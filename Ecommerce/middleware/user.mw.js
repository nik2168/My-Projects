const User = require('../models/user.model.js')


const verifyreqbody = async (req, res, next) => {
    try{
    if(!req.body.name) return res.status(400).send("Please provide the name")
    if(!req.body.password) return res.status(400).send("Please provide the password")
    if(!req.body.email) return res.status(400).send("Please provide the email")
    if(!req.body.userid) return res.status(400).send("Please provide the userid")
     const finduser = await User.findOne({userid : req.body.userid})
    if(finduser) return res.status(400).send("User with this userid is already present")
    next()
    }catch(err){
    return res.status(404).send(`Error while fetching the req body ${err}`)
}
}

const authmw = async (req, res, next) => {
    if(!req.body.password) return res.status(400).send("Please provide the password")
    if(!req.body.userid) return res.status(400).send("Please provide the userid")
    next()
}

module.exports = {
    verifyreqbody,
    authmw
}