/*
* Book.h
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
#include<vector>
#include <locale>         // std::locale, std::isalpha
#include<fstream>
using namespace std;

class Book{

private:
  string title;
	string author;
	int dateOfPublication;
	string bookType;
	int numberOfPages;

public:
  //----------------------------//
  //    Getters and Setters     //
  //----------------------------//

	//Description: Returns book's Title.
	string getTitle() const;

	//Description: Returns book's Author.
	string getAuthor() const;

	//Description: Returns book's year of publication.
	int getDateOfPublication() const;

	//Description: Returns book's Type.
	string getBookType() const;

	//Description: Returns book's Number of Pages
	int getNumberOfPages() const;

	//Description: Sets book's Title.
	void setTitle(const string& newTitle);

	//Description: Sets book's Author.
	void setAuthor(const string& newAuthor);

	//Description: Sets book's year of publication.
	void setDateOfPublication(const int& newDateOfPublication);

	//Description: Sets book's Type.
	void setBookType(const string& newBookType);

	//Description: Returns book's Number of Pages
	void setNumberOfPages(const int& newNumberOfPages);

	//---------------------------//
  //   Overloading Operators   //
  //---------------------------//

	//Description:Comparison opeartor.Compares "this" Book object with "b" Book object
	//            Returns true if both Book objects have each and every member variables value same.
	bool operator==(const Book& b) const;

	//Description:Input the contents of"this"
	friend istream& operator>>(istream& in , Book& b);

	//Description:Prints the content of "this"
	friend ostream& operator<<(ostream& out, const Book& b);

};
