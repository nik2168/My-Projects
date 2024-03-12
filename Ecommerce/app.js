const express = require('express')
const app = express()


let port = 8080
const mongoose = require('mongoose')
const User = require('./models/user.model.js')
const dbconfigs = require('./configs/db.configs.js')
const bcrypt = require('bcryptjs')
const userroutes = require('./routes/user.routes.js')

app.use(express.json())
app.use(express.urlencoded({extended : true}))

mongoose.connect(dbconfigs.url)
.then(() => {
 console.log("Connected to database successfully !")

 app.listen(port, () => {
    console.log(`Server is running at port : ${port}`)
})
 init()
})
.catch((err) => {
 console.log("Error while connected to db", err)
})

async function init() {
    
    try{
    const person =  await User.findOne({usertype : "admin"})
   if(person){
    console.log("Admin already Present")
    return
   }
}catch(err){
    console.log("err while fetching the admin : ", err)
}
   try{
   const newUser = await User.create({
    name : "Nik",
    userid : 1,
    email : "nikhil123@gmail.com",
    password : bcrypt.hashSync("nikhil123", 8),
    usertype : "admin"
   })
   console.log("Admin created successfully", newUser) 
}catch(err){
    console.log("Error while creating the user : ", err)
}
}

// for all type of request handling --- in one line isn't it crazy ? who knows we have routes & controllers ?
app.use('/ecom/api/v1', userroutes)





