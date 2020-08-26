#include <iostream>
#include "IntList.h"
//CS012 PROGRAM 5

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
        return;
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

/*A global friend function that outputs to the stream all of
the integer values within the list on a single line, each 
separated by a space. This function does NOT send to the 
stream a newline or space at the end.
*/
ostream & operator<<(ostream& out, const IntList& rhs) {
    for(IntNode *currNode = rhs.head; currNode != nullptr; currNode = currNode -> next) {
        
        if(currNode == rhs.tail) {
            out << currNode -> data;
        }
        else 
            out << currNode -> data << " ";
}
   return out;

}

//----------------------------------------------------------------------------------------------------------
//the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy) {
     //clear();
    head = nullptr;
    tail = nullptr;

    if(cpy.head == nullptr) {
        return;
    }
    else {

//         head = nullptr;
//     tail = nullptr;
        for(IntNode *currNode = cpy.head; currNode != nullptr; currNode = currNode -> next) {
            push_back(currNode -> data);
            //return;
        }
          }
       }

IntList &IntList::operator=(const IntList &rhs) {
    
    if(rhs.head == nullptr) { //if rhs is empty
         head = nullptr; //if rhs is empty, set head = nullptr so that copy is empty too
     }
    if(this != &rhs) { //if copy and rhs are not the same, then copy each node from rhs to "this"
        clear();
        head = nullptr; //make sure you set head and tail to nullptr before assigning or else its going to be pointing to nowhere (MEMORY LEAK!!!)
        tail = nullptr;
        
        for(IntNode *cpyNode = rhs.head; cpyNode != nullptr; cpyNode = cpyNode -> next) {
                push_back(cpyNode -> data);
        }
    
}
    return *this;
}

void IntList::push_back(int value) {
    //IntNode *temp = tail;
   // tail -> next = new IntNode(value);
   // tail = new IntNode(value);
    //temp -> next = tail;
    IntNode* newN = new IntNode(value);
    if(empty()) {
        head = newN;
        tail = newN;
    }
    else {
   tail -> next = newN;
   tail = newN;
    }
}

void IntList::clear() {
    for(IntNode* currNode = head; currNode != nullptr; currNode = currNode -> next) {
        pop_front();
    }
}

//  Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already sorted.) This function loops through the list until it finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.

void IntList::insert_ordered(int value) {
    IntNode* insertValue = new IntNode(value);
    if(head == nullptr) {
        push_front(value);
    }
    else if(value < (head->data)) {
        push_front(value);
        
    }
    else if(value >= (tail->data)) {
        push_back(value);
    }
    else {
    for(IntNode *prev = head; prev != tail; prev = prev->next) {
        IntNode *curr = prev -> next;
        if(value <= (curr->data)) {
            prev->next = insertValue;
            insertValue -> next = curr;
            return;
        }
    }
        }
}

void IntList::selection_sort() {
    for(IntNode *i = head; i != nullptr; i = i -> next) {
        IntNode *minLoc = i;
            for(IntNode *j = i -> next; j != nullptr; j = j -> next) {
                if((j->data) < (minLoc -> data)){
                    int temp = j->data;
                    j -> data = i -> data;
                    i -> data = temp;
                }
            }
    } 
}

// Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.

void IntList::remove_duplicates() {
      for (IntNode* i = head; i != nullptr ; i = i->next)
    {
        for (IntNode* j = i; j != nullptr ; j = j->next)
        {
            while (j->next != nullptr && j->next->data == i->data)
            {
                IntNode* temp = j->next;
                j->next = j->next->next;
                if (temp == tail)
                {
                    tail = j;
                }
                delete temp;
            }
        }
    }


}

//    for (IntNode* i = head; i != nullptr ; i = i->next)
//     {
//         for (IntNode* j = i; j != nullptr ; j = j->next)
//         {
//             while (j->next != nullptr && j->next->data == i->data)
//             {
//                 IntNode* temp = j->next;
//                 j->next = j->next->next;
//                 if (temp == tail)
//                 {
//                     tail = j;
//                 }
//                 delete temp;
//             }
//         }
//     }