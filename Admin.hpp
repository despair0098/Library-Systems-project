#ifndef __ADMIN__HPP__
#define __ADMIN__HPP__

#include <iostream>
#include <string>
#include "BookSearch.hpp"
#include "Account.hpp"
#include "filemanager.hpp"

using namespace std;

class Admin: public BookSearch, public Account{
    public:
        void addBook();
        void removeBook();
        void editBook();
        void displayBooks();
	void displayBooks(ostream& o);
        void newDay(string name);
        void lookUser(string n);
	string getMessage(string n) const;
        
};
#endif
