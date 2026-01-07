#ifndef BOOKSEARCH_HPP
#define BOOKSEARCH_HPP

#include <string>

using namespace std;

class BookSearch{
    
    public:
        ~BookSearch(){};

        virtual void displayBooks() = 0;
        virtual void addBook() = 0;
        virtual void removeBook() = 0;
        virtual void lookUser(string n) = 0;

};
#endif

