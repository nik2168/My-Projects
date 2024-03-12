const express = require('express')
const router = express.Router()



// imported controllers
   
 // for user
const {
    singnup,
    showallusers,
    userauth
} = require('../controllers/user.controllers')

// for catagories
const {
    createcatagory
} = require('../controllers/catagory.controllers.js')




// middlewares import

// for user
const {
    verifyreqbody, // to check if user have provided the req.body 
    authmw
} = require('../middleware/user.mw.js')

// for catagories 
const {
    catParamsCheck,
    userTokenVerify,
    tokenUserVerify
} = require('../middleware/catagory.mw.js')



router.get('/user', showallusers)
router.post('/user/singnup', verifyreqbody, singnup)
router.post('/user/signin', authmw, userauth)
router.post('/catagory/create', [userTokenVerify, tokenUserVerify, catParamsCheck], createcatagory)

module.exports = router

