#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Book.h"
#include "Database.h"

using namespace std;

void loadFile(Database& d1){

	ifstream fin("Database.txt");
	string title,author,bookType;
	int year,pages;

	if(fin.fail()){
		cout<<"Input file stream failed";
	}	else{

		while(fin.eof()== false){

			Book b1;
			fin>>title>>author>>year>>bookType>>pages;

			b1.setTitle(title);
			b1.setAuthor(author);
			b1.setDateOfPublication(year);
			b1.setNumberOfPages(pages);
			b1.setBookType(bookType);
			d1.insert(b1);

		}
		fin.close();
	}
}

int main()
{

	string choice;
	Database library;
	bool done=false;
	while(!done)
	{
		system("cls");
		cout<<"Welcome to book records database application, What would you like to do?"<<endl;
		cout<<"\t1. Add a new book record to the database"<<endl;
		cout<<"\t2. Delete an exisiting book record from the database"<< endl;
		cout<<"\t3. Update any information of an existing book record in the database" << endl;
		cout<<"\t4. View you book records database"<<endl;
		cout<<"\t5. Search for a books records in the database"<<endl;
		cout<<"\t6. Load database from a file"<<endl;
		cout<<"\t7. Save the database to a file"<<endl;
		cout<<"\t8. Exit Application"<<endl;
		cout<<"Enter your choice please (Enter a number): ";
		cin>>choice;

		if(choice=="1")
		{

			Book b1;
			cout<<"Enter the details of Book";
			cin>>b1;
			library .insert(b1);
			cout<<"Your book is inserted in the database\t";
			system("pause");

		}
		else if(choice=="2")
		{

			Book b2;
			cout<<"Enter the details of book you want to delete";
			cin>>b2;
			library.remove(b2);
			system("pause");
		}
		else if(choice=="3")
		{

			Book b3;
			cout<<"Enter the details of the book you want to update";
			cin>>b3;
			library.updateBook(b3);
			cout<<library;
			system("pause");
		}
		else if(choice=="4")
		{

			cout<<"Total number of book records in database are "<<library.getBookCount()<<endl;
			cout<<library;
			system("pause");
		}

		else if(choice=="5")
		{
			system("cls");
			int selection;
			cout<<"Enter the choice b which you want to search book"<<endl;
			cout<<"\t 1.Search by Title "<<endl;
			cout<<"\t 2.Search by Author "<<endl;
			cout<<"\t 3.Search by Date of Publication "<<endl;
			cout<<"\t 4.Search by Booktype "<<endl;
			cout<<"\t 5.Search by Number of pages "<<endl;
			cout<<"\t 6.Search books between two year of publication"<<endl;
			cout<<"\t 7.Search books between two different total number of pages of book"<<endl;
			cout<<"Enter your choice: ";
			cin>>selection;
			string search;
			int help,help1;
			switch (selection)
			{
			case 1:cout<<"Enter Title: ";cin>>search;library.searchByTitle(search);break;
			case 2:cout<<"Enter Author: ";cin>>search;library.searchByAuthor(search);break;
			case 3:cout<<"Enter Year: ";cin>>help;library.searchByYear(help);break;
			case 4:cout<<"Enter BookType: ";cin>>search;library.searchByBookType(search);break;
			case 5:cout<<"Enter number of pages: ";cin>>help;library.searchByPage(help);break;
			case 6:cout<<"Enter Two year of publication: ";cin>>help;cout<<endl;cin>>help1;library.searchBetweenTwoYear(help,help1);break;
			case 7:cout<<"Enter two vale of total number of pages: ";cin>>help;cout<<endl;cin>>help1;library.searchBetweenTwoPages(help,help1);break;
			default:cout<<"Invalid selection";
			}
			cout<<endl;
			system("pause");

		}
		else if(choice=="6")
		{
			loadFile(library);
			cout<<library;
			system("pause");
		}
		else if(choice=="7")
		{
			library.save();
		}
		else if(choice=="8")
		{
			exit(0);
			return 0;
		}
		else
		{
			cout<<"Make a valid Selection! Please try again\t";
			
		}
	}

}
