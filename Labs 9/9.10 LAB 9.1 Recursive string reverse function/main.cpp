#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
    string temp = s;
    //int tempSize = s.size();
    if(s.size() <= 1) {
        return;
    }
    else {
        char tempFront = s.front();
        char tempBack = s.back();
        int newSize = s.size()-2;
        
        temp = temp.substr(1, newSize);
        
        flipString(temp);
        s = tempBack + temp;
        s.push_back(tempFront);
    }
}


