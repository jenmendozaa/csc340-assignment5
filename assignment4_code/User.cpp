// TO DO: #include needed standard libraries and your own libraries here

#include "User.h" // implementing the User.h
#include <iostream> // included for input and output operations

// TO DO: function implementations // implemented the constructor
User::User(const std::string & userName, const std::string & emailAdd, const std::string & pass, const std::string & userBio, const std::string & profilePic)
    : username(userName), email(emailAdd), password(pass), bio(userBio), profilePicture(profilePic) {}


// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
    return (User::username == otherUser.username) && (User::email == otherUser.email);
}
