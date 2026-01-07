#ifndef FileManager_HPP
#define FileManager_HPP

#include<fstream>
#include <vector>
#include "Account.hpp"
#include <string>


struct Users
{
	string username;
	string password;
	int age;
};

class FileManager : public Account{

    public:
	  vector<Book> read();                      //This will read Books.txt and fill up the vector all Books
	  void write(vector<Book> b);               //This will take in a vector and write in Books.txt

    vector<Book> readUser(string n);          //This will return the vector of Books that a user has
    void writeUser(vector<Book> b, string n); //This will be given a user's books vector and will be written in its own txt
    
    vector<Users> readAllUsers();                //This will populate a vector of type users for menu.cpp
    void writeAllUsers(vector<Users> u);         //This will write all the users from menu.cpp
       
    int removeUser(string FileName);            //This will remove the file from the directory
};
#endif
