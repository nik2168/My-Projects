const mongoose = require('mongoose')


const user = mongoose.Schema({

    name : {
        type : String,
        require : [true, "please provide name"]
    },

    userid : {
        type : Number,
        require : true,
        unique: true
    },

    email : {
        type : String,
        require : true,
        minLength : 10,
        lowercase : true
    },

    password : {
        type : String,
        require : true,
    },

    usertype : {
        type : String,
        default : "customer",
        enum : ["admin", "customer"]
    }

}, {timestamps : true, versionKey : false})

 const User = mongoose.model("user", user)

 module.exports = User