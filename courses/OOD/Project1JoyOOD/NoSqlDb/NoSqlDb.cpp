//////////////////////////////////////////////////////////////////////
// NoSqlDb.cpp	    :	Provides Interface to store the             //
//                      key values for a No SQL database            //
//                      and necessary functions to                  //
//                      perform operations like Insert,Delete,Edit  //
//						and Query functionalities                   //
// Version			:	1.0											//
// -----------------------------------------------------------------//
// Credits                                                          //
// and source       :   Dr.Jim Fawcett, Syracuse University         //
//                      jfawcett@twcny.rr.com                       //
// -----------------------------------------------------------------//
// Application      :   No SQL Database,CSE687-Object Oriented Design
// -----------------------------------------------------------------//
// Language			:	C++, Visual Studio 2015	                    //
//                                                                  //
// Platform			:	Dell Inspiron 15 7000Series, Core-i5,       //
//                      Windows 10			                        //
// -----------------------------------------------------------------//
// Author			:	Joy Shalom Soosai Michael       			//
//						jsoosaim@syr.edu,SUID : 699737418     		//
//////////////////////////////////////////////////////////////////////


//Header Functions needed for the package
#include <iostream>
#include<string>
#include "../XmlDocument/XmlDocument.h"
#include "../XmlElement/XmlElement.h"
#include "../Convert/Convert.h"
#include "../CppProperties/CppProperties.h"
#include "../NoSqlDb/StrHelper.h"
#include "NoSqlDb.h"
//#include "../Project1Joy/ConsoleApplication2/TestExec.h"
#include<vector>
#include<istream>
#include<algorithm>
#include<iterator>
#include<stdlib.h>

using namespace std;
using StringData = std::string;
using integer = int;
using Key = NoSqlDb<StringData>::Key;
using Keys = NoSqlDb<StringData>::Keys;
using myvector = std::vector<StringData>;

//Utilities::Utilities() {}
//Utilities::~Utilities() {}

using namespace std;
using StringData = std::string;
using integer = int;
using Key = NoSqlDb<StringData>::Key;
using Keys = NoSqlDb<StringData>::Keys;
using myvector = std::vector<StringData>;
NoSqlDb<StringData> db;
myvector m1, m2, m3, m4;
Keys keys = db.keys();

void SaveAndAddElements()
{
	//first element to be stored:
	std::cout << "\n" << "First Element \n";
	Database<StringData> cus1;
	cus1.name = "1";
	cus1.category = "Category1";
	cus1.text_desc = "Best for years";
	cus1.timedate = "01/10/1992";
	cus1.child = { "1" };
	cus1.Info_Save = "International Person";

	//To save the details to the database
	db.save(cus1.name, cus1);

	//To push the element 1's children to the database
	std::cout << "children of element 1";
	if (!cus1.child.getValue().empty()) {
		for (int i = 0; i < cus1.child.getValue().size(); i++)
		{
			m1.push_back(cus1.child.getValue()[i]);

		}

		for (auto j : m1)
			std::cout << "\n" << "m1 :" << j << "\n";

		for (auto i : m1)
		{

			std::cout << "\n  " << i << ":";
			std::cout << db.value(i).show();

		}

		std::cout << "\n\n";
	}


	//Second element to be stored:
	std::cout << "\n" << "Second Element  \n";
	Database<StringData> cus2;
	cus2.name = "2";
	cus2.category = "Category3";
	cus2.text_desc = "Best for years";
	cus2.timedate = "09/01/2001";
	cus2.child = { "2" };
	cus2.Info_Save = "Resident person";

	//To save the details to the database
	db.save(cus2.name, cus2);

	//To push the element 2's children to the database
	std::cout << "children of element 2";
	if (!cus2.child.getValue().empty()) {
		for (int i = 0; i < cus2.child.getValue().size(); i++)
		{
			m2.push_back(cus2.child.getValue()[i]);

		}

		for (auto j : m2)
			std::cout << "\n" << "m2 :" << j << "\n";

		for (auto i : m2)
		{

			std::cout << "\n  " << i << ":";
			std::cout << db.value(i).show();

		}

		std::cout << "\n\n";
	}


	//Third element to be stored:
	std::cout << "Third element   \n";
	Database<StringData> cus3;
	cus3.name = "3";
	cus3.category = "Category3";
	cus3.text_desc = "Best for months";
	cus3.timedate = "01/01/1991";
	cus3.child = { "3" };
	cus3.Info_Save = "Green card holder";

	//To save the details to the database
	db.save(cus3.name, cus3);

	//To push the element 3's children to the database
	std::cout << "children of element 3";
	if (!cus3.child.getValue().empty()) {
		for (int i = 0; i < cus3.child.getValue().size(); i++)
		{
			m3.push_back(cus3.child.getValue()[i]);

		}

		for (auto j : m3)
			std::cout << "\n" << "m3 :" << j << "\n";

		for (auto i : m3)
		{

			std::cout << "\n  " << i << ":";
			std::cout << db.value(i).show();

		}

		std::cout << "\n\n";
	}

	//Fourth element to be stored:
	std::cout << "Fourth element\n";
	Database<StringData> cus4;
	cus4.name = "4";
	cus4.category = "Category4";
	cus4.text_desc = "Best for years";
	cus4.timedate = "01/01/1920";
	cus4.child = { "4" };
	cus4.Info_Save = "Green card holder";

	//To save the details to the database
	db.save(cus4.name, cus4);

	////To push the element 4's children to the database
	std::cout << "children of element 4";
	if (!cus4.child.getValue().empty()) {
		for (int i = 0; i < cus4.child.getValue().size(); i++)
		{
			m4.push_back(cus4.child.getValue()[i]);

		}

		for (auto j : m4)
			std::cout << "\n" << "m4 :" << j << "\n";

		for (auto i : m4)
		{

			std::cout << "\n  " << i << ":";
			std::cout << db.value(i).show();

		}

		std::cout << "\n\n";
	}
}

//Delete key-value of pair 1
void Delete()
{
	std::cout << "\n" << "Delete the key value pair 1";
	Key k1 = { "1" };
	db.removekey(k1);
	Keys keys = db.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
}

void edit()
{
	std::cout << "Edit the Key";
	Database<StringData> it1 = { " 1" };
	//Key it1 = { "2" };
	it1.category = "Yes Changed";
	it1.text_desc = "new desc";
	//it1.name = "2";
	it1.timedate = "01-01-2011";
	it1.Info_Save = "New Data";
	db.save(it1.name, it1);
	Keys keys = db.keys();
	for (Key key : keys)
	{
		std::cout << "\n  " << key << ":";
		std::cout << db.value(key).show();
	}
}
void SearchByName()
{
	std::cout << "\n" << "To perform search using name";
	Database<StringData> search1;
	search1.name = "2";
	db.FindByName("search1");
	cout << "\n" << "The searched value for the name '2':";
	std::cout << "\n  " << search1.name << ":";
	std::cout << db.value(search1.name).show();
}

void SearchByCategory()
{
	std::cout << "\n" << "To perform search using category name";
	std::cout << "\n" << "The searched value for the category 'Category3':";
	std::vector<Database<StringData>> results = db.FindByCategory("Category3");
	for (Database<StringData> value : results)
	{
		std::cout << "\n" << value.show();
	}
}

void SearchByDescription()
{
	std::cout << "\n" << "To perform search using text description";
	std::cout << "\n" << "The searched value for the description 'Best for years':";
	std::vector<Database<StringData>> res = db.FindByDesc("Best for years");
	for (Database<StringData> value : res)
	{
		std::cout << "\n" << value.show();
	}
}


int main()
{

	myvector m1, m2, m3, m4;

	std::cout << "\n  NoSQL Database :";
	std::cout << "\n =================================\n";

	std::cout << "\n  Creating and saving NoSqlDb elements with string data";
	std::cout << "\n -------------------------------------------------------\n";
	SaveAndAddElements();
	Delete();
	edit();
	SearchByName();
	SearchByCategory();
	SearchByDescription();
	std::cin.get();

}
