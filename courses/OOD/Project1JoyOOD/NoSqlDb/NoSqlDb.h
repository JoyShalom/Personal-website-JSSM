#pragma once
//#ifndef NoSqlDb_H
#define NoSqlDb_H
//////////////////////////////////////////////////////////////////////
// NoSqlDb.h	    :	No SQL Database created which handles the   //
//                      functionality of storing the information and//
//                      retrieving the data using different search  //
//                      methods.                                    //
// Version			:	1.0											//
// -----------------------------------------------------------------//
// Credits                                                          //
// and source       :   Dr.Jim Fawcett, Syracuse University         //
//                      jfawcett@twcny.rr.com                       //
// -----------------------------------------------------------------//
// Application      :   No SQL Database,CSE687-Object Oriented Design
// -----------------------------------------------------------------//
// Language			:	C++, Visual Studio 2015					    //
//                                                                  //
// Platform			:	Dell Inspiron 15 7000Series, Core-i5,       //
//                      Windows 10			                        //     										
// -----------------------------------------------------------------//
// Author			:	Joy Shalom Soosai Michael       			//
//						jsoosaim@syr.edu,SUID : 699737418     		//
//////////////////////////////////////////////////////////////////////

/*
* Credits:
* --------
* I would like to give credits to Prof. Jim W Fawcett, Syracuse University
* for providing a started code and explaining how the No SQL Datsbase should work.
*
* PACKAGE OPERATIONS
* ------------------
* This package contains a  template named 'Info and two classes namely 'Database' and 'NoSqlDb'.
* The Class Database holds the data record in the NoSql database using the property functionality.
* The Class NoSqlDb is a key/value pair in-memory database which stores and retrieves elements.

* DEPENDANT FILES
* ---------------
* NoSqlDb.h, NoSqlDb.cpp, CppProperties.h, CppProperties.cpp,
* Convert.h, Convert.cpp, XmlDocument.h, XmlDocument.cpp
* 
* BUILD PROCESS
* -------------
* devenv Project1Joy.sln/rebuild debug
*
* MAINTENANCE INFORMATION
* -----------------------
* Ver 1.0 : 02/07/2017
*	- Initial Release
*   - Build on top of Prof. Jim fawcett's 24 Jan 2017 code.
*
* QUERY MECHANISM
* ---------------
* Created a vector combining classes Database and Nosqldb for the function. 
* Created an instance- Eg:results for the vector of Database<Info>.
* Using pair functionality, created a pair of key and database<Info>.
* Converted string:string using property for the input given while calling the function.
* Compare the passed input with the database and pushed the results back to the vector created.
*/
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iostream>
#include "../CppProperties/CppProperties.h";

// Database class represents a data record in our NoSql database
// In NoSql database that acts as a value in a key/value pair

template<typename Info>
class Database
{
private:
	using Name = std::string;

public:
	// Define the metadata
	using Category = std::string;
	using TimeDate = std::string;
	using TextDesc = std::string;
	using StringData = std::string;
	using Child = std::vector<StringData>;

	Property<Name> name;					// metadata
	Property<Category> category;			// metadata
	Property<TextDesc> text_desc;			// metadata
	Property<TimeDate> timedate;			// metadata
	Property<Child> child;                  // metadata
	Property<Info> Info_Save;	            // data

	std::string show();
};

template<typename Info>
std::string Database<Info>::show()
{
	std::ostringstream out;
	out.setf(std::ios::adjustfield, std::ios::left);
	out << "\n    " << std::setw(8) << "name" << " : " << name;
	out << "\n    " << std::setw(8) << "category" << " : " << category;
	out << "\n    " << std::setw(8) << "Text Description" << " : " << text_desc;
	out << "\n    " << std::setw(8) << "timeDate" << " : " << timedate;
	for (int i = 0; i < child.getValue().size(); i++)
		out << "\n    " << std::setw(8) << "children : " << child.getValue()[i];
	out << "\n    " << std::setw(8) << "Information Saved : " << Info_Save;
	out << "\n";
	return out.str();
}

template<typename Info>
class NoSqlDb
{
public:
	// Define the <key,keys> of the database using the vector
	using Key = std::string;
	using Keys = std::vector<Key>;

	// Function Definition for the operations which is to be demonstrated
	Keys keys();
	bool save(Key key, Database<Info> elem);
	Database<Info> value(Key key);
	Database<Info> removekey(Key key);
	std::vector<Database<Info>> FindByName(Key _name);
	std::vector<Database<Info>> FindByCategory(Key _cat);
	std::vector<Database<Info>> FindByDesc(Key _desc);
	Database<Info> EditValue(Key key, Database<Info>);
	size_t count();
private:
	using Item = std::pair<Key, Database<Info>>;

	//Unordered map is used to store the key and the values associated with it
	std::unordered_map<Key, Database<Info>> store;
};

// Function to store the items using push back operation
template<typename Info>
typename NoSqlDb<Info>::Keys NoSqlDb<Info>::keys()
{
	Keys keys;
	for (Item item : store)
	{
		keys.push_back(item.first);
	}
	return keys;
}

//Function to save the key and the elements associated with it
template<typename Info>
bool NoSqlDb<Info>::save(Key key, Database<Info> elem)
{
	if (store.find(key) != store.end())
		return false;
	store[key] = elem;
	return true;
}

//Function to find and retrieve the elements using the key
template<typename Info>
Database<Info> NoSqlDb<Info>::value(Key key)
{
	if (store.find(key) != store.end())
		return store[key];
	return Database<Info>();

}

//Function for the deletion of key/value pairs
template<typename Info>
Database<Info> NoSqlDb<Info>::removekey(Key key)
{
	if (store.find(key) != store.end())
		store.erase(key);
	return Database<Info>();

}

//Key deletePC = delete_key;
//test1.parent_child_rel(deletion_key);

//Edit
template<typename Info>
Database<Info> NoSqlDb<Info>::EditValue(Key key, Database<Info> elem)
{
	store[key] = elem;
	return Database<Info>();
}
	
//Query to retrieve the value and children of a specified key using the key name
template<typename Info>
std::vector<Database<Info>> NoSqlDb<Info>::FindByName(Key _name)
{
	std::vector<Database<Info>> vec;
	for (Item pr : store) {
		if (Convert<Property<std::string>>::toString(pr.second.name) == _name) {
			vec.push_back(pr.second);
		}
	}
	return vec;
}

//Query to retrieve the keys which contain a specified string in their category name
template<typename Info>
std::vector<Database<Info>> NoSqlDb<Info>::FindByCategory(Key _cat)
{
	std::vector<Database<Info>> vec;
	for (Item pr : store) {
		if (Convert<Property<std::string>>::toString(pr.second.category) == _cat) {
			vec.push_back(pr.second);
		}
	}
	return vec;
}

//Query to retrieve the keys which contain a specified string in their text description
template<typename Info>
std::vector<Database<Info>> NoSqlDb<Info>::FindByDesc(Key _desc)
{
	std::vector<Database<Info>> vec;
	for (Item pr : store) {
		if (Convert<Property<std::string>>::toString(pr.second.text_desc) == _desc) {
			vec.push_back(pr.second);
		}
	}
	return vec;
}


//Function to count the size of the NoSqlDb.
template<typename Info>
size_t NoSqlDb<Info>::count()
{
	return store.size();
   
}

//template<typename Info>


/////////////////////////////////////////////////////////////////////
// Persistance class
// - you will need to implement that using the XmlDocument class
//   from Handouts/Repository

/* class X
{
public:
	Property<std::string> name;
	Property<double> pi;
}; */

