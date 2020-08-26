#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}



//void push_front(int value): Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int value) {
    
    
    IntNode* temp = head;
    head = new IntNode(value);
    head -> next = temp;
    
    if(tail == nullptr) {
        tail = head;
    }
}

//Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
void IntList::pop_front() {
    if(empty()) {
    }
    if(head == tail)
    {
        head = nullptr;
        delete tail;
        tail = nullptr;
    }
    
  if(head != nullptr) {
     
         IntNode* temp = head;
         head = head -> next;
//          delete head;
//          head = temp -> next;
      delete temp;
    }
}

IntList::~IntList() {
     IntNode *curr = head;
     while(curr != nullptr) {
         pop_front();
     curr = curr -> next;
     }
}

//bool empty() const: Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
bool IntList::empty() const {
    if(head == nullptr) {
        return true;
    }
    else
        return false;
}

//const int & front() const: Returns a reference to the first value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::front() const {
    return head -> data;
}

//const int & back() const: Returns a reference to the last value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::back() const {
    return tail -> data;
}

// friend ostream & operator<<(ostream &, const IntList &): Overloads the insertion operator (<<) so that it sends to the output stream (ostream) a single line all of the int values stored in the list, each separated by a space. This function does NOT send a newline or space at the end of the line.
ostream & operator<<(ostream& out, const IntList& rhs) {
//    IntNode* currNode = rhs.head;
// //     IntNode* currNodeT = rhs.tail;
//      while (currNode != nullptr)
//     {
//         out << currNode->data; 
//         currNode = currNode->next;

//         if(currNode != nullptr) {
//             out << ". ";
//         }       
//     }
    
//     return out; 

    for(IntNode *currNode = rhs.head; currNode != nullptr; currNode = currNode -> next) {
        
        if(currNode == rhs.tail) {
            out << currNode -> data;
        }
        else 
            out << currNode -> data << " ";
}
   return out;
}