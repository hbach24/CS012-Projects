#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(const string& filename);

int main() {
   ifstream inFS;
   string filename;
   int sum = 0;
   
    
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;

   
   sum = fileSum(filename);
    
   inFS.open(filename);
        
   if(inFS.is_open())
   {
   cout << "Sum: " << sum << endl;
   }
   
   return 0;
}

// Place fileSum implementation here
int fileSum(const string& filename) {
    ifstream inFS;
    int sum1 = 0;
    int fileNum;
    
    inFS.open(filename);

    if(!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        return 1; // 1 indicates error
   }
    
  //  int sum1 = 0;
    while(!inFS.eof()) {
        inFS >> fileNum;
        if(!inFS.fail()) {
            sum1 += fileNum;
        }
    }
    
    inFS.close();
    return sum1;

   // return sum1;
}