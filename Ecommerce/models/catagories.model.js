const { default: mongoose } = require("mongoose");

const catagorymodel = mongoose.Schema({
    name : {
        type : String,
        unique : true,
        require : true
    },

    description : {
        type : String,
        require : true
    }

}, {timestamps : true}, {versionkey : false})

const Catagory = mongoose.model("catagory", catagorymodel)

module.exports = Catagory