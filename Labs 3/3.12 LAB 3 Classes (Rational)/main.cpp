#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here
Rational::Rational(int num, int den) {
    numerator = num;
    denominator = den;
    
}

Rational::Rational(int num) {
    numerator = num;
    denominator = 1;
}

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

int Rational::gcd(int n, int d) const {
    //FIXME GCD 
    int hcf;
    if(d > n) {
        int temp = d;
        d = n;
        n = temp;
    }
     
    for (int i = 1; i <=  d; ++i) {
        if (n % i == 0 && d % i ==0) {
            hcf = i;
        }
    }
    return hcf;
}


const Rational Rational::add(const Rational& r) const {
    Rational x;
    
    x.numerator = (r.numerator * denominator) + (r.denominator * numerator);
    x.denominator = (r.denominator * denominator);
    
    return x;
    

}

const Rational Rational::subtract (const Rational & r) const {
    Rational x;
    //a = r.numerator 
    //b = r.denominator
    //c = numerator
    //d = denominator
    //(a/b) - (c/d) = (ad - bc) / (b*d)
    
    x.numerator = (numerator * r.denominator) - (denominator * r.numerator);
    x.denominator = (r.denominator * denominator);
    
    return x;
}

const Rational Rational::multiply (const Rational & r) const {
    Rational x;
    //a = r.numerator 
    //b = r.denominator
    //c = numerator
    //d = denominator
    //(a/b) * (c/d) = (ac) / (bd)
    
    x.numerator = (r.numerator * numerator);
    x.denominator =  (r.denominator * denominator);
    
    return x;
}

const Rational Rational::divide (const Rational & r) const {
    Rational x;
    //a = r.numerator 
    //b = r.denominator
    //c = numerator
    //d = denominator
    //(a/b) / (c/d) = (ad) / (cb)
    
    x.numerator = (numerator * r.denominator);
    x.denominator =  (r.numerator * denominator);
    
    return x;
}

void Rational::simplify() {
    //The simplify function should divide the numerator and denominator by the greatest common divisor. This function should call the private helper function gcd to get the greatest common divisor. 
    //private helper fn: int gcd(int, int) const;
    Rational x;
    int gcd1 = gcd(numerator, denominator);
    
    numerator = numerator / gcd1;
    denominator = denominator / gcd1;

}

void Rational::display() const {
    //Rational x;
    
    cout << numerator << " / " << denominator;
    
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

