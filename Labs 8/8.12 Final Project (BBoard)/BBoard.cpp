#include <iostream>
#include <fstream>
#include "BBoard.h"
#include <vector>
#include <string>
#include <sstream>
#include <ostream>

using namespace std;

/* Constructs a board with a default title, 
     * empty user & message lists, 
     * and the "default" User
     */
BBoard::BBoard() {
    title = "";
    currentUser = nullptr;
    
}

 /* Same as the default constructor except 
     * it sets the title of the board
     */
BBoard::BBoard(const string& t) {
    title = t; 
    currentUser = nullptr;
}

BBoard::~BBoard() {
    for(unsigned int i = 0; i < messageList.size(); i++) {
        delete messageList.at(i);
}
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
            addUser(user, pass);
//             temp = User(user, pass);
//             userList.push_back(temp);
        }
    }
    inFS.close();
    
    
    return true;
}

void BBoard::addUser(const string &name, const string &pass) {
    User temp = User(name, pass);
    userList.push_back(temp);
}

/*This function includes the functionality of the old "user_exists" helper:

It traverses the userList, testing for the existence of a User with the given name and password; if this User is NOT found, the function returns nullptr; otherwise it returns a pointer to the identified User

(the statement return &userList.at(i) will work - make sure you understand why!!)

This function may be used by login() to set the currentUser (which is now, obviously, a pointer, not an object).

There must be no other way to set currentUser to anything other than nullptr.

*/
const User * BBoard::getUser(const string &name, const string &pw) const {
    User curr;
    for(unsigned int i = 0; i < userList.size(); i++) {
        curr = userList.at(i);
        if(curr.check(name, pw)) {
            return &userList.at(i);
        }
    }
    return nullptr;
}

 /* This function asks for a username and password, and checks the userList vector for a matching User.

If a match is found, it sets currentUser to the identified User from the list (remember, currentUser is now a pointer, not an actual object).

If not found, it will keep asking until a match is found or the user types: 'q' or 'Q' as the username (you may assume we do not have a member with name 'q' or 'Q')

When the user chooses to quit, say "Bye!" and just return from the login function - meaning that in main(), currentUser will be unchanged from its initial value, which should have been set to nullptr.


     */
void BBoard::login() {
    //currentUser = nullptr;
    string user;
    string pass;
    
    cout << "Welcome to " << title << endl;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> user;
    //cout << endl; 
    
//This function may be used by login() to set the currentUser (which is now, obviously, a pointer, not an object).
//getUser(name, pw)
    
    while(user != "Q" && user != "q") {
        cout << "Enter your password: ";
        cin >> pass;
        //cout << endl;
        
        currentUser = getUser(user, pass);
        
        if(currentUser != nullptr) {
            cout << "\nWelcome back " << currentUser -> getUsername() << "!" << endl << endl;
            return;
        }
        else if(currentUser == nullptr) {
            cout << "Invalid Username or Password!";
            cout << endl;
            cout << endl;
            cout << "Enter your username ('Q' or 'q' to quit): ";
            cin >> user;
            //cout << endl;
        }
              
    }
    
    cout << "Bye!" << endl;
return;
}



/*This function includes the main loop of the BBoard.
If and only if there is a valid currentUser, enter the main loop, displaying the menu items:
Display Messages ('D' or 'd')
Add New Topic('N' or 'n')
Add Reply ('R' or 'r')
Quit ('Q' or 'q')

The user should select one of these menu items, which should then invoke the corresponding method of BBoard; with any other input, the user should be asked to try again.

'Q'/'q' should re-set currentUser to nullptr and then end the run function (return).

Note: if login() did not set a valid currentUser, this function must immediately return without showing the menu - i.e. there must be no way to get around logging in!

     */
void BBoard::run() {
    if(currentUser == nullptr) {
        return;
    }
    char action;
   
    cout << "Menu" << endl;
    cout << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Topic ('N' or 'n')" << endl;
    cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl;
    cout << "Choose an action: ";
    cin >> action;
    //cout << endl;
   // cout << endl;
       
    while(action != 'Q' && action != 'q') {
        if(action == 'n' || action == 'N') {
            addTopic();

        }
        if(action == 'd' || action == 'D') {
            display();
        }
        if(action == 'r' || action == 'R') {
            addReply();
        }

    cout << "Menu" << endl;
    cout << "- Display Messages ('D' or 'd')" << endl;
    cout << "- Add New Topic ('N' or 'n')" << endl;
    cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
    cout << "- Quit ('Q' or 'q')" << endl;
    cout << "Choose an action: ";
    cin >> action;
        
  //  cout << endl;
    if(action == 'Q' || action == 'q') {
        cout << "Bye!" << endl;
//         currentUser = nullptr;
        return;
    }
       
    }
  
}

bool BBoard::loadMessages(const string &datafile) {
    ifstream infs;
    int msgNum;
    string read;
    
    string authr;
    string sjct;
    string bdy;
    int id;
    string msgType; //type of message: reply or topic
    string childID;
    vector<string> childrenID;
    
    infs.open(datafile);
    
    if(!infs.is_open()) {
        return false;
    }

    infs >> msgNum; //the number of messages in File
   // cout << msgNum << endl;
    
    if(msgNum != 0) {
    for(int i = 1; i <= msgNum; i++) {
      //  cout << "msglist size" << messageList.size() << endl;
        authr = "";
        sjct = "";
        bdy = "";
    
         infs >> msgType;
     //    cout << msgType << endl;
         
         infs >> read; // should read in ":id:"
      //   cout << read;
          if(read == ":id:")  {
                 infs >> id;
        //         cout << id << endl;
             }
    
        infs >> read; //reads in ":subject:"
     //   cout << read;
        if(read == ":subject:") {
            infs >> read;
            getline(infs, sjct);
            sjct = read + sjct;
                
            
     //           cout << sjct << endl;
            }
        infs >> read; //reads in ":from:"
         if(read == ":from:") {
      //          cout << read; //":from:"
                infs >> authr;
       //         cout << authr << endl;
            }
    infs >> read; //"reads in :body:" or ":children:"
  //  cout << read;
    
    string t;
    if(read == ":body:") {
        infs >> t;
        getline(infs, read);
        read = t + read;
        
        while(read != "<end>") {
          // cout << "HERE" << read << "HERE" << endl;
            if(read != "<end>") {
//                 bdy += read;
//                 bdy += "\n";
                
                 bdy = bdy + read + "\n";
            }
            getline(infs, read);
        }
        
         //cout << "DIS BODY" << bdy << endl;
        childrenID.push_back("");
    }
    else if (read == ":children:") {
       //while(read != ":body:") {
           getline(infs, childID);
   //       cout << childID << endl; //
           childrenID.push_back(childID);
           infs >> read; //reads in :body:
           //do the body within the children
     //  }
     // cout << read << endl;
        
       string tem;
       if(read  == ":body:") {
        infs >> tem;
        getline(infs, read);
        read = tem + read;
           

        while(read != "<end>") {
///            cout <<"HERE" << read << "HERE" << endl;
            if(read != "<end>") {
//                 bdy += read;
//                 bdy += "\n";
                bdy = bdy + read + "\n";
            }
            getline(infs, read);
       }
       //cout << "DISBODY" << bdy << endl;
      // cout << read << endl;
    }  
    }
//        cout << "DISBODY" << bdy << "ENDBODY"<< endl;
     Topic *top = nullptr;
     Reply *repl = nullptr;
    if(msgType == "<begin_topic>") {
        top = new Topic(authr, sjct, bdy, id);
        messageList.push_back(top);
    }
    else if(msgType == "<begin_reply>") {
        repl = new Reply(authr, sjct, bdy, id);
        messageList.push_back(repl);
     }
//     cout << "messageList size" << messageList.size() << endl;
//     cout << "childrenID size" << childrenID.size() << endl;
//        // infs.close();
  
    }
    }
    infs.close();
    
    string temp;
    int tempID;
  //       cout << "messageList size" << messageList.size() << endl;
   // cout << "childrenID size" << childrenID.size() << endl;
    for(unsigned int i = 0; i < childrenID.size(); i++) {
        temp = childrenID.at(i); // 3 9
        stringstream inSS(temp);

        while(inSS >> tempID) {
         messageList.at(i) -> addChild(messageList.at(tempID - 1));
        }
}
    
    return true;
}

void BBoard::addTopic() {
    string tempMessage;
    string tempSubject;
    string tempBody;
    string name;
    
    string temp;
    
    cout << "Enter Subject: ";
    getline(cin, tempSubject);
    getline(cin, tempSubject);
    //cout << tempSubject;
   // cout << endl;
    
    cout << "Enter Body: ";
//     string garb;
    
//     getline(cin, garb);
    getline(cin, temp);
    
     while(temp != "") {
        tempBody = tempBody + temp + "\n";
         
        getline(cin, temp);
         
    }
   // cout << tempBody;
    
    cout << endl;
        
    name = currentUser -> getUsername();
    
    Topic *top = new Topic(name, tempSubject, tempBody, messageList.size() + 1);
    messageList.push_back(top);
    
    //cout << endl;

}
                  
void BBoard::addReply() {
    int msgID;
    string tempBody;
    string user;
    string subj;
    
    cout << "Enter Message ID (-1 for Menu): ";
    cin >> msgID;
    cout<< endl;
    
    if(msgID > -1) {
    while(msgID >  static_cast<int>(messageList.size())) {
        cout << "Invalid Message ID!!" << endl << endl;
        cout << "Enter Message ID (-1 for Menu): ";
        cin >> msgID;
        cout << endl;
        if(msgID <= -1) {
            return;
        }
    }
    }
    else if(msgID <= -1){
        return;
    }
    
    string garb;
    
    string temp;
    cout << "Body: ";
    getline(cin, garb);
    getline(cin, temp);
    
     while(temp != "") {
        tempBody = tempBody + temp + "\n";
         
        getline(cin, temp);
         
    }
    cout << endl;
    
    user = currentUser -> getUsername();
    
    subj = "Re: " + messageList.at(msgID - 1) -> getSubject();
    Reply *rep = new Reply(user, subj, tempBody, messageList.size() + 1);
    
    messageList.push_back(rep);
    messageList.at(msgID - 1) -> addChild(rep);
}

void BBoard::display() const {
     if(messageList.size() == 0) {
        cout << "\nNothing to Display." << endl << endl;
        return;
    }
cout << endl;
    for(unsigned int i = 0; i < messageList.size(); i++) {
        if(!(messageList.at(i) -> isReply())) {
            cout <<  "---------------------------------------------------------" << endl;
            (messageList.at(i)) -> print(0);
        }
    }
    cout <<  "---------------------------------------------------------" << endl << endl;
    
//         for(unsigned i = 0; i < messageList.size(); i++) {
//     cout << "Message #" << messageList.at(i) -> id << ":" << messageList.at(i) -> subject << endl;
//     cout << "from " << messageList.at(i) ->author << ":" << messageList.at(i) -> body << endl;
//     }

}

/*
It gets a filename (datafile) of a file that will store all of the messages, and after opening the file writes the messages into it with the same format (See File Format Specs).

(Note: Since you will be opening the file for writing - i.e. an ofstream - "file not found" is NOT an error; a new file will simply be created for you).
*/
bool BBoard::saveMessages(const string &file) {
    ofstream out;
    
    out.open(file);
    
    if(!out.is_open()) {
        return false;
    }
    
    out << messageList.size() << endl;
    
    for(unsigned int i = 0; i < messageList.size(); i++) {
        out << messageList.at(i) -> toFormattedString();
    }
    
    out.close();
    
 return true;
 }



