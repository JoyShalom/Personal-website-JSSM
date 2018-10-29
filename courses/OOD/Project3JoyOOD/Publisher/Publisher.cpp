//////////////////////////////////////////////////////////////////////////////
// Publisher.cpp- To publish all code dependencies using HMTL               //
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

#include <iomanip>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <set>
#include "Publisher.h"

using namespace std;
string mainFile;
DepAnal dp;
string line;

//Function which is used to find the files dependent over in the given directory//

void Publisher::findFilesConvertHTML(string dirPath) {
	string fpath = FileSystem::Path::getFullFileSpec(dirPath);
	for (auto patt : patterns) {
		vector<string> files = FileSystem::Directory::getFiles(fpath, patt);
		for (auto f : files) {
			convertToHTML(dirPath + "/" + f);
		}}}

// Function which is used to convert the dependent files to .htm hyperlinks//

void Publisher::convertToHTML(string filePath) {
	ifstream fileSearch; ofstream myfile; 
	int n = 0, f_pos = 0;
	char* search = "#include";
	fileSearch.open(filePath);
	if (fileSearch.is_open()) {
		mainFile = dp.getFileName(filePath);
		if (finished.count(mainFile) != 0)	return;
		finished.insert(mainFile);
		myfile.open(mainFile + ".htm");
		HTMLDesign(myfile);
		while (getline(fileSearch, line)) {
			if (line.find(search) == 0 && line.find("\"") != string::npos) {
				cout << "\nThe extraction of #include statements::\n\n";
				cout << line << endl;
				string filename = dp.getFileName(dp.getFilePath(line));
				myfile << "<a href='" << filename + ".htm" << "'>" << filename + ".htm" << "</a><br /></head><body>";
				cout << "\n\nThe extraction of file path of each #include files::\n\n";
				cout << filename << endl;
				if (finished.count(filename) == 0) {

					//Add files to index.htm file//
					IndexFile << "<a href='" << filename + ".htm" << "'>" << filename + ".htm" << "</a><br />";
					IndexFile << "<a href='" << mainFile + ".htm" << "'>" << mainFile + ".htm" << "</a><br />";
					convertToHTML(dp.getFilePath(line));  }	}  }
		fileSearch.clear();
		fileSearch.seekg(0, ios::beg);
		myfile << "<pre>";
		while (getline(fileSearch, line)) {
			f_pos = 0;
			while ((f_pos = line.find("<")) != string::npos) {
				line.replace(f_pos, 1, "&lt");
				f_pos += 3; }
			while ((f_pos = line.find(">")) != string::npos) {
				line.replace(f_pos, 1, "&gt");
				f_pos += 3; }

			//To include the concept of collapsing and expanding the code within .htm files//
			if (line.find("{") != string::npos && line.find("find") == string::npos && line.find("}") == string::npos) {
				n++;
				line.replace(line.find("{"), 1, "<pre id='a2" + to_string(n) + "' onclick=\"toggle_visibility('a1" + to_string(n) + "', 'a2" + to_string(n) + "');\">[-]</pre> { <pre id='a1" + to_string(n) + "'>");
			}
			if (line.find("}") != string::npos && line.find("find") == string::npos && line.find("{") == string::npos)
				line.replace(line.find("}"), 1, "</pre> }<br /><br />");
			myfile << line << '\n'; }
		myfile << "</pre>" << "</body></html>"; myfile.close(); } }


//Function which is used to apply the HTML tags, use CSS stylesheet and Java script//
void Publisher::HTMLDesign(ofstream& myfile)
{
	myfile << "<!DOCTYPE html><html><head>";
	myfile << "<link href = \"Style.css\" rel=\"stylesheet\" type =\"text/css\">" << "<script src=\"Script.js\" type=\"text/javascript\"></script>";
	myfile << "<h1>" << mainFile << "</h1>";
	myfile << "<h4>!----------------------------------------------------------------------------</h4>";
	myfile << mainFile << "<h4>--Code Publisher</h4>";
	myfile << "<h4>Published 02 Apr 2017</h4>";
	myfile << "<h4>Author: Joy Shalom Soosai Michael, CSE687 - Object Oriented Design, Spring 2017</h4>";
	myfile << "<h4>Credits and source: Prof.Jim Fawcett</h4>";
	myfile << "<h4>-----------------------------------------------------------------------------></h4>";
	myfile << "<h4>Dependencies:</h4>";
}

// Function which is used to add demonstration in the index.htm page//
void Publisher::toDemonstrateWithinHTML() {
	IndexFile << "<h4> Demonstating Requirement 1: </h4>";
	IndexFile << "<h4> This Project is done in visual Studio 2015 and its C++ Windows Console Projects, as provided in the ECS computer labs </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 2: </h4>";
	IndexFile << "<h4> This Project uses C++ standard library's streams for all I/O and new and delete for all heap-based memory management </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 3: </h4>";
	IndexFile << "<h4> Publisher program creates web pages each of which captures the content of a single C++ source code file </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 4: </h4>";
	IndexFile << "<h4> Facility to expand or collapse class bodies, methods, and global functions using JavaScript and CSS properties </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 5: </h4>";
	IndexFile << "<h4> CSS style sheet that the Publisher uses to style its generated pages </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 6: </h4>";
	IndexFile << "<h4> Embed in each web page's <head> section links to the style sheet and JavaScript file </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 7: </h4>";
	IndexFile << "<h4> Embedd HTML5 links to dependent files with a label, at the top of the web page </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 8: </h4>";
	IndexFile << "<h4> Command line processing to define the files to publish by specifying path and file patterns </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 9: </h4>";
	IndexFile << "<h4> Command line processing to define the files to publish by specifying path and file patterns </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
	IndexFile << "<h4> Demonstating Requirement 10: </h4>";
	IndexFile << "<h4> An automated unit test suite that demonstrates you meet all the requirements </h4>";
	IndexFile << "<h4> Requirement Implemented </h4>";
}


/* Test Stub */
#ifdef TEST_PUBLISHER
void main()
{
	Publisher da;
	string dirPath = "../";
	vector<string> dirs;
	std::queue<string> dirQue;
	dirQue.push(dirPath);
	da.findFilesConvertHTML(dirPath);

	while (dirQue.empty() == false) {
		string tempDir = dirQue.front();
		dirQue.pop();

		dirs = FileSystem::Directory::getDirectories(tempDir);
		for (auto d : dirs) {
			if (d == "." || d == "..")
				continue;
			string dpath = tempDir + "/" + d;
			dirQue.push(dpath);
			da.findFilesConvertHTML(dpath);
		}
	}

	return;
}
#endif // TEST_PUBLISHER