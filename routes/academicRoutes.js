var express = require('express')
var router = express.Router()
var mongoose = require('mongoose')
var academic = require('../models/academic.js')

/* Display the home Page */
router.get('/', function (req, res, next) {
  academic.find(function (err, details) {
    if (err) return next(err)
    res.json(details)
  })
})

/* To find by ID */
router.get('/:id', function (req, res, next) {
  academic.findById(req.params.id, function (err, details) {
    if (err) return next(err)
    res.json(details)
  })
})

/* Post data */
router.post('/', function (req, res, next) {
  academic.create(req.body, function (err, post) {
    if (err) return next(err)
    res.json(post)
  })
})

/* Delete data */
router.delete('/:id', function (req, res, next) {
  academic.findByIdAndRemove(req.params.id, req.body, function (err, post) {
    if (err) return next(err)
    res.json(post)
  })
})

module.exports = router
