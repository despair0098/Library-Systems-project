#include "Admin.hpp"
#include "filemanager.hpp"
using namespace std;

void Admin::addBook() {
    // ask the fields of the books by the user;
    FileManager f;
    Book book1;
    string inputS;
    int inputN;
    book1.rentalPeriod = 14;
    book1.id = Books.size();
    book1.availability = true;
    cout << "What is the title of the book?" << endl;
    getline(cin, inputS);
    book1.name = inputS;
    cout << "Author of the book?" << endl;
    getline(cin, inputS);
    book1.author = inputS;
    cout << "Genre?" << endl;
    getline(cin, inputS);
    book1.genre = inputS;
    cout << "Description?" << endl;
    getline(cin, inputS);
    book1.description = inputS;
    cout << "Length(# of pages) for the book?" << endl;
    cin >> inputN;
    cin.ignore();
    book1.length = inputN;
    cout << "Is it going to be on the shelf?(True/False)" << endl;
    getline(cin, inputS);
    if(tolower(inputS[0]) == 't'){
        book1.shelved = true;
    } else if(tolower(inputS[0]) == 'f'){
        book1.shelved = false;
    }
    cout << "Maturity?" << endl;
    getline(cin, inputS);
    book1.maturity = inputS[0];
    Books.push_back(book1);
    f.write(Books);
}

void Admin::removeBook() {
    // the ID itself is just the index of the vector
        FileManager f;
	Books = f.read();
	int ID;
        bool validID = false;
        while(!validID){
            cout << "Which book do you want to remove? Type the ID of the book: " << endl;
            cin >> ID;
            if(ID >= Books.size()){
                cerr << "Invalid ID." << endl;
		ID = 0;
            } else {
                validID = true;
            }
        }
        Books.erase(Books.begin() + (ID));
	f.write(Books);
}


void Admin::editBook(){
	FileManager f;
	Books = f.read();
    	int ID = 0;
        bool validID = false;
	cout << Books.size() << endl;
        while(!validID){
            cout << "Which book do you want to edit? Type the ID of the book: " << endl;
            cin >> ID;
            if(ID >= Books.size()){
		cout << Books.size() << endl;
                cerr << "Invalid ID." << endl;
            } else {
                validID = true;
            }
        }

        if(validID){
            char input;
            while(input != 'Q'){
                string inputS;
                int inputN;
                cout << "What do you want to edit?" << endl;
                cout << "A: Availability" << endl;
                cout << "B: Description" << endl;
                cout << "C: Maturity" << endl;
                cout << "D: Shelved(in the archive or at the shelf)" << endl;
                cout << "Q: Quit" << endl;
                cin >> input;
		cin.ignore();
                if(input == 'A'){
                    cout << "Type the availability of the book(t/f): " << endl;
                    getline(cin, inputS);
                        if(tolower(inputS[0]) == 't'){
                            Books.at(ID).availability = true;
                        } else if(tolower(inputS[0]) == 'f'){
                            Books.at(ID).availability = false;
                        }
                } else if(input == 'B'){
                    cout << "Type new description: " << endl;
                    getline(cin, inputS);
                    Books.at(ID).description = inputS;
                } else if(input == 'C'){
                    cout << "Type new maturity of the book(E/M): " << endl;
                    getline(cin, inputS);
                    Books.at(ID).maturity = inputS[0];
                } else if(input == 'D'){
                    if(Books.at(ID).availability == true){
                        cout << "Type the shelved status of the book(t/f): " << endl;
                        getline(cin, inputS);
                        if(tolower(inputS[0]) == 't'){
                            Books.at(ID).shelved = true; // in archive
                        } else if(tolower(inputS[0]) == 'f'){
                            Books.at(ID).shelved = false; // not in archive
                        }
                    } else {
                        // if availability is false, admin can't change if its shelved or not
                        cerr << "ERROR: can't shelved the book that is being borrowed" << endl;
                    }
                } else if(input =='Q'){
                    break;
                }
            }
        }
	f.write(Books);
}

void Admin::displayBooks() {
    // display all of the books on the shelf AND archive
     FileManager f;
     Books = f.read();
     for (int i = 0; i < Books.size(); i++){
        cout << "ID: " << i << endl;
        cout << "Title: " << Books.at(i).name << endl;
        cout << "Author: " << Books.at(i).author << endl;
        cout << "Genre: " << Books.at(i).genre << endl;
        cout << "Description: " << Books.at(i).description << endl;
        cout << "Length: " << Books.at(i).length << endl;
        if(Books.at(i).availability == true){
            cout << "Availability: it is on the shelf" << endl;
        } else if(Books.at(i).availability == false){
            cout << "Availability: it is NOT on the shelf" << endl;
        }
        if(Books.at(i).shelved == true){
            cout << "Availability: it is in the archive" << endl;
        } else if(Books.at(i).shelved == false){
            cout << "Availability: it is NOT in the archive" << endl;
        }
        cout << "Maturity: " << Books.at(i).maturity << endl;
    }
}

void Admin::displayBooks(ostream& out) {
	FileManager f;
	Books = f.read();
	for (int i = 0; i < Books.size(); i++){
        out << "ID: " << i << endl;
        out << "Title: " << Books.at(i).name << endl;
        out << "Author: " << Books.at(i).author << endl;
        out << "Genre: " << Books.at(i).genre << endl;
        out << "Description: " << Books.at(i).description << endl;
        out << "Length: " << Books.at(i).length << endl;
        if(Books.at(i).availability == true){
            out << "Availability: it is on the shelf" << endl;
        } else if(Books.at(i).availability == false){
            out << "Availability: it is NOT on the shelf" << endl;
        }
        if(Books.at(i).shelved == true){
            out << "Availability: it is in the archive" << endl;
        } else if(Books.at(i).shelved == false){
            out << "Availability: it is NOT in the archive" << endl;
        }
        out << "Maturity: " << Books.at(i).maturity << endl;
    }
	f.write(Books);
}

void Admin::newDay(string name){
    //decrease the days of the books by 1 when its being rented out
    FileManager f;
    vector<Book> borrowed = f.readUser(name); 
    for (int i = 0; i < borrowed.size(); i++){
        borrowed.at(i).rentalPeriod = borrowed.at(i).rentalPeriod - 1;
    }  
    f.writeUser(borrowed, name);
    
}

void Admin::lookUser(string n) {
     //looks for the user
     FileManager f;
     vector<Book> books = f.readUser(n); 
	cout << endl << n << "'s Books" <<endl;
       for(int i = 0; i < books.size(); i++){
            cout << "ID: " << i << endl;
            cout << "Title: " << books.at(i).name << endl;
            cout << "Author: " << books.at(i).author << endl;
            cout << "Rental period: " << books.at(i).rentalPeriod << endl;
        }

}

string Admin::getMessage(string n) const{
     FileManager f;
     string msg;
     vector<Book> books = f.readUser(n);
       for(int i = 0; i < books.size(); i++){
            msg +=  "ID: " +  to_string(books.at(i).id) + "\nTitle: " + books.at(i).name + "\nAuthor: " + books.at(i).author + "\nRental period: " + to_string(books.at(i).rentalPeriod);
        }
     return msg;

}
