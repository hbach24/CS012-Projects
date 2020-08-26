#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;


void readData(const string& fileData, vector<double>& angle, vector<double>& lift);
double interpolation(double angleB, const vector<double>& angle, const vector<double>& lift);
bool isOrdered(const vector<double> & angle);
void reorder(vector<double> & angle, vector<double> & lift);


int main(int argc, char *argv[]) {
    string fileData;
    vector<double> angle;
    vector<double> lift;
    double angleB;
    string newInput = "Yes";
    
    fileData = argv[1];
    
    ifstream inFS;     
    
    
    
    readData(fileData, angle, lift);
    
    if (!isOrdered(angle))
    {
    reorder(angle, lift);
    }

    double max = angle.at(angle.size()-1);
    double min = angle.at(0);
    
    cin >> angleB;
    
    if(angleB >= min && angleB <= max) {
        cout << interpolation(angleB, angle, lift);
    }
    
    cin >> newInput; 
    
    while (newInput == "Yes") {
        
        cin >> angleB;
        
    if(angleB >= min && angleB <= max) {
        
        cout << interpolation(angleB, angle, lift);
        
    }
        
        cin >> newInput;
    }
    
    inFS.close();
    
    return 0;
}
/*readData: passes in the name of a file and two vectors (double) and
stores in the first vector the flight-path angles (first column) and 
in the second vector the corresponding coefficients of lift (2nd column).
If the file does not open properly, this function should output an error 
message and then call the exit function passing it an exit value of 1.*/

void readData(const string& fileData, vector<double>& angle, vector<double>& lift) {
    ifstream inFS;
    
    double angleNum;
    
    double liftNum;

    inFS.open(fileData);
    
    if(!inFS.is_open()) {
        cout << "Error opening " << fileData << endl;
        exit(1);
    }
    
    
    while(inFS >> angleNum) {
        inFS >> liftNum;
        angle.push_back(angleNum);
        lift.push_back(liftNum);
    }
    
}

/* isOrdered: passes in the vector of flight-path angles and returns true if
the stored angles are in ascending order, otherwise returns false.*/

bool isOrdered(const vector<double>& angle) {
    if(!angle.empty()) {
        for(unsigned int i = 0; i < angle.size()-1; i++) {
            if(angle.at(i) > angle.at(i+1)) {
                return false;
            }
        }
    }
    return true;
}


void reorder(vector<double>& angle, vector<double>& lift) {
   // int minIndex;
    double temp;
    double temp2;
    
    for (unsigned int i = 0; i < angle.size(); i++) {
        
        for (unsigned int j = i + 1; j < angle.size(); j++) {
            
          if (angle.at(i) > angle.at(j)) {
               //minIndex = j;
         
        /*swap(angle.at(i), angle.at(minIndex));
        swap(lift.at(i), lift.at(minIndex));*/
              
        temp = angle.at(j);
        temp2 = lift.at(j);
                
        angle.at(j) = angle.at(i);
        angle.at(i) = temp;
        
        lift.at(j) = lift.at(i);
        lift.at(i) = temp2;
              
        }
    }
}
    }


/*Interpolation: passes in the requested flight-path angle along
with the 2 vectors of data (flight-path angles and corresponding
coefficients of lift) and returns the corresponding coefficient of lift.*/

double interpolation(double angleB, const vector<double>& angle, const vector<double>& lift) {
    //string newInput = "";
    //cin >> angleB; 
    
    double liftB = 0;
    double returnLift;
   
      //  cin >> angleB;
        
     for (unsigned int i = 0; i < angle.size(); i++) {
        if(angleB == angle.at(i))
            returnLift = lift.at(i);     
}
               
    for(unsigned int i = 0; i < angle.size(); i++) {
        
        if(angleB > angle.at(i)) { 
             
    liftB = lift.at(i) + ((angleB - angle.at(i)) / (angle.at(i+1) - angle.at(i))) * (lift.at(i+1) - lift.at(i));
            
        returnLift = liftB;
           
        }
        
    }
               
 return returnLift;
}

             
             
             
             
             
             
             

// a < b < c
//f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))