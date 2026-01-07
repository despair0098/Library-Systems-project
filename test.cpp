#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Account.hpp"
#include "user.hpp"
#include "BookSearch.hpp"
#include "Admin.hpp"
#include "filemanager.hpp"

using namespace std;

TEST(DisplayBooks,Adult) {
	int age = 17;
	User* max =  new User("test123","pass123",age);	
	
	stringstream s;	

	Book t;
	t.id = 0;
	t.name = "calc";
	t.genre = "action";
	t.description = "cool math book";
	t.length = 5;
	t.availability = true;
	t.maturity = 'M';
	t.shelved = false;
	t.rentalPeriod = 14; 
	
	if(t.maturity != 'M' || age >= 17 ){
		max->Books.push_back(t); 	
		max->displayBooks(s);		
	} 

	EXPECT_EQ(s.str(),"calc  action 5 0\ncool math book\n");
	
}


TEST(DisplayBooks,underageUser) {
	int age = 11;
        User* kyle =  new User("test123","pass123",age);
  	      
	stringstream s;
	
        Book t;
        t.id = 1;
        t.name = "hist";
        t.genre = "action";
        t.description = "cool hist book";
        t.length = 5;
        t.availability = true;
        t.maturity = 'E';
        t.shelved = false;
        t.rentalPeriod = 14;

  
        kyle->Books.push_back(t);
        kyle->displayBooks(s);
     
	EXPECT_EQ(s.str(),"hist  action 5 1\ncool hist book\n");

}

TEST(addBook,1Book) {
        int age = 14;
        User* lyle  =  new User("test123","pass123",age);


        Book t;
        t.id = 0;
        t.name = "hist";
        t.genre = "action";
        t.description = "cool hist book";
        t.length = 5;
        t.availability = true;
        t.maturity = 'E';
        t.shelved = false;
        t.rentalPeriod = 14;

        lyle->Books.push_back(t);

        lyle->displayBooks();

        lyle->addBook();

        EXPECT_EQ(lyle->getBorrowedBooks(0).name,"hist");
	EXPECT_EQ(lyle->Books.at(0).availability,false);	
}

TEST(addBook,2Books) {
        int age = 14;
        User* lyle  =  new User("test123","pass123",age);


        Book t;
        t.id = 0;
        t.name = "hist";
        t.genre = "action";
        t.description = "cool hist book";
        t.length = 5;
        t.availability = true;
        t.maturity = 'E';
        t.shelved = false;
        t.rentalPeriod = 14;
	
	Book A;
        A.id = 1;
        A.name = "calc";
        A.genre = "action";
        A.description = "cool math book";
        A.length = 5;
        A.availability = true;
        A.maturity = 'E';
        A.shelved = false;
        A.rentalPeriod = 14;
	
        lyle->Books.push_back(t);
	lyle->Books.push_back(A);

        lyle->displayBooks();

	lyle->addBook();
	
        EXPECT_EQ(lyle->getBorrowedBooks(0).name,"calc");

}

TEST(lookUser,RandUser) {
        int age = 14;
        User* lyle  =  new User("test123","pass123",age);

	stringstream s;

        Book t;
        t.id = 0;
        t.name = "hist";
        t.genre = "action";
        t.description = "cool hist book";
        t.length = 5;
        t.availability = true;
        t.maturity = 'E';
        t.shelved = false;
        t.rentalPeriod = 14;

        Book A;
        A.id = 1;
        A.name = "calc";
        A.genre = "action";
        A.description = "cool math book";
        A.length = 5;
        A.availability = true;
        A.maturity = 'E';
        A.shelved = false;
        A.rentalPeriod = 14;

        lyle->Books.push_back(t);
        lyle->Books.push_back(A);

        lyle->displayBooks();

        lyle->addBook();
	lyle->addBook();
	
	lyle->lookUser("lyle",s);
	
	EXPECT_EQ(s.str(),"hist  action 0\ncalc  action 1\n");

}


TEST(RemBook,remSingle) {
        int age = 14;
        User* lyle  =  new User("test123","pass123",age);

        stringstream s;

        Book t;
        t.id = 0;
        t.name = "hist";
        t.genre = "action";
        t.description = "cool hist book";
        t.length = 5;
        t.availability = true;
        t.maturity = 'E';
        t.shelved = false;
        t.rentalPeriod = 14;

        Book A;
        A.id = 1;
        A.name = "calc";
        A.genre = "action";
        A.description = "cool math book";
        A.length = 5;
        A.availability = true;
        A.maturity = 'E';
        A.shelved = false;
        A.rentalPeriod = 14;

        lyle->Books.push_back(t);
        lyle->Books.push_back(A);

        lyle->displayBooks();

        lyle->addBook();
        lyle->addBook();

        lyle->lookUser("lyle");

        lyle->removeBook();

        EXPECT_EQ(lyle->Books.at(0).availability,true);



}

TEST(RemBook,adultBookFilter) {
        int age = 14;
        User* lyle  =  new User("test123","pass123",age);
	
	stringstream s;
	
        Book t;
        t.id = 0;
        t.name = "hist";
        t.genre = "action";
        t.description = "cool hist book";
        t.length = 30;
        t.availability = true;
        t.maturity = 'E';
        t.shelved = false;
        t.rentalPeriod = 14;

        Book A;
        A.id = 1;
        A.name = "calc";
        A.genre = "action";
        A.description = "cool math book";
        A.length = 23;
        A.availability = true;
        A.maturity = 'M';
        A.shelved = false;
        A.rentalPeriod = 14;

        lyle->Books.push_back(t);
        lyle->Books.push_back(A);

        lyle->displayBooks();

        lyle->addBook();

        lyle->lookUser("lyle");
	
	lyle->removeBook();

	EXPECT_EQ(lyle->Books.at(0).availability,true); 
	
}

TEST(USER, removeUser_success)
{

}

TEST(Admin, addBook1) {
    Admin admin;
    stringstream s;
	
    admin.addBook();
    admin.displayBooks(s);
    EXPECT_EQ(s.str(), "ID: 0\nTitle: maze runner\nAuthor: michael jordan\nGenre: action rpg\nDescription: my life\nLength: 234\nAvailability: it is on the shelf\nAvailability: it is in the archive\nMaturity: E\n");
}

TEST(Admin, removeBook) {
   Admin admin;
   stringstream s;
  
  
   admin.addBook();
   admin.addBook();
   admin.displayBooks();
   admin.removeBook();
   admin.displayBooks(s);
   EXPECT_EQ(s.str(), "ID: 0\nTitle: maze runner\nAuthor: michael jordan\nGenre: action rpg\nDescription: my life\nLength: 234\nAvailability: it is on the shelf\nAvailability: it is in the archive\nMaturity: E\n");
}


TEST(Admin, changeAvail) {
   Admin admin;
   stringstream s;

   admin.addBook();
  // admin.editBook();
   admin.displayBooks(s);
   EXPECT_EQ(s.str(), "ID: 0\nTitle: maze runner\nAuthor: michael jordan\nGenre: action rpg\nDescription: my life\nLength: 234\nAvailability: it is on the shelf\nAvailability: it is in the archive\nMaturity: E\n");
}

TEST(Admin, newDay) {
    Admin admin;
    vector<Book> books;

    Book book1;
    book1.id = 0;
    book1.name = "maze runner";
    book1.rentalPeriod = 14;
    books.push_back(book1);

    Book book2;
    book2.id = 1;
    book2.name = "harry potter";
    book2.rentalPeriod = 14;
    books.push_back(book2);

    FileManager f;
    f.writeUser(books, "test321");
    admin.newDay("test321");
    vector<Book> result = f.readUser("test321");
    EXPECT_EQ(result.at(0).rentalPeriod, 13);
    EXPECT_EQ(result.at(1).rentalPeriod, 13);
    
}

TEST(Admin, lookUser) {
    Admin admin;
    vector<Book> books;

    Book book1;
    book1.id = 0;
    book1.name = "maze runner";
    book1.author = "michael";
    book1.rentalPeriod = 14;
    books.push_back(book1);

    Book book2;
    book2.id = 1;
    book2.name = "harry potter";
    book2.author = "john";
    book2.rentalPeriod = 14;
    books.push_back(book2);

    FileManager f;
    f.writeUser(books, "test321");
    vector<Book> result = f.readUser("test321");
    
    EXPECT_EQ(admin.getMessage("test321"), "ID: 0\nTitle: maze runner\nAuthor: michael\nRental period: 14ID: 1\nTitle: harry potter\nAuthor: john\nRental period: 14");
}

TEST(FileManagerTest, reading_writing_users_txt) 
{
	FileManager f;
	vector<Book> list;
	vector<Book> result;
	Book b, c;

	b.id = 0;
	b.name = "Name";
	b.author = "Author";
	b.genre = "Genre";
	b.description = "This is the description.";
	b.length = 100;
	b.rentalPeriod = 14;
	b.availability = true;
	b.maturity = 'E';
	b.shelved = false;
	list.push_back(b);

	c.id = 1;
  	c.name = "Name2";
  	c.author = "Author2";
  	c.genre = "Genre2";
  	c.description = "This is the description2.";
  	c.length = 200;
  	c.rentalPeriod = 14;
  	c.availability = false;
  	c.maturity = 'M';
  	c.shelved = true;
	list.push_back(c);
	f.write(list);

	result = f.read();
	EXPECT_EQ(result[0].id, 0);
	EXPECT_EQ(result[0].name, "Name");
	EXPECT_EQ(result[0].author, "Author");
	EXPECT_EQ(result[0].genre, "Genre");
	EXPECT_EQ(result[0].description, "This is the description.");
	EXPECT_EQ(result[0].length, 100);
 	EXPECT_EQ(result[0].rentalPeriod, 14);
	EXPECT_TRUE(result[0].availability);
  	EXPECT_EQ(result[0].maturity, 'E');
	EXPECT_TRUE(!result[0].shelved);
	
	EXPECT_EQ(result[1].id, 1);
  	EXPECT_EQ(result[1].name, "Name2");
 	EXPECT_EQ(result[1].author, "Author2");
  	EXPECT_EQ(result[1].genre, "Genre2");
  	EXPECT_EQ(result[1].description, "This is the description2.");
  	EXPECT_EQ(result[1].length, 200);
  	EXPECT_EQ(result[1].rentalPeriod, 14);
  	EXPECT_TRUE(!result[1].availability);
  	EXPECT_EQ(result[1].maturity, 'M');
  	EXPECT_TRUE(result[1].shelved);	 
}

TEST(FileManagerTest, reading_and_writing_user_files)
{
	FileManager f;
	vector<Book> list;
	vector<Book> result;
	Book b, c;

	b.name = "name";
	b.author = "author";
	b.genre = "genre";
	b.id = 0;
	b.rentalPeriod = 7;
	list.push_back(b);
	
	c.name = "Name";
	c.author = "Author";
	c.genre = "Genre";
	c.id = 1;
	c.rentalPeriod = 1;
	list.push_back(c);
	
	f.writeUser(list, "test123");
	result = f.readUser("test123");
	
	EXPECT_EQ(result[0].name, "name");
	EXPECT_EQ(result[0].author, "author");
	EXPECT_EQ(result[0].genre, "genre");
	EXPECT_EQ(result[0].id, 0);
	EXPECT_EQ(result[0].rentalPeriod , 7);

	EXPECT_EQ(result[1].name, "Name");
  	EXPECT_EQ(result[1].author, "Author");
  	EXPECT_EQ(result[1].genre, "Genre");
  	EXPECT_EQ(result[1].id, 1);
	EXPECT_EQ(result[1].rentalPeriod , 1);
}

TEST(FileManagerTest, reading_and_writing_all_user_information)
{
	FileManager f;
	vector<Users> list, result;
	Users b, c;
	
	b.username = "userName";
	b.password = "passWord";
	b.age = 16;
	list.push_back(b);
	
	c.username = "USERNAME";
	c.password = "PASSWORD";
	c.age = 18;
	list.push_back(c);

	f.writeAllUsers(list);
	result = f.readAllUsers();
	
	EXPECT_EQ(result[0].username, "userName");
  	EXPECT_EQ(result[0].password, "passWord");
  	EXPECT_EQ(result[0].age, 16);

	EXPECT_EQ(result[1].username, "USERNAME");
  	EXPECT_EQ(result[1].password, "PASSWORD");
  	EXPECT_EQ(result[1].age, 18);
}	

TEST(FileManagerTest, removing_user_pass)
{
	ofstream o;
	string name = "test999";
	o.open(name + ".txt");
	FileManager f;
	EXPECT_EQ(f.removeUser(name), 0 );
	
}

TEST(FileManagerTest, removing_user_fail)
{
	FileManager f;
	EXPECT_TRUE(f.removeUser("invalid") != 0);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}

