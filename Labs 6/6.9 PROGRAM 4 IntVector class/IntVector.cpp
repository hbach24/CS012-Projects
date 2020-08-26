#include <iostream>
#include "IntVector.h"
#include <stdexcept>

using namespace std;

// This function should set both the size and capacity of the
// IntVector to 0 and will not allocate any memory to store integers.
// (Make sure you do not have a dangling pointer.)
IntVector::IntVector() {
    sz = 0;
    cap = 0;
    data = nullptr;
}

// Sets both the size and capacity of the IntVector to the value of the 
// parameter passed in and dynamically allocates an array of that size as well.
// This function should initialize all elements of the array to the value of
// the 2nd parameter.
IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[size];
    
    for(unsigned int i = 0; i < size; i++) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
    delete []data;
}

// This function returns the current size (not the capacity) of the IntVector 
// object, which is the values stored in the sz data field.
unsigned IntVector::size() const {
    return sz;
}

// This function returns the current capacity (not the size) of the IntVector object, 
// which is the value stored in the cap data field.
unsigned IntVector::capacity() const {
    return cap;
}

//Returns whether the IntVector is empty (the sz field is 0).
bool IntVector::empty() const {
    if(sz == 0) {
        return true;
    }
    else
        return false;
}


// This function will return the value stored in the element at the passed in index position. 
// Your function should throw an outofrange exception if an invalid index is passed in.
// An invalid index is an index greater than or equal to the size.
const int & IntVector::at(unsigned index) const {
    if(index < 0 || index >= sz) {
       throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

//This function will return the value stored in the first element.
const int & IntVector::front() const {
    return data[0];   
}

//This function will return the value stored in the last element.
const int & IntVector::back() const {
    return data[sz-1];
}

// This function will double the capacity of the vector. This function should reallocate memory for the dynamically allocated array and update the value of capacity. Make sure your expand() function properly handles the case when capacity is 0 before calling expand(). This will be a special case within the expand() function. **MAKE SURE THERE ARE NO MEMORY LEAKS**
void IntVector::expand() { //used for assign/insert fns
     if(cap == 0) {
        cap = 1;   
    }
    
    else {
        cap *= 2;
    }
    
   int *temp = nullptr;
   temp = data;
    
    data = new int[cap];
    
    for(unsigned i = 0; i < sz; i++) {
        data[i] = temp[i];
    }
}

// This function will expand the capacity of the vector by the amount passed in. 
// This function should reallocate memory for the dynamically allocated array and
// update the value of capacity.
void IntVector::expand(unsigned amount) {
    int *temp = nullptr;
    temp = data;
    cap = cap + amount;
    data = new int[cap];
    
    for(unsigned i = 0; i < sz; i++) {
        data[i] = temp[i];
    }
}

// Size will be increased by 1. If capacity and size are equal when this function is 
// called, capacity must first be doubled and then size must be increased by 1. Also adds
//value to the end of the array.
void IntVector::push_back(int value) {
    if(sz >= cap) { 
        expand();//i tried expand() but that doesn't work either fml 
    }
     sz++;
     data[sz - 1] = value;
}

int & IntVector::back() {
    return data[sz-1];
}

int & IntVector::front() {
    return data[0];
}

int & IntVector::at(unsigned index) {
    if(index < 0 || index >= sz) {
       throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

// This function inserts data at position index. To do this, all values currently at position index and greater are shifted to the right by 1 (to the element right after its current position).

// Size will be increased by 1. However, If size will become larger than capacity, this function needs to first double the capacity. In other words, if capacity and size are both 20 when this function is called, this function must first increase the capacity to 40 and then it will be able to increase the size to 21.

// Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you.

// This function should throw an out_of_range exception, passing it the string "IntVector::insert_range_check" if the index is too large. See bottom of specifications for more details on how to throw an exception and how to test that it works properly.
void IntVector::insert(unsigned index, int value) {
      if(cap == 0) {
        expand(1);
    }
   else if(sz == cap) {
        expand();
    }
    sz+= 1;
    
    if(index >= sz || index < 0) {
       throw out_of_range("IntVector::insert_range_check");
    }
    
    if(index == sz) {
        push_back(value);
    }
    
    if(index < sz) {
        for(unsigned i = sz - 1; i > index; i--) {
            at(i) = at(i-1);
        }
        at(index) = value;
    }
}




// This function removes the value at position index and shifts all of the values 
// at positions greater than index to the left by one (to the element right before its current position).
//Size is decreased by 1.
void IntVector::erase(unsigned index) {
    if(index >= sz || index < 0) {
        throw out_of_range("IntVector::erase_range_check");
    }
    
    for(unsigned i = index; i < sz - 1; i++) {
        data[i] = data[i+1];
    }
    sz = sz - 1;
}


// This function just needs to decrease size by 1.
// This function will never thrown an exception. Calling pop_back on an empty vector will cause undefined behavior.
void IntVector::pop_back() {
    sz = sz - 1;
}

//This function reduces the size of the vector to 0.
void IntVector::clear() {
    sz = 0;
}

// If the new value of size will be larger than capacity, then the capacity must first be expanded by either doubling (expand()) or by increasing the capacity by a specific amount (expand(size - cap)), whichever results in the largest capacity. Then, this function can then increase the size appropriately.
void IntVector::resize(unsigned size, int value) {
    if(size > cap) { // size = 30 cap = 10;
        if(size > cap * 2) {
            expand(size - cap);
        }
        else
            expand();
    }
    
    if(size < sz) {
        sz = size;
    }
    else if(size > sz) {
        int temp = sz;
        sz = size;
        for(unsigned i = temp; i < size; i++) {
            at(i) = value;
        }
}
}

// This function requests that the capacity (the size of the dynamically allocated array)
// be set to n at minimum. This informs the vector of a planned increase in size.

// This function should NOT ever reduce the size of the vector. If n is larger than the 
// current capacity then the capacity should be expanded to n.

// A call to this function never affects the elements contained in the vector, nor the vector's size.
void IntVector::reserve(unsigned n) {
    if(n > cap) {
        cap = n;
    }
  
}



void IntVector::assign(unsigned n, int value) {
    delete [] data;
    data = new int[n];
    sz = n;
    
    if(n > cap) {
        if(sz > cap * 2) {
            expand(n - cap);
        }
        else
            expand();
    }
    
    for(unsigned i = 0; i < sz; i++) {
        data[i] = value;
    }
}

//--------------------------------------------------------//
void IntVector::display() {
    for(unsigned i = 0; i < sz; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}