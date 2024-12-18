// TO DO: #include all the standard libraries and your own libraries here
#include <string> // allows me to use std::string
#include <iostream> // included for input and output operations

#ifndef USER_H
#define USER_H
// To DO: define the class User with the necessary functions and data fields
class User { // defining the class User

private: // creating Data needed Data Members for our User
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;

public: // creating constructor to initialize user object
    User(const std::string & userName, const std::string & emailAdd, const std::string & pass, const std::string & userBio, const std::string & profilePic);

    User() : username(""), email(""), password(""), bio(""), profilePicture("") {}

    // creating getter functions for me to be able to access our private data memebres username, email, password, and posts
    std::string getUsername() const { return username;} // allows us to be able to return user username
    std::string getEmail() const { return email;} // allows us to be able to return email

    void displayUser()const {
        std::cout << "Username: " << username << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Bio: " << bio << std::endl;
        std::cout << "Profile Picture: " << profilePicture << std::endl;
    }





    // This is a function that allows you to compare two users based on their username and email address.
    // You may directly include it in your class definition.
    // You don't need to modify it but will have to put it inside your class.
    // Operator == overloading function prototype:
    bool operator==(const User& otherUser) const;

};

#endif


