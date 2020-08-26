// Don't forget inclusion guard
#include <string>
#include "User.h"

using namespace std;

User::User() {
    username = "";
    password = "";
}

// creates a user with given username and password.
User::User(const string& uname, const string& pass) {
    username = uname;
    password = pass;
}

string User::getUsername() const {
    return username;
}

  /* returns true if the stored username/password matches with the
   * parameters. Otherwise returns false.
   * Note that, even though a User with empty name and password is 
   * actually a valid User object (it is the default User), this 
   * function must still return false if given a empty uname string.
   */
bool User::check(const string &uname, const string &pass) const {
    if(uname.size() == 0) {
        return false;
    }
    else if(username == uname && password == pass) {
        return true;
    }
    else 
        return false;
    
}

 /* sets a new password.
   * This function should only set the new password if the current (old) 
   * password is passed in. Also, a default User cannot have its 
   * password changed. 
   * returns true if password changed, false if not.
   */
bool User::setPassword(const string &oldpass, const string &newpass) {
    
    if(password == "") {
        return false;
    }
    else if (oldpass == password) {
        password = newpass;
        return true;
    }
    else 
        return false;
//     if(username.size() == 0) {
//         password = password;
//     }
//     else if(password = oldpass) {
//        password = newpass;
//    }
  
//     if(password != tempPass) {
//         return true;
//     }
//     else
//         return false;
}