#include <iostream>
#include <string>
#include <vector> 
#include "Admin.hpp"
#include "user.hpp"
#include "filemanager.hpp"

using namespace std;

template <typename T, typename U>
class Iterator {
public:
	typedef typename std::vector<T>::iterator iter_type;
	Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
		m_it_ = m_p_data_->m_data_.begin();
	}

	void First() {
		m_it_ = m_p_data_->m_data_.begin();
	}

	void Next() {
		m_it_++;
	}

	bool IsDone() {
		return (m_it_ == m_p_data_->m_data_.end());
	}

	iter_type Current() {
		return m_it_;
	}

private:
	U *m_p_data_;
	iter_type m_it_;
};

template <class T>
class Container {
	friend class Iterator<T, Container>;

public:
	void Add(T a) {
		m_data_.push_back(a);
	}

	Iterator<T, Container> *CreateIterator() {
		return new Iterator<T, Container>(this);
	}

private:
	std::vector<T> m_data_;
};

class Data {
public:
	Data(string a = "") : m_data_(a) {}

	void set_data(int a) {
		m_data_ = a;
	}

	string data() {
		return m_data_;
	}

private:
	string m_data_;
};

class intData {
public:
	intData(int a = 0) : m_data_(a) {}

	void set_data(int a) {
		m_data_ = a;
	}

	int data() {
		return m_data_;
	}

private:
	int m_data_;
};

int main()
{
	Container<Data> usernames, passwords;
	Container<intData> ages;
	Iterator<Data, Container<Data> > *it = usernames.CreateIterator();
	Iterator<Data, Container<Data> > *it2 = passwords.CreateIterator();
	Iterator<intData, Container<intData> > *it3 = ages.CreateIterator();
    	cout << "Library System" << endl;
    	cout << endl;
	cout << "Choose an option" << endl;
    	cout << "1. Admin Login" << endl;
    	cout << "2. User Login" << endl;
    	cout << "3. Create User" << endl;
    	cout << "4. Exit" << endl;
	int option; 
	cin >> option;
    while ( option != 4 )
	{	
    	if (option == 1)
    	{
			string username;
			string password;
			bool name = false;
			bool word = false;
			cout << "Admin Login" << endl;
			cout << "Please enter your username: ";
			cin >> username;
			//if statement checking if the username matches to one in the database
			//else cout "Username not found"
			if ( username == "admin" )
			{
	    		name = true;
			}
			cout << "Please enter your password: ";
			cin >> password;
			if ( password == "admin" )
			{
	   			word = true;
			}
			//This username and password if-else statement is just a placeholder, but it will be replaced by the login() function later
			if ( name == true && word == true )
			{
				//All the functions for the admin class and what they can do in the library will be implemented here
				//Call filemanager function to populate the Books vector. 
				Account a(new Admin());
				cout << "Choose an option" << endl;
				cout << "1. Add a book" << endl;
				cout << "2. Remove a book" << endl;
	    			cout << "3. Edit a book" << endl;
	    			cout << "4. Display Books" << endl;
	    			cout << "5. New Day" << endl;
	    			cout << "6. Look User" << endl;
				cout << "7. Exit" << endl;
				int input1; 
				cin >> input1;
				cin.ignore();
				while ( input1 != 7 )
				{
					if ( input1 == 1 )
					{
						//Add the add book function here
						//This will add the books to a vector and it will be stored there acting like a library
						a.add();
					}
					if ( input1 == 2 )
					{
						//Add the remove book function here
						//This will remove the books from the vector
						a.removeB();
					}
					if ( input1 == 3 )
					{
						//Add edit book function here
						static_cast<Admin*>(&a)->editBook();
					}	
					if ( input1 == 4 )
					{
						//Add display books function here
						//Display all the books currently in the library 
						a.display();
					}
					if ( input1 == 5 )
					{
						//Add new day function here
						for (it->First(); !it->IsDone(); it->Next())
                        			{			
							static_cast<Admin*>(&a)->newDay(it->Current()->data());
						}
					}
					if ( input1 == 6 )
					{
						//Add look user function here
						for(it->First(); !it->IsDone(); it->Next())
						{
							a.look(it->Current()->data());
						}
					}
					if ( input1 == 7 )
					{
						break;
					}
					cout << "Choose an option" << endl;
					cout << "1. Add a book" << endl;
					cout << "2. Remove a book" << endl;
	    				cout << "3. Edit a book" << endl;
	    				cout << "4. Display Books" << endl;
	    				cout << "5. New Day" << endl;
	    				cout << "6. Look User" << endl;
					cout << "7. Exit" << endl;
					input1 = 0;
					cin >> input1;
				}
			}
    	}
    	else if ( option == 2 )
    	{
			FileManager f;
			string username1;
			string password1;
			bool name1 = false;
			bool word1 = false;
			vector<Users> u = f.readAllUsers();
			for ( int i = 0; i < u.size(); i++ )
			{
				Data a(u[i].username), b(u[i].password);
				usernames.Add(a);
				passwords.Add(b);
			}
			cout << "User Login" << endl;
			cout << "Please enter your username: ";
			cin >> username1;
			it2->First();
			it3->First();
			//if statement checking if the username matches to one in the database
			//else cout "Username not found"
			for (it->First(); !it->IsDone(); it->Next()) 
			{
				if( username1 == it->Current()->data() )
				{
					name1 = true;
					cout << "Please enter your password: ";
					cin >> password1;
					if ( password1 == it2->Current()->data() )
					{
						word1 = true;
					}
				}
				else
				{
					it2->Next();
					it3->Next();
				}
			}
			if ( name1 == true && word1 == true )
			{
				//All the functions for the user class and what they can do in the library will be implemented here
				//Call filemanager function to populate the Books vector. 
				Account u(new User(it->Current()->data(), it2->Current()->data(), it3->Current()->data()));
				cout << "Choose an option" << endl;
				cout << "1. Display Books" << endl;
				cout << "2. Show Borrowed" << endl;
	    			cout << "3. Borrow Book" << endl;
	    			cout << "4. Return Book" << endl;
				cout << "5. Clear Account" << endl;
				cout << "6, Exit" << endl;
				int option1; 
				cin >> option1;
				while ( option1 != 6 )
				{
					if ( option1 == 1 )
					{
						//Add the display book function here
						//Display all the books in the library, but not the archived ones. This will be sorted in the BookSearch function. 
						//There will also be age ratings for displaying which books to certain users based on their age
						//UserE class for books rated for everyone
						//UserM class for books rated for adults. This will take in a vector to see which users are allowed to see this section of books. 
						u.display();
					}
					if ( option1 == 2 )
					{
						//Add the show borrowed function here
						u.look(it->Current()->data());
					}
					if ( option1 == 3 )
					{
						//Add borrow book function here
						//The Book class will be used here to search for the books. 
						u.add();
					}
					if ( option1 == 4 )
					{
						//Add return book function here
						u.removeB();
					}
					if ( option1 == 5 )
					{
						//Remove User
						//No more borrowed book
						static_cast<User*>(&u)->removeAccount(it->Current()->data());
						
					}
					if ( option1 == 6 )
					{
						f.write(u.Books);
						break;
					}
					cout << "1. Display Books" << endl;
					cout << "2. Show Borrowed" << endl;
	    				cout << "3. Borrow Book" << endl;
		    			cout << "4. Return Book" << endl;
					cin >> option1;
				}
			}
			cin >> option;
    	}
    	else if ( option == 3 )
    	{
			bool available = false; 
			string newUser;
			string newPass;
			int newAge;
			cout << "Enter your username";
			cin >> newUser;
			for (it->First(); !it->IsDone(); it->Next()) 
			{
				if( newUser == it->Current()->data() )
				{
					cout << "Username is taken";
					available = false; 
					break;
				}
				else
				{
					available = true;
				}
			}
			if ( available == true )
			{
				cout << "Enter your password";
				cin >> newPass; 
				bool check = false; 
				while ( check == false )
				{
					for (int i = 0; i < newPass.length(); i++ )
					{
						if ( isspace(newPass[i]) ) 
						{
							bool check = true; 
							break;
						}
						else
						{
							check = false;
						}
					}
					if ( check == true )
					{
						cout << "Invalid Password, enter a password with no spaces.";
						cin >> newPass;
						check = false;
					}
					else
					{
						check = true;
						cout << "What is your age";
						cin >> newAge;
					} 
				}
			}
			cin >> option;
    	}
    	else if ( option == 4 )
    	{
			
			break;
		}
		cout << "Choose an option" << endl;
		cout << "1. Admin Login" << endl;
		cout << "2. User Login" << endl;
		cout << "3. Create User" << endl;
		cout << "4. Exit" << endl;
		option = 0; 
		cin >> option;
	}
	delete it;
	delete it2;
	delete it3;
}	
