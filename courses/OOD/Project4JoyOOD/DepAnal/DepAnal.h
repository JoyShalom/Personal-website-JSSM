#ifndef DEPANAL_H
#define DEPANAL_H
//////////////////////////////////////////////////////////////////////////////
// DepAnal.h   - Helper Package to find the dependent files and its path    //
// Version     : 1.0                                                        //
// Language    : Visual C++, Visual Studio 2015                             //
// Platform    : Dell Inspiron 15 7000Series, Core-i5,                      //
//               Windows 10                                                 //
// Application : Remote Code Publisher                                      //
// Author      : Joy Shalom Soosai Michael                                  //
//               jsoosaim@syr.edu,SUID : 699737418                          //
// Credits                                                                  //
// and source  : Dr.Jim Fawcett, Syracuse University                        //
//                      jfawcett@twcny.rr.com                               //
//////////////////////////////////////////////////////////////////////////////

// Credits
// --------
// I would like to give credits to Prof. Jim W Fawcett, Syracuse University
// for explaining how the code Publisher should work.

// Module Operations:
// ------------------
// This module will help in finding out the dependent files and its relative path

// Public Interface:
// -----------------
// Methods :-
//----------
// std::string getFilePath(std::string filePath);            // Function which is used to retrive the file path from the #include statements
// std::string getFileName(std::string filePath);            // Function which is used to retrive just the file name from the #include statements
//
// Required files:
// ---------------
// DepAnal.cpp
//
// Build command:
// --------------
// devenv DepAnal.sln /rebuild debug
//
// Maintenance History:
// --------------------
// ver 1.0 : 2 Apr 17
// - first release
//


#include <string>

//DepAnal Class
class DepAnal {
public:
	std::string getFilePath(std::string filePath);    
	std::string getFileName(std::string filePath);
};
#endif
