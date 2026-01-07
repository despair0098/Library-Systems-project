#ifndef USERE_HPP
#define USERE_HPP
#include <iostream> 
#include <string> 
#include "Account.hpp"
#include "user.hpp" 

using namespace std; 

class UserE
{
	public: 
	string message;
        void displayBooks(){
 	for (int i = 0; i < Books.size(); i++){
                if(Books.at(i).availabilty && Books.at(i).maturity == 'E'){
                   cout << Books.at(i).name << " ";
                  }
	}
};	

#endif USERE_HPP
	  
