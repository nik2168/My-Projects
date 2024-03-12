const Catagory = require('../models/catagories.model.js')
const jwt = require('jsonwebtoken')
const mySecret = require('../configs/auth.configs.js')
const User = require('../models/user.model.js')


const catParamsCheck = async(req, res, next) => {
    if(!req.body.name) return res.status(400).send("Please provide the name of the catagory")
    if(!req.body.description) return res.status(400).send("Please provide the description of the catagory")
    try{
      const catCheck = await Catagory.findOne({name : req.body.name})
      if(catCheck){
       return res.status(400).send("This catagory is already present")
      }
    }catch(err){
       return res.status(400).send("Error while fetching the catagory")
    }
    next()
}

const userTokenVerify = async (req, res, next) => {
       const token = req.headers.token
       
       // check if token is present or not ?
       if(!token) return res.status(404).send("Please login for authorisation & token")

       // check if token is valid or not ?
       try{
       jwt.verify(token, mySecret.secret, (err, decoded) => {
        if(err) return res.status(400).send(`Error while verifying token `)
        else{
         req.userId = decoded.userid
         console.log(req.userId)
      }
      next()
       })
       
       }catch(err){
            return res.status(400).send("Error while verifying the user token !")
    }
}

const tokenUserVerify = async (req, res, next) => {
        
      // check if the userid in token is a valid id or not
      try{
      const user = await User.findOne({userid : req.userId})
      if(!user) return res.status(400).send("You are not authorised user won't match to our db")
      if(user.usertype != "admin") return res.status(400).send("Customers are not authorised to create a catagory")
      next()
      }catch(err){
          return res.status(400).send("Error while matching the token user to db")
      }  
}


module.exports = {
        catParamsCheck,
        userTokenVerify,
        tokenUserVerify
}