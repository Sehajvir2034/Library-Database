all: LibraryApp

LibraryApp: LibraryApp.o Book.o Database.o
	g++ -Wall -std=c++11 -o library LibraryApp.o Book.o Database.o

LibraryApp.o: LibraryApp.cpp
	g++ -Wall -std=c++11 -c LibraryApp.cpp

Book.o: Book.h Book.cpp
	g++ -Wall -std=c++11 -c Book.cpp

Database.o: Database.h Database.cpp
	g++ -Wall -std=c++11 -c Database.cpp

clean:
	rm -f LibraryApp *.o		
