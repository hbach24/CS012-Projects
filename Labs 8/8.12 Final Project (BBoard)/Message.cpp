#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Message.h"

using namespace std;

Message::Message() {
    author = "";
    subject = "";
    body = "";
    id = 0;
} 

Message::Message(const string &athr, const string &sbjct, const string &bdy, unsigned i) { //:author(athr), subject(sbjct), body(bdy), id(i) {}
    author = athr;
    subject = sbjct;
    body = bdy;
    id = i;
}
 //:author(athr), subject(sbjct), body(bdy), id(i){}


const string & Message::getSubject() const {
    return subject;
}

unsigned Message::getID() const {
    return id;
}

void Message::addChild(Message *message) {
    childList.push_back(message);
     
}

Message::~Message() {
//     for(unsigned int i = 0; i < childList.size(); i++) {
//         delete childList.at(i);
//     }
    
}



string Message::toFormattedString() const {
   stringstream out;
     string tempstr;
    
     out << ":id: " << id << endl;
     out << ":subject: " << subject << endl;
     out << ":from: " << author;
    
    if(childList.size() != 0) {
        out << endl;
        out << ":children: ";
        for(unsigned int i = 0; i < childList.size(); i++) {
        out << childList.at(i) -> getID();
            if(i != childList.size() - 1) {
                out << " ";
            }
        }   
    }
   // out << endl;
    out <<  "\n:body: " << body;
    //out << "<end>" << endl;
    
    
   
   
     tempstr = out.str();
     if(tempstr.back() == '\n') {
        //out << "<end>" << endl;
         tempstr = tempstr + "<end>\n";
    }
    else {
        tempstr = tempstr + "\n<end>\n";
//         out << endl; 
//         out << "<end>" << endl;
    }
    
 //   tempstr = out.str();
    
    return tempstr;
    
    
}

/*This function is responsible for printing the Message 
      * (whether Topic or Reply), and all of the Message's 
      * "subtree" recursively:
      * After printing the Message with indentation n and appropriate 
      * format (see output details), it will invoke itself 
      * recursively on all of the Replies in its childList,
      * incrementing the indentation value at each new level.
      *
      * Note: Each indentation increment represents 2 spaces. e.g. if 
      * indentation == 1, the reply should be indented 2 spaces, if 
      * it's 2, indent by 4 spaces, etc.
*/
void Message::print(unsigned n) const {
    string sp;
    stringstream inss(body);
    string temp;
    //getline(inss, word);
    if(n != 0) {
    for(unsigned int i = 0; i < n; i++) {
        sp = sp + "  ";
    }
    }

      cout << sp << "Message #" << this -> id << ": " << this -> subject << endl; 
      cout << sp << "from " << this -> author << ": "; //<< this -> body << endl;
    
    getline(inss, temp);
    cout << temp << endl;
    while(getline(inss, temp)) {
        cout << sp << temp << endl;
    }

    if(n == 0 && childList.size() == 0 ){
        return;
    }
    if(childList.size() != 0) {
        for(unsigned int i = 0; i < childList.size(); i++) {
            cout << endl;
            childList.at(i) -> print(n + 1);
        }
    }
    
}
//         if(n == 0) {
//         cout << "Message #" <<  id << ":" << this -> subject << endl;
//         cout << "from " << this -> author << ":" << this -> body << endl;
// //             for(unsigned int i = 0; i < body.size(); i++) {
// //                 if(body.at(i) == " ") {
// //                     cout << 
// //                 }
// //             }
//         return;
//    }
    
//     cout << "Message #" << this -> id << ":" << this -> subject << endl;
//  //   cout << "from " << this -> author << ":" << this -> body << endl;
    
// //     for(unsigned i = 0; i < body.size(); i++) {
// //         if(body.at(i) == '') {
// //            cout << endl;
// //         }
// //         else if(body.at(i) == ' ') {
// //             cout << " ";
// //         }
// //     }
    
//     if(isReply()) {
//     for(unsigned int i = 0; i < n; i++) {
//         cout << "  ";
//     }
//     } 
        
//     if(childList.size() != 0) {
//         for(unsigned int i = 0; i < childList.size(); i++) {
//             childList.at(i) -> print(n + 1);
//         }
//     }
    
//}
    
//     else if(n )
//     cout << " " << " ";
//     temp = temp + 1;
//     print(temp);
//         Message :: prnt(4);
//     4 indentations
//         _ _ _ _ message
        
        
    
//     if(childList.size()==0) {
//         print topic with no indentation 
//     }

// void Message::print(unsigned indentation) const // New !!
// {
// 	string space;

// 	for (unsigned x = 0; x < indentation; x++)
// 	{
// 		space += "  ";
// 	}
	
// 	if(indentation != 0)
// 		cout << endl;

// 	cout << space << "Message #" << id << ": " << subject << endl;
// 	cout << space << "from " << author << ": ";

// 	for (unsigned y = 0; y < body.size(); y++)
// 	{
// 		cout << body.at(y);
// 		if (body.at(y) == '\n')
// 		{
// 			cout << space;
// 		}
// 	}
// 	cout << endl;

// 	if (childList.size() != 0)
// 	{
// 		for (unsigned z = 0; z < childList.size(); z++)
// 		{
// 			childList.at(z)->print(indentation + 1);
// 		}
// 	}
// }