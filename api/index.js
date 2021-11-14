const mongoose = require('mongoose')
const express = require("express")
const http = require('http')
var assert = require('assert')

const hostname = '127.0.0.1'
const port = 3000

const schema = mongoose.Schema({
    username: String,
    password: String,
})

const router = express.Router()

var model = mongoose.model("users", schema)

async function connect(){
    try {
        await mongoose.connect('mongodb://localhost:27017/katalonTest',
            {useNewUrlParser: true, useUnifiedTopology: true})
        var json = await model.find({})
        return json
    } catch(error) {
        console.log(error)
        return ""
    }
}

const server = http.createServer((req, res) => {

    if (req.method == 'POST') {
        let rei = '';
        req.on('data', chunk => {
            rei += chunk;
        })
        
        req.on('end', () => {
            console.log(rei)
            var newdata = new model(JSON.parse(rei))
            newdata.save(function(err){
                if (err) {
                    throw err
                }
                console.log('INSERTED!')
            })

            connect().then( function(data) {
                res.statusCode = 200;
                res.setHeader('Content-Type', 'application/json')
                res.end(JSON.stringify(data))
            })
        })

    } else {
        connect().then(function(data) {
            res.statusCode = 200;
            res.setHeader('Content-Type', 'application/json')
            res.end(JSON.stringify(data))
        })
    }
})

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
})