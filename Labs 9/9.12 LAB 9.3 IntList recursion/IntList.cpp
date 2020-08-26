#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

//they should have access to data, *next

//ostream& operator << 
/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream& operator<<(ostream &out, IntNode *node) { //global function, probably uses the friend function
    if(node != nullptr) {
    out << node -> data;
    if(node -> next != nullptr) {
        out << ' ';
    }
    out << node -> next;
    }
    return out;
}

   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
ostream & operator<<(ostream & out, const IntList &rhs) { //friend operator; has no access to head
   if(rhs.head != nullptr) {
        out << rhs.head;
    }
    return out;
}
//they all can access head, data, next

   /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */
bool IntList::exists(int num) const { //public IntList function
    if(this->head != nullptr) {
       return this -> exists(this->head, num);
    }
return false;
}

/* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in.
      Otherwise returns false.
   */
bool IntList::exists(IntNode *node, int num) const { //private IntList function CODE SEEMS TO ONLY BE TESTING HEAD RN
    if((node -> data) == num) {
        return true; 
    }
    
    else if((node->next) != nullptr) {
        return exists(node->next, num);
    }
    return false;
}

//   if(curr != nullptr) { //might remove && curr->next != nullptr because it is prob preventing the tail from being printed out
//     //out << curr -> next;
//     out << curr;
//     out << " ";
//     //out << curr -> next; //but curr->next isn't an IntList? so is this calling the other ostream operator b/c this represents an IntNode
// //        return out;
//         curr = curr -> next;
//     }
//     }