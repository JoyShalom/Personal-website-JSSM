#ifndef PUBLISHER_H
#define PUBLISHER_H
//////////////////////////////////////////////////////////////////////////////
// Publisher.h- To publish all code dependencies using HMTL                 //
// Version     : 1.0                                                        //
// Language    : Visual C++, Visual Studio 2015                             //
// Platform    : Dell Inspiron 15 7000Series, Core-i5,                      //
//               Windows 10                                                 //
// Application : Code Publisher                                             //
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
// This module will analyze files in a given path by generating a dependency Table and then
// publish the dependency along with the code using HTML.

// Public Interface:
// -----------------
// std::vector<std::string> patterns = { "*.cpp", "*.h" };    // Patterns is the variable used to describe what type of files have to be retrived from the folder
// std::set<std::string> finished;                            // Finished is the variable used to find the count of files
// std::ofstream IndexFile;                                   // IndexFile is the variable which is used to copy files to the index.html page
// Methods :-
//----------
// void convertToHTML(std::string filePath);                 // Function which is used to convert the dependent files to .htm hyperlinks
// void findFilesConvertHTML(std::string dirPath);           // Function which is used to find the files dependent over in the given directory
// void HTMLDesign();                                        // Function which is used to apply the HTML tags, use CSS stylesheet and Java script
// void toDemonstrateWithinHTML();                           // Function which is used to add demonstration in the index.htm page
//
//
// Required files:
// ---------------
// Publisher.cpp,FileSystem.h, FileSystem.cpp,DepAnal.h,DepAnal.cpp,style.css,Script.js
//
// Build command:
// --------------
// devenv Publisher.sln /rebuild debug
//
// Maintenance History:
// --------------------
// ver 1.0 : 2 Apr 17
// - first release
//


#include <string>
#include "../File_System/FileSystem.h"
#include "../DepAnal/DepAnal.h"

// Publisher class
class Publisher{
public:
	std::ofstream IndexFile;
	std::vector<std::string> patterns = { "*.cpp", "*.h" };      //Patterns which are checked in the file location
	std::set<std::string> finished;
	void convertToHTML(std::string filePath);
	void findFilesConvertHTML(std::string dirPath);
	void HTMLDesign(std::ofstream& myfile);
	void toDemonstrateWithinHTML();
	
};
#endif
