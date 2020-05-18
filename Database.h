/*
* Database.h
*
* Description: Models the attributes of a Book (title, author, dateOfPublication, etc)
* Class Invariant: The attributes of a Book are a valid string (it is not an empty string)
*                  and it starts with a letter (a or A to z or Z).
*                  The name of an author uniquely identifies him/her.
*
* Created on: May 16, 2020
* Author: Sehajvir Singh Pannu
*/
#pragma once
#include<iostream>
#include<string>
#include <locale>         // std::locale, std::isalpha
#include<vector>
#include<fstream>
#include "Book.h"

using namespace std;

class Database{
private:
	vector<Book> container;
public:

	//Description: Returns the total Book count currently stored in Databse.
	int getBookCount() const;

	//Description:Checks if "duplicate" Book object is already in the database.
	//            Returns true if "duplicate" object matches with any of object of database.
	bool check(const Book& duplicate) const;

	//Description:Insert an Element in the database.
	void  insert(const Book& newElement);

	//Description:Remove an Element from the database.
	void remove(const Book& toBeRemoved);

	//Description:Remove all Elements from databse.
	void removeAll();

	//Description: Updates Information on previously stored book objects in database.
	void updateBook( Book& toBeUpdated);

	//Search Funtions

	//Description:Search Books in the database with "find" title
	void searchByTitle(const string& find);

	//Description:Search Books in the database with "find" Author.
	void searchByAuthor(const string& find);

	//Description:Search Books in the database with "find" Year of Publication.
	void searchByYear(const int& find);

	//Description:Search Books in the database with "find" BookType.
	void searchByBookType(const string& find);

	//Description:Search Books in the database with "find" Number of Pages
	void searchByPage(const int& find);

	void searchBetweenTwoYear(const int& find,const int & find1);

	void searchBetweenTwoPages(const int& find,const int &find1);

	//Search funtion ends

	//Description:Saves Database in a text file.
	void save();

	friend ostream& operator <<(ostream& out, const Database& d);

};
#include "Database.cpp"
#include "Book.cpp"
