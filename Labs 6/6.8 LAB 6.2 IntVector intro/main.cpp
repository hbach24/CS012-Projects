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
}