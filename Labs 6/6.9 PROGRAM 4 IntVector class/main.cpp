#include <iostream>
#include "IntVector.h"

using namespace std;

int main () {
    int size;
    int value;
    
    cout << "Enter array size: ";
    cin >> size;
    
    cout << "Enter value to initialize array: ";
    cin >> value;
    
    IntVector test(size, value);

     cout << "Size of array: " << test.size() << endl;
     cout << "Capacity of array: " << test.capacity() << endl;
    
     if(test.empty()) {
         cout << "Empty array" << endl;
     }
     else {
         cout << "Array not empty" << endl;
     }
    

    
    cout << "Second element of array: " << test.at(1) << endl;
    
    cout << "First element of array: " << test.front() << endl;
    cout << "Last element of array: " << test.back() << endl;
    test.display();
    
    cout << "testing insert() function: ";
    test.insert(1, 7);
    test.display();
    
     test.display();
     cout << "at function test: ";
     cout << test.at(100) << endl;
    
     cout << "Testing erase function: ";
     test.erase(1);
     cout << endl;
     test.display();
     cout << endl;
     cout << "size after erase(): " << test.size() << "size should decrease by 1" << endl;
    
     cout << "Testing size < sz: ";
     test.resize(3, 2);
     test.display();
     cout<< endl;
    
    cout << "Testing size > sz: ";
    test.resize(8, 2);
    test.display();
    
    
    test.display();
    cout << "add element ";
    test.push_back(1);
    test.display();
    cout << endl;
    cout << test.capacity();
    
    cout << "before assign() called: " << endl;
    test.display();
    cout << "testing assign() function: " << endl;
    test.assign(8, 9);
    test.display(); 
    
    cout << "testing reserve(): ";
    cout << endl;
    cout << "capacity before reserve(): ";
    cout << test.capacity();
    cout << endl;
    cout << "capacity after reserve(): ";
    test.reserve(5);
    cout << test.capacity(); 
    
    cout << "size before pop_back() is called: ";
    cout << test.size() << endl;
    test.pop_back();
    cout << "size after pop_back is called: ";
    cout << test.size();
    cout << endl;
    
    cout << "size before clear() is called: ";
    cout << test.size() << endl;
    test.clear();
    cout << "size should be 0 after clear() is called: ";
    cout << test.size() << endl;

    

    

    
}