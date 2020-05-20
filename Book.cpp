/*
* Book.cpp
*
* Description: Models the attributes of a Book (title, author, dateOfPublication, etc)
*
* Created on: May 16, 2020
* Author: Sehajvir Singh Pannu
*/

#include<iostream>
#include<string>
#include<vector>
#include <locale>         // std::locale, std::isalpha
#include<fstream>
#include "Book.h"

using namespace std;

//Description: Returns book's Title.
string Book :: getTitle() const{
  return title;
}

//Description: Returns book's Author.
string Book :: getAuthor() const{
  return author;
}

//Description: Returns book's year of publication.
int Book :: getDateOfPublication() const{
  return dateOfPublication;
}

//Description: Returns book's Type.
string Book :: getBookType() const{
  return bookType;
}

//Description: Returns book's Number of Pages
int Book :: getNumberOfPages() const{
  return numberOfPages;
}

//Description: Sets book's Title.
void Book :: setTitle(const string& newTitle){
  title = newTitle;
}

//Description: Sets book's Author.
void Book :: setAuthor(const string& newAuthor){
  author = newAuthor;
}

//Description: Sets book's year of publication.
void Book :: setDateOfPublication(const int& newDateOfPublication){
  dateOfPublication = newDateOfPublication;
}

//Description: Sets book's Type.
void Book :: setBookType(const string& newBookType){
  bookType = newBookType;
}

//Description: Returns book's Number of Pages
void Book :: setNumberOfPages(const int& newNumberOfPages){
  numberOfPages=newNumberOfPages;
}

//Overloaded Operators

//Description:Comparison opeartor.Compares "this" Book object with "b" Book object
//            Returns true if both Book objects have each and every member variables value same.
bool Book::operator==(const Book& b) const{
	if(this->title == b.title)
		if(this->author == b.author)
			if(this->dateOfPublication == b.dateOfPublication)
				if(this->bookType == b.bookType)
					if(this->numberOfPages == b.numberOfPages)
						return true;
					else
						return false;
				else
					return false;
			else
				return false;
		else
			return false;
	else
		return false;

}

//Description:Input the contents of"this"
istream& operator>>(istream& in , Book& b)
{
	cout << endl;
	cout << "Enter title of Book: ";
	in >> b.title;
	cout << "Enter the name of author of book: ";
	in >> b.author;
	cout << "Enter the date of publication: ";
	in >> b.dateOfPublication;
	cout << "Enter the type of book: ";
	in >> b.bookType;
	cout << "Enter the number of pages of book: ";
	in >> b.numberOfPages;

	return in;
}

//Description:Prints the content of "this"
ostream& operator<<(ostream& out, const Book& b){

	out<< b.title << " " << b.author << " " << b.dateOfPublication <<" " << b.bookType << " " << b.numberOfPages;

	return out;
}
