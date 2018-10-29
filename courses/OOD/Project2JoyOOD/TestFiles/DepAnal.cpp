//////////////////////////////////////////////////////////////////////////////
// DepAnal.cpp   - Helper Package to find the dependent files and its path  //
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

#include <iomanip>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <set>
#include "DepAnal.h"
using namespace std;

// Function which is used to retrive just the file name from the #include statements
std::string DepAnal::getFileName(std::string filePath) {
	int beginIdx = filePath.rfind('/');
	if (beginIdx == string::npos)
		return filePath;

	int endIdx = int(filePath.length()) - 1;
	std::string filename = filePath.substr(beginIdx + 1, endIdx - (beginIdx));

	return filename;
}

// Function which is used to retrive the file path from the #include statements
std::string DepAnal::getFilePath(std::string filePath) {
	int beginIdx = filePath.find(' ');
	int endIdx = int(filePath.length()) - 1;
	std::string filename = filePath.substr(beginIdx + 2, endIdx - (beginIdx + 2));

	return filename;
}

/*Test Stub*/
#ifdef TEST_DEPANAL_H
void main()
{

	std::cout << "To test dependency";
	DepAnal dp;
	dp.getFileName("../File_System/");
	dp.getFilePath("../File_System/");
}
#endif