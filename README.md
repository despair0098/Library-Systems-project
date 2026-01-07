# Library System project
 
Authors: [Zijun Wang](https://github.com/despair0098), [Garrick Chiu](https://github.com/YanaWanas), [Harsh Patel](https://github.com/hp6164), [Raeed Shaikh](https://github.com/raeeedeer)
 
## Project Description
This is important to us because it is something that can challenge us to be better programmers. We thought that creating a library system would both test our previous knowledge and allow us to learn more about the intricacies of computer science. The experience working on a project like this would be helpful for us to apply this newfound knowledge and skill to the real world. We found that an assignment relating to the account systems would be interesting because this kind of structure is used everywhere in the world.

We are going to use C++ because it is a language that we all have in common. C++ is a language that we have been using for a few years including the experience we gained in UCR CS classes. We will be using VSCode or Visual Studio community as our IDE. We will also be using git for version control and GitHub for hosting the remote repository. C++ is one of the most used languages in the industry so we want to get more familiar with it and learn more about it, especially in a project scenario.

The input would be the keyboard inputs by the users, typing the username and password. The output would have some kind of a window that shows book lists, and other features. Features that the project would provide would be allowing the user to create an account where users can borrow books and display books that are available in the library. The administrators of this system would also have the ability to edit/add/remove any kind of books from the library system.


## Class Diagram
Our UML Diagram:https://lucid.app/lucidchart/0a25c338-e080-4661-af16-15381fa8fc73/edit?invitationId=inv_593feb96-0a62-44b1-bd41-3aca5d2978fa&page=0_0#

![Library System UML (1)](https://user-images.githubusercontent.com/22960474/144116940-67f1dd4a-5a7a-4a0f-80a9-edc02b708a69.jpeg)

The Account class is our abstract parent class. It provides a basic account structure for all admin and user accounts. It has variables username, password, account balance, and a vector containing all books that are currently borrowed under the account. The class has member functions display books, login, logout, and show balance.
We have a main file, where it is going to be the menu for the program, serving as the user interface. It will have access to Account class and Filereader with their respective child classes.

For the user class, this will be the normal account for the people to use. In this class, there will be a display books function that will show all of the books on the shelf not on the archive to the user. As a user, there will also be a function where you will be able to borrow books by getting the ID of the book, and also be able to see how many books you have borrowed. The last function in the user class will allow the user to return the books they have borrowed.

In the admin class, this will be the account for admins only so normal people should not have access to this. Within the admin class, you will be able to add a book, with the ID and name of the book. Using the book’s ID, you can also remove or edit any book within the system. Similar to the user class, you will be able to display all the books, but also include the archived books with the display books function. To track every user’s account and their rental period, there will be a new day function that will subtract by 1 every day until the user’s book is due. There will also be a look user function that will allow the admin to look up any user account, and see their rented books.

The book search class will be aggregated to the account class and manager, and it will search the books when the Admin and User wants the books to be displayed.

The Book struct maintains and holds all variables and attributes relevant to each book. Each book has the member variables name, genre, description, length, rental period, availability, and ID. The rental period will be a constant among all books. Genre is categorical but the rest are unique to every book. Both the user and admin classes will be able to access different attributes of the book class.

The FileManager inherits from account class. This class will read and write files into and out of linked lists.

Strategy Pattern: We picked this pattern because we needed different algorithms for each user’s displayBooks(). Since we implemented this pattern, it allows the admin to have the same function name but different content on its respective displayBooks(). Admin can see shelved books which the User cannot see those books. 

Iterator pattern: We picked this pattern because we needed a way to create and store user account logins, and have that data be passable so that it can be used by User and Admin. This allowed us to input usernames, passwords, ages from FileManager and insert into 3 iterators. 
 
 ## Screenshots
![SS1](https://user-images.githubusercontent.com/22960474/144117097-3e479c7b-5031-497b-a8e9-ebfa2496e249.jpg)
![SS2](https://user-images.githubusercontent.com/22960474/144117107-4b77cddb-33de-4a4e-a746-9f03d1cd2451.jpg)
 ## Installation/Usage
1. git clone –recursive <repo>
2. cmake3 .
3. make
4.  ./test
5. The menu would show up and type the number you want to do.
6. To create a user account, type 3.
7. Type your username, password, and your age. 
8. To login to your user account, type 2. 
9. Type your account’s username and password. 
10. The menu would show up and type the number corresponding to the option. 
11. Type 1 to show all of the books that users can see. 
12. Type 2  to show the list of the books that the user is borrowing. 
13. Type 3 to borrow the book.
14. Type 4 to return the borrowed book.
15. Type 5 to delete this user account. 
16. You can quit the user menu by typing 6. 
17. To login to the admin account, type 1. 
18. Type the account’s username and password. 
19. The menu would show up and type the number for one of the options. 
20. To add the book, type 1 and put the information about the book such as the title and author name. 
21. To remove the book, type 2 and put the ID of the book in the terminal. 
22. To edit the certain book’s information, type 3 and put the ID of the book in the terminal. 
23. It will show a menu about what you want to change and type the corresponding number for the fields. 
24. To show the list of the books, type 4. It will show all of the books on the shelf and in the archive to the admin. 
25. To decrease the rental period of the books that have been borrowed out, type 5 and that can decrease the period. 
26. To look up the user’s list of borrowed books, type 6 and it will print out the list of borrowed books of a specific user you want to see. 
27. You can quit the admin menu by typing 7. 
28. To quit from the program itself, type 4. 

 ## Testing
We have tested our program by every function using unit tests and integration testing.
 
