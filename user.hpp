#ifndef USER_HPP
#define USER_HPP
#include <iostream> 
#include <string> 
#include "Account.hpp"
#include "BookSearch.hpp"
#include "filemanager.hpp"
#include <sstream>

using namespace std; 

class User: public BookSearch, public Account
{
  private:
        vector<Book> borrowedBooks;
        int age;
        string message;

  public:
	User(string userName, string password, int age ) : Account(userName,password)
	{
	   this->age = age;		 			
	}
	string warningMessage;
	void setWarningMessage(string m)
	{
	    warningMessage = m;
	}

  	void displayBooks() 
	{
        	if( age < 17)
		{
			for (int i = 0; i < Books.size(); i++)
			{
				if(Books.at(i).maturity == 'E' && Books.at(i).availability && !Books.at(i).shelved)
				{
                        		cout << Books.at(i).name << " " << Books.at(i).author << " " << Books.at(i).genre << " " << Books.at(i).length <<" " <<  Books.at(i).id << endl;
                        		cout << Books.at(i).description << endl;
				}
			}
         	}
		else
		{
			for (int i = 0; i < Books.size(); i++)
			{
				if(Books.at(i).availability && !Books.at(i).shelved)
				{
                          		cout << Books.at(i).name << " " << Books.at(i).author << " " << Books.at(i).genre << " " << Books.at(i).length << " " << Books.at(i).id << endl;
                          		cout << Books.at(i).description << endl;
				}
			}
		}				
      	}

 	void displayBooks(ostream &out) 
        {
        	if( age < 17)
                {
                	for (int i = 0; i < Books.size(); i++)
                        {
                        	if(Books.at(i).maturity == 'E' && Books.at(i).availability && !Books.at(i).shelved)
                                {
                        		out << Books.at(i).name << " " << Books.at(i).author << " " << Books.at(i).genre << " " << Books.at(i).length <<" " <<  Books.at(i).id << endl;
                        		out << Books.at(i).description << endl;
                               	}
                        }
         	}
               	else
               	{
                	for (int i = 0; i < Books.size(); i++)
                        {
                        	if(Books.at(i).availability && !Books.at(i).shelved )
                                {
                          		out << Books.at(i).name << " " << Books.at(i).author << " " << Books.at(i).genre << " " << Books.at(i).length << " " << Books.at(i).id << endl;
                          		out << Books.at(i).description << endl;
                               	}
                       	}
              	}
      }

      void lookUser(string n) 
      {
		cout << "Displaying " << n <<  "'s borrowed books" << endl; 
		
        	for (int i = 0; i < borrowedBooks.size(); i++)
	      	{
                	cout << borrowedBooks.at(i).name << " " <<  borrowedBooks.at(i).author<< " " << borrowedBooks.at(i).genre <<  borrowedBooks.at(i).id << endl;
		       	if( borrowedBooks.at(i).rentalPeriod <= 0 )
		        {
				cout << borrowedBooks.at(i).name << "is overdue. " << endl << endl; ;
		        }
         	}
      }


     void lookUser(string n,ostream &out) 
     {
            //  out << "Displaying " << n <<  "'s borrowed books" << endl;

     		for (int i = 0; i < borrowedBooks.size(); i++)
              	{
                	out << borrowedBooks.at(i).name << " " <<  borrowedBooks.at(i).author<< " " << borrowedBooks.at(i).genre << " " <<   borrowedBooks.at(i).id << endl;
                        if( borrowedBooks.at(i).rentalPeriod <= 0 )
                        {
                        	out << borrowedBooks.at(i).name << "is overdue. " << endl << endl; ;
                        }
         	}
    }



    void addBook() 
    {
		int id = 0; 
		cout << "please provide the id of the book you wish to borrow" << endl; 
		cin >> id; 
		while( id < 0 || id > Books.size())
		{
			          cerr << "invalid id, please provide a valid id. " << endl; 
			          cin >> id;
		      }
		      if( Books.at(id).availability == true && !Books.at(id).shelved  )
		      {
			        Books.at(id).availability = false;
			        Book checkedBook = Books.at(id);
			        borrowedBooks.push_back(checkedBook);
				borrowedBooks.at(borrowedBooks.size()-1).availability = false; 
		      }
		      else 
		      {
			         cout << Books.at(id).name << " is not available." << endl;	
		      } 
		FileManager f;
		f.writeUser(borrowedBooks, userName);
    }

    Book getBorrowedBooks(int i ){
		 return borrowedBooks.at(i) ;
    }

    void removeBook() 
    {
		int ID = 0; 
		cout << "please provide the id of the book you wish to return" << endl; 
		cin >> ID; 
		
		while( ID < 0 || ID > Books.size())
		{
			cerr << "invalid id, please provide a valid id. " << endl; 
			cin >> ID;
		}
		
          	for( int i = 0; i < borrowedBooks.size(); i++)
          	{
                	if( borrowedBooks.at(i).id == ID)
		        {
                       		Books.at(ID).availability = true;
		      		// borrowedBooks.at(i).availability = true; 
                       		borrowedBooks.erase(borrowedBooks.begin() + (i));
                 	}
          	}
		FileManager f;
		f.write(Books);
		f.writeUser(borrowedBooks, userName);
  }
  void removeAccount(string name)
  {
	FileManager f;
	borrowedBooks = f.readUser(name);
	int size = borrowedBooks.size();
	cout << endl << "You must remove books that you have borrowed" << endl;
	for(int i = 0; i < size; i++)
	{
		removeBook();
	}
	f.writeUser(borrowedBooks, name);
	f.removeUser(name);	
  }
	         
};
#endif 
	  
