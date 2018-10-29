var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var bodyParser = require('body-parser');
var router = express.Router();
var home = require('./routes/homeRoutes');
var academic = require('./routes/academicRoutes');
var serveIndex = require('serve-index');

var mongoose = require('mongoose');
mongoose.Promise = require('bluebird');
mongoose.connect('mongodb://localhost/mean-angular5', { useNewUrlParser: true, promiseLibrary: require('bluebird') })
  .then(() =>  console.log('connection succesful'))
  .catch((err) => console.error(err));
var app = express();

var fs = require('fs');
var path = require('path');
var directoryPath = path.join(__dirname, 'courses','OOD','Project1Joy');

app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({'extended':'false'}));
app.use(express.static(path.join(__dirname, 'dist')));
app.use('/homes', express.static(path.join(__dirname, 'dist')));
app.use('/home', home);
app.use('/academic',academic);

//OOD Projects
app.use('/pro1OOD', serveIndex(path.join(__dirname, 'courses','OOD','Project1JoyOOD')));
app.use('/pro1OOD', express.static(path.join(__dirname, 'courses','OOD','Project1JoyOOD')));
app.use('/pro2OOD', serveIndex(path.join(__dirname, 'courses','OOD','Project2JoyOOD')));
app.use('/pro2OOD', express.static(path.join(__dirname, 'courses','OOD','Project2JoyOOD')));
app.use('/pro3OOD', serveIndex(path.join(__dirname, 'courses','OOD','Project3JoyOOD')));
app.use('/pro3OOD', express.static(path.join(__dirname, 'courses','OOD','Project3JoyOOD')));
app.use('/pro4OOD', serveIndex(path.join(__dirname, 'courses','OOD','Project4JoyOOD')));
app.use('/pro4OOD', express.static(path.join(__dirname, 'courses','OOD','Project4JoyOOD')));

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
 // res.send();
});

/*app.use('/oodpro1', function(request,response) {
  fs.readdir(directoryPath, function (err, files) {
  var filesSearched   = [];
    //handling error
    if (err) {
        return console.log('Unable to scan directory: ' + err);
    } 
    //listing all files using forEach
    files.forEach(function (file) {
        // Do whatever you want to do with the file
        filesSearched.push(file);
        console.log(file); 
    });
})
});*/

module.exports = app;