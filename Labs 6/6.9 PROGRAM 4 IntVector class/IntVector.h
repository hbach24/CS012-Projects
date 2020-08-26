#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <iostream>
using namespace std;

class IntVector {
        
    private: 
        unsigned sz;
        unsigned cap;
        int *data;
                 
        void expand(); //
        void expand(unsigned amount); //
    
    public:
        IntVector();
        IntVector(unsigned size, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
    
        int & at(unsigned index); //
        void insert(unsigned index, int value); //
        void erase(unsigned index); //
        int & front(); //
        int & back(); //
        void assign(unsigned n, int value);
        void push_back(int value); //
        void pop_back(); //
        void clear(); //
        void resize(unsigned size, int value = 0); //
        void reserve(unsigned n);
    
        void display(); //
};

#endif

//TIPS FOR EXPAND() FUNCTION
//make a new array twice the capacity, copy everything from the old array to the new array
//delete old array after copying all the contents of it to the new (double cap) array; change data to point to new array
// we need a new variable/pointer (temp) that can store either one of the two arrays (old or new)
//deleting what they point to 