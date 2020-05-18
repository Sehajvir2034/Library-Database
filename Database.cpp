/*
* Database.cpp
*
* Description: Models the attributes of a Book (title, author, dateOfPublication, etc)
*
* Created on: May 16, 2020
* Author: Sehajvir Singh Pannu
*/

#include <iostream>
#include <string>
#include <vector>
#include <locale>        
#include <fstream>
#include "Database.h"
#include "Book.h"

using namespace std;

int Database :: getBookCount() const{
    return container.size();
}

bool Database :: check(const Book& duplicate) const
{
	bool check=false;
	for(int i=0;i<container.size();i++)
	{

		if(container[i]==duplicate)
		{
			cout<<"This book is already in the database"<<endl;
			check=true;
			return true;
		}

	}
	if(check==false)
		return false;
}

void Database :: insert(const Book& newElement)
{

	if(check(newElement)==false)
		container.push_back(newElement);

}

void Database :: remove(const Book& toBeRemoved)
{
	bool check=false;
	for(int i=0;i<container.size();i++)
	{

		if(container[i]==toBeRemoved)
		{
			container.erase(container.begin()+i);

			check=true;
		}
	}
	if(check==false)
		cout<<"Details of book are not right! Please again make a selection";
}

void Database :: removeAll()
{
	container.erase(container.begin(),container.end());

}


void Database :: updateBook( Book& toBeUpdated)
{
	bool done=false;
	int selection;
	string choice;
	Book change;
	change=toBeUpdated;

	if(check(toBeUpdated)==true)
	{
		while(!done)
		{
			cout<<"Enter the number corresponding to the thing you want to update in the book record"<<endl;
			cout<<"\t1. Title of book"<<endl;
			cout<<"\t2. Author of book"<<endl;
			cout<<"\t3. Date of Publication of book"<<endl;
			cout<<"\t4. Type of Book "<<endl;
			cout<<"\t5. Total number of pages of book"<<endl;
			cout<<"\t6. No more updated required in this book"<<endl;
			cout<<"Enter your choice: ";
			cin>>selection;
			string update;
			int updated;

			switch(selection)
			{
			case 1:cout<<"Enter the title: " ;cin>>update;toBeUpdated.setTitle(update);break;
			case 2:cout<<"Enter the author of book: ";cin>>update;toBeUpdated.setAuthor(update);break;
			case 3:cout<<"Enter the date of Publication: ";cin>>updated;toBeUpdated.setDateOfPublication(updated);break;
			case 4:cout<<"Enter the type of book: ";cin>>update;toBeUpdated.setBookType(update);break;
			case 5:cout<<"Enter the total number of pages: ";cin>>updated;toBeUpdated.setNumberOfPages(updated);
			case 6:done=true;break;
			default:cout<<"Enter a valid input";
			}


		}

		remove(change);
		insert(toBeUpdated);

	}
	else
		cout<<"Details of the book you want to update are not right! Please again make a selection"<<endl;

}

void Database :: searchByTitle(const string& find)
{
	bool done=false;
	for(int i=0;i<container.size();i++)
	{
		if(container[i].getTitle()==find)
		{
			done=true;
			cout<<container[i]<<endl;
		}
	}
	if(done==false)
		cout<<"No Book by this title is in the database";
}

void Database :: searchByAuthor(const string& find)
{
	bool done=false;
	for(int i=0;i<container.size();i++)
	{
		if(container[i].getAuthor()==find)
		{
			done=true;
			cout<<container[i]<<endl;
		}
	}
	if(done==false)
		cout<<"No Book by this title is in the database";
}

void Database :: searchByYear(const int& find)
{
	bool done=false;
	for(int i=0;i<container.size();i++)
	{
		if(container[i].getDateOfPublication()==find)
		{
			done=true;
			cout<<container[i]<<endl;
		}
	}
	if(done==false)
		cout<<"No Book by this title is in the database";
}

void Database :: searchByBookType(const string& find)
{
	bool done=false;
	for(int i=0;i<container.size();i++)
	{
		if(container[i].getBookType()==find)
		{
			done=true;
			cout<<container[i]<<endl;
		}
	}
	if(done==false)
		cout<<"No Book by this title is in the database";
}
void Database :: searchByPage(const int& find)
{
	bool done=false;
	for(int i=0;i<container.size();i++)
	{
		if(container[i].getNumberOfPages()==find)
		{
			done=true;
			cout<<container[i]<<endl;
		}
	}
	if(done==false)
		cout<<"No Book by this title is in the database";
}

void Database :: searchBetweenTwoYear(const int& find,const int& find1)
{
	bool done=false;
	for(int i=0;i<container.size();i++)
	{
		if(find>find1)
		{
			if(container[i].getDateOfPublication()>find1 && container[i].getDateOfPublication()<find)
			{
				done=true;
				cout<<container[i]<<endl;
			}
		}
		else if (find1>find)
		{
			if(container[i].getDateOfPublication()>find && container[i].getDateOfPublication()<find1)
			{
				done=true;
				cout<<container[i]<<endl;
			}

		}
		else
			cout<<"Both value are the same";
	}
	if(done==false)
		cout<<"No book records avaliable in database between these two year of publication ";


}

void Database :: searchBetweenTwoPages(const int& find, const int& find1)
{
	bool done=false;
	for(int i=0;i<container.size();i++)
	{
		if(find>find1)
		{
			if(container[i].getNumberOfPages()>find1 && container[i].getNumberOfPages()<find)
			{
				done=true;
				cout<<container[i]<<endl;
			}
		}
		else if (find1>find)
		{
			if(container[i].getNumberOfPages()>find && container[i].getNumberOfPages())
			{
				done=true;
				cout<<container[i]<<endl;
			}

		}
		else
			cout<<"Both value are the same";
	}
	if(done==false)
		cout<<"No book records avaliable in database between these two pages of number ";

}

void Database :: save()
{
	ofstream fout("MyDatabase.txt");
	fout<<"Book records in a databse";
	for(int i=0;i<container.size();i++)
	{
		fout<<container[i].getTitle()<<"\t"<<container[i].getAuthor()<<"\t"<<container[i].getDateOfPublication()<<"\t"<<container[i].getBookType()<<"\t"<<container[i].getNumberOfPages()<<endl;

	}
	fout.close();

}


ostream& operator<<(ostream& out,const Database& d)
{
	for(int i=0;i<d.getBookCount();i++)
		cout<<d.container[i];
	return out;
}
