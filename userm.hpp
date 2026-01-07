#ifndef USERM_HPP
#define USERM_HPP
#include <iostream> 
#include <string> 
#include "Account.hpp"
#include "user.hpp" 

using namespace std; 

class UserM
{
	public: 
	string message;
        void displayBooks(){
 	for (int i = 0; i < Books.size(); i++){
                if(Books.at(i).availabilty){
                   cout << Books.at(i).name << " ";
                  }
	}
};	

#endif USERM_HPP
	  
