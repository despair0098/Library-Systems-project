#include<fstream>
#include "filemanager.hpp"
#include <vector>
#include <string>
using namespace std;

vector<Book> FileManager::read()
{
 	ifstream reader;
	string s;
	vector<Book> list;
	Book b;

	reader.open("Books.txt");
	while(reader.is_open())
	{
		getline(reader, s, ' ');                //This will read the id
		b.id = stoi(s);                         //turn string to int for id
		getline(reader, b.name, '.');           //This will read the name
		getline(reader, b.author, '|');         //This will read the author
		getline(reader, b.genre, '.');          //This will read the genre
		getline(reader, b.description, '|');    //This will read the description
		getline(reader, s, '.');                //This will read the length
		b.length = stoi(s);                     //turn string to int for length
		getline(reader,s, '.');                //This will read the rentalPeriod
		b.rentalPeriod = stoi(s);               //turn string to int for rentalPeriod
		getline(reader, s , '.');    //This will read availability
		if(s == "1")
		{
			b.availability = true;
		}
		else
		{
			b.availability = false;
		}
		getline(reader, s , '.');       //This will read maturity
		b.maturity = s[0];
		getline(reader, s , ' ');    //This will read availability
                if(s == "1")
                {
                        b.shelved = true;
                }
                else
                {
                        b.shelved = false;
                }
		list.push_back(b);                      //This will push object of Book b into vector<Book> list 
		getline(reader, s, ' ');                
		if ( s[0] != ';') //This if statement checks if there is a semicolon, when there is no semicolon
		{              //then it will close the ifstream
			reader.close();
		} 	
	} //repeat until open, if the if statement above is true, then the file will close and exit the loop
	
	return list;
}

void FileManager::write(vector<Book> b)
{

	ofstream writer;
	writer.open("Books.txt");
	
	for(int i = 0; i < b.size(); i++)
	{
		writer << b[i].id << " " << b[i].name << "."<< b[i].author << "|" << b[i].genre << "." << b[i].description << "|";
		writer << b[i].length << "." << b[i].rentalPeriod << "."<< b[i].availability << "."<< b[i].maturity << ".";
		writer << b[i].shelved << " ";
		if(i+1 < b.size())
		{
			writer<< "; ";
		}
		else
		{
			writer<< " ";
			break;
		}		
	}
	writer.close();

}
vector<Book> FileManager::readUser(string n)
{
	ifstream reader;
	vector<Book> list;
	Book b;
	string s;
	reader.open(n + ".txt");

	while(reader.is_open())
	{
		getline(reader, b.name, '.');
		getline(reader, b.author, '|');
		getline(reader, b.genre, '.');
		getline(reader, s, ' ');
		b.id = stoi(s);
		getline(reader, s, ' ');
                b.rentalPeriod = stoi(s);
		list.push_back(b);
		getline(reader, s, ' ');                
		if ( s[0] != ';') //This if statement checks if there is a semicolon, when there is no semicolon
		{              //then it will close the ifstream
			reader.close();
		} 	

	}
	return list;
}

void FileManager::writeUser(vector<Book> b, string n)
{
	ofstream writer;

	writer.open(n + ".txt");
	for(int i = 0; i < b.size(); i++)
	{
		writer << b[i].name << "." << b[i].author << "|" << b[i].genre << "."<< b[i].id << " " << b[i].rentalPeriod << " ";
		if (i+1 < b.size())
		{
			writer << "; ";
		}
		else
		{
			writer << " ";
			writer.close();
		}
	}

}


vector<Users> FileManager::readAllUsers()
{
	ifstream reader;
	string s;
	vector<Users> list;
	Users u;

	reader.open("Users.txt");
	while(reader.is_open())
	{
		
		getline(reader, u.username, ' ');                //This will read the username
		getline(reader, u.password, ' ');                //This will read the password
		getline(reader, s, ' ');                         //This will read the string     
		u.age = stoi(s);                                 //This will convert the string to integer

		list.push_back(u);                              //Push new user
		
		getline(reader, s, ' ');                
		if ( s[0] != ';') //This if statement checks if there is a semicolon, when there is no semicolon
		{              //then it will close the ifstream
			reader.close();
		} 	
	}

	return list; 	
}

void FileManager::writeAllUsers(vector<Users> u)
{
	ofstream writer;

	writer.open("Users.txt");
	for(int i = 0; i < u.size(); i++)
	{
		writer << u[i].username << " " << u[i].password << " " << u[i].age << " ";
		if(i+1 < u.size())
		{
			writer<< "; ";
		}
		else
		{
			writer << " ";
			writer.close();
		}
	}
}

int FileManager::removeUser(string FileName)
{
	FileName += ".txt";                     //Adds txt in FileName
	const char* file = FileName.c_str();    //converts to char* to use remove
	int ans = remove(file);                 //calls remove function to remove file
	if (ans == 0) //if ans = 0 then it is succesful
	{
		cout << "Succesfully Deleted: " << FileName << endl;
	}
	else
	{
		cerr << "Error: Cannot delete " << FileName << endl;
	}
	
	return ans;
}
