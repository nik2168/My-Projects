const Catogory = require('../models/catagories.model.js')
const jwt = require('jsonwebtoken')
const User = require('../models/user.model.js')
const secretwords = require('../configs/auth.configs.js')

const createcatagory = async (req, res) => {
    // create new catagory
    try{
      const newCat = await Catogory.create(req.body)
      return  res.status(200).send(`${req.body.name} created successfully !`) 
     
    }catch(err){
       return  res.status(400).send("Error while fetching the Catagory !")
    }
}

module.exports = {
    createcatagory
}