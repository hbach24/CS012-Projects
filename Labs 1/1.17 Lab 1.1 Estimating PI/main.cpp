// This program implements the Monte Carlo Method for estimating the value of PI.

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// given the coordinates of a point (x,y) computes if the point is inside or on the circle 
// centered at origin with radius r. Returns 'true' if it is inside or on the circle, 'false' otherwise.
// DO NOT use the sqrt function here. Just compare to r squared.
bool isInside(double x, double y, double r) {
    double eq = pow(x, 2) + pow(y, 2);
    if (eq == pow(r, 2) || eq < pow(r, 2)) {
        return true;
    }
    else
        return false;
}

// given s, the size of the side of a square that is centered at the origin, 
// chooses a random coordinates inside the square, and calls isInside function 
// to test if the point is inside the circle or not.
bool throwDart(int s) {
    int x, y;
    // assign x and y to two random integers between -s/2 and s/2 
    x = rand() % (s + 1) - (s / 2); //rand() % ((s/2) - (-s/2) + 1)) - (s/2) <-- rand() % (max-min+1) + min
    y = rand() % (s + 1) - (s / 2);
    //Call the isInside function and return its output. 
    if (isInside(x, y, (s / 2))) {
        return true;
    }
    else
        return false;
    //You do not have to cast x & y to doubles, it is done automatically.

}

int main() {
    srand(333);
    int side; // this is the side of the square and is also our resolution. 
    int tries;  // this is the number of tries.

    //Ask the user for the size (integer) of a side of the square
    cin >> side;
    //Get the users input using cin

    //Ask the user for the number of tries using cout.
    //cout << "Number of tries: ";
    cin >> tries;
    //Get the users input using cin.


    int inCount = 0; //counter to track number of throws that fall inside the circle

    for (int i = 0; i < tries; ++i) {
        //throw a dart using throwDart method and increment the counter depending on its output.
        if (throwDart(side))
            inCount++;
    }

    /* int inCountSquare = 0;
     for(int i = 0; i < tries; ++i) {
        //throw a dart using throwDart method and increment the counter depending on its output.
       if(!throwDart(side))
        inCountSquare++;
     }*/

     //Compute and display the estimated value of PI. Make sure you are not using integer division.
    double pi;
    pi = 4.0 * (inCount) / (tries);   //double(inCountSquare + inCount));
    cout << pi << endl;
    return 0;
}