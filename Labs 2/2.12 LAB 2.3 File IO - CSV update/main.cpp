#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   inputFile = argv[1];
   outputFile = argv[2];
    
   
   // Create input stream and open input csv file.
    ifstream inFS;
    //string filename;
    //cin >> filename;
    inFS.open(inputFile);
        
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
    if(!inFS.is_open()){
        cout << "Error opening " << inputFile << endl;
        return 1;
    }
    
    int num;
    char ignoreChar;
    string fileStr;
    vector<int> v;
    
    getline(inFS, fileStr); 
    istringstream inSS(fileStr);
    
    for (unsigned int i = 0; i < (fileStr.size() - (fileStr.size() / 2)); ++i) {
        inSS >> num >> ignoreChar;
        v.push_back(num);
    }

   // Close input stream.
    inFS.close();
   
   // Get integer average of all values read in.
    int sum = 0;
    for(unsigned int i = 0; i < v.size(); i++) {
        sum += v.at(i);
    }
   int avg = sum / v.size();
    
   // Convert each value within vector to be the difference between the original value and the average.
    for(unsigned int i = 0; i < v.size(); i++) {
        v.at(i) = v.at(i) - avg;
    }
   
   // Create output stream and open/create output csv file.
    ofstream outFS; 
    outFS.open(outputFile);
    
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
    if(!outFS.is_open()) {
        cout << "Error opening " << outputFile << endl; 
        return 1;
    }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
    for(unsigned int i = 0; i < v.size()-1; i++){
         outFS << v.at(i) << ", ";
    }
    outFS << v.at(v.size()-1);
   // Close output stream.
       outFS.close();
    
   return 0;
}