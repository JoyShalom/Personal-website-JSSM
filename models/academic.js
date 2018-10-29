var mongoose = require('mongoose')

var academicPageSchema = new mongoose.Schema({
  courseName: String,
  projectsDone: []
})

module.exports = mongoose.model('academic', academicPageSchema)
