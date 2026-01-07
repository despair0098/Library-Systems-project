#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include <vector>
#include <string>
#include "BookSearch.hpp"

using namespace std;

struct Book
{
     int id;
     string name;
     string author;
     string genre;
     string description;
     int length;
     int rentalPeriod;
     bool availability;
     char maturity;
     bool shelved; 
};

class Account 
{
     protected: 
          string userName;
	         string passWord;
	  
     private:
         BookSearch* strategy; 
     public:
         vector<Book> Books;
         Account(){}
         Account(string userName, string passWord)
         {
              this->userName = userName;
              this->passWord = passWord;
         }
         Account(BookSearch* const s) : strategy(s){}
         //~Account(){delete this->strategy;}
	    virtual void display()
         {
              this->strategy->displayBooks();
         }
         virtual void add()
         {
              this->strategy->addBook();
         }
         virtual void removeB()
         {
              this->strategy->removeBook();
         }
         virtual void look(string n)
         {
              this->strategy->lookUser(n);
         }
};
#endif

