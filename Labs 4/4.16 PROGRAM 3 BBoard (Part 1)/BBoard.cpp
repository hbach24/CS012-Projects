#include <iostream>
#include <fstream>
#include "BBoard.h"
#include <vector>
#include <string>

using namespace std;

/* Constructs a board with a default title, 
     * empty user & message lists, 
     * and the "default" User
     */
BBoard::BBoard() {
    title = "";
}

 /* Same as the default constructor except 
     * it sets the title of the board
     */
BBoard::BBoard(const string& t) {
    title = t; 
}

 /* Imports all the authorized users from an input file, 
     * storing them as User objects in the vector userList
     * The name of the input file is passed in as a parameter to this function.
     * Returns true if the file opened, false if it did not. 
     * See specifications for file format.
     */
bool BBoard::loadUsers(const string& userFile) {
    ifstream inFS;
    string user;
    string pass;
    User temp;
    // vector<User> userList;
    
    inFS.open(userFile);
    
    if(!inFS.is_open()) {
        return false;
    }
    
    
    
    while(inFS >> user >> pass) {
        if(user != "end") {
            temp = User(user, pass);
            userList.push_back(temp);
            
        }
    }
    inFS.close();
    return true;
}

// bool BBoard::userExists(const string & user, const string& pass) const {
//     User curr;
//      for(unsigned int i = 0; i < userList.size(); i++) {
//             curr = userList.at(i);
//             if(curr.check(user, pass)) {
//                 return true;
//             }
    
// }
//     return false;
// }

 /* Asks for and validates a user/password.
     * Always asks for both user and password combo unless 'q' or 'Q' entered.
     * Checks userList to validate user and password.
     * If valid, sets currentUser to this User, outputs welcome message, 
     * then returns true.
     * Otherwise outputs error message and then repeats request
     * for username/password.
     * Continues until valid user/password 
     * or until 'q' or 'Q' is entered for username.
     * If 'q' or 'Q' is entered, does not ask for password, outputs "Bye!"
     * and then returns false.
     */
bool BBoard::login() {
    User curr;
    string user;
    string pass;
    
    cout << "Welcome to CS12 Bulletin Board" << endl;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> user;
    cout << endl; 

    while(user != "Q" && user != "q") {
        cout << "Enter your password: ";
        cin >> pass;
        cout << endl;
        for(unsigned int i = 0; i < userList.size(); i++) {
            curr = userList.at(i);
            if(curr.check(user, pass)) {
                currentUser = User(user, pass);
                cout << "Welcome back " << currentUser.getUsername() << "!" << endl;
                cout << endl;
            
                return true;
              
            }
        }
            cout << "Invalid Username or Password!";
            cout << endl;
            cout << endl;
            cout << "Enter your username ('Q' or 'q' to quit): ";
            cin >> user;
            cout << endl;
        }
                cout << "Bye!" << endl;
                return false;
}

/* Contains main loop of Bulletin Board.
     * First verifies a User has been logged in before calling this function.
     * (Do not call login function within this function.)
     * Returns from **function** immediately if no User logged in (Default User).
     * Continues to display menu options to user and performs requested action
     * until user chooses to quit.
     * See output samples for exact format of menu.
     */
void BBoard::run() {
    char action;
   
    cout << "Menu" << endl;
    cout << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Message ('N' or 'n')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl;
    cout << "Choose an action: ";
    cin >> action;
    cout << endl;
   // cout << endl;
       
    while(action != 'Q' && action != 'q') {
        if(action == 'n' || action == 'N') {
            addMessage();

        }
        if(action == 'd' || action == 'D') {
            display();
        }

    cout << "Menu" << endl;
    cout << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Message ('N' or 'n')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl;
    cout << "Choose an action: ";
    cin >> action;
    cout << endl;
    if(action == 'Q' || action == 'q') {
        cout << "Bye!" << endl;
    }
       
    }
   
}




void BBoard::addMessage() {
    string tempMessage;
    string tempSubject;
    string tempBody;
    string name;
  
    
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, tempSubject);
    cout << endl;
    
    cout << "Enter Body: ";
    getline(cin, tempBody);
    cout << endl;
        
    name = currentUser.getUsername();
    messageList.push_back(Message(name, tempSubject, tempBody));
    
    cout << "Message Recorded!" << endl;
    cout << endl;

}

void BBoard::display() const {
    
    
    if(messageList.size() == 0) {
        cout << "Nothing to Display." << endl;
        cout << endl;
    }
    if(messageList.size() != 0) {
    for(unsigned int i = 0; i < messageList.size(); i++) {
        cout << "---------------------------------------------------------" << endl;
        cout << "Message #" << i + 1 << ": ";
        messageList.at(i).display();
        //cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    }
}

