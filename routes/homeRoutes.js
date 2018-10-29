var express = require('express')
var router = express.Router()
var mongoose = require('mongoose')
var home = require('../models/Home.js')

/* Display the home Page */
router.get('/', function (req, res, next) {
  home.find(function (err, details) {
    if (err) return next(err)
    res.json(details)
  })
})

/* To find by ID */
router.get('/:id', function (req, res, next) {
  home.findById(req.params.id, function (err, details) {
    if (err) return next(err)
    res.json(details)
  })
})

/* Post data */
router.post('/', function (req, res, next) {
  home.create(req.body, function (err, post) {
    if (err) return next(err)
    res.json(post)
  })
})

/* Delete data */
router.delete('/:id', function (req, res, next) {
  home.findByIdAndRemove(req.params.id, req.body, function (err, post) {
    if (err) return next(err)
    res.json(post)
  })
})

module.exports = router
