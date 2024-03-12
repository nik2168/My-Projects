const mongoose = require('mongoose')
const User = require('../models/user.model')
const bcrypt = require('bcryptjs')
const jwt = require('jsonwebtoken')
const sec = require('../configs/auth.configs.js')

const singnup = async (req, res) => {
    try{
        req.body.password = bcrypt.hashSync(req.body.password, 8)
        const product = await User.create(req.body)
        res.status(201).json(product)
       }catch(err){
           res.status(500).json({Error : err.message})
       }   
}

const showallusers = async (req, res) => {
    try{
     const person = await User.find()
     res.status(200).send(person)
    }catch(err){
        res.status(400).json({Error : err.message})
    }
}

const userauth = async (req, res) => {

    // check if user is present or not ?
    const user = await User.findOne({userid : req.body.userid})
    if(!user) {
        res.status(400).send("User not found")
        return
    }

    // check if password is correct
    const passwordcheck = bcrypt.compareSync(req.body.password, user.password)
    if(!passwordcheck){
        res.status(400).send("Incorrect Password !")
        return
    }
    
    // if everything is all right then generate jwt token 
    const token = jwt.sign({userid : user.userid}, sec.secret, {expiresIn : 1200})
    res.status(200).json({
        name : user.name,
        userid : user.userid,
        email : user.email,
        usertype : user.usertype,
        accesstoken : token
    })
}

module.exports = {
    singnup,
    showallusers,
    userauth
}
