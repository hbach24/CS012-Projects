#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();    
   Date(unsigned m, unsigned d, unsigned y);
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const; //*


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const; //*

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const; //*

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const; //*
};


// Implement the Date member functions here
Date::Date() {
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y) {
     /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
    year = y;
  
  if(m > 12) //**
  {
      month = 12;
      //cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
  }
  else if(m == 0) //***
  {
      month = 1;
  }
  else if(m <= 12) 
  {
      month = m;
  }

    
   if(d == 0)
  {
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
      
  }  
  else if(m > 12 && d <= 31) {
        month = 12;
        day = d;
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        
    }
  else if(m == 0 && d <= 31)
  {
      month = 1;
      day = d;
      cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
  }
      
  else if(month == 2 && (d == 28 || d == 29)) 
  {
      year = y;
      if(d == 28 && isLeap(y)) {
            day = 29;
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
        else if (d == 29 && isLeap(y) == false) {
            day = 28;
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
  }
  else if(d > 31)
  {
      
      if(month == 4 || month == 6 || month == 9 || month == 11)
           {
           day = daysPerMonth(month, year);
           cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
           }
           
        else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
           {
            day = daysPerMonth(month, year);
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
           }
      
  }
  
  else if(month <= 12 && d <= 31)
  {
      if((d == 31) && (month == 4 || month == 6 || month == 9 || month == 11))
           {
           day = daysPerMonth(month, year);
           cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
           }
           
        else if((d == 30) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
           {
            day = daysPerMonth(month, year);
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
           }
      else
          day = d;
  }
    
   
}


Date::Date(const string &mn, unsigned d, unsigned y) {
   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
    //int monthNum;
    if((d == 0) && (mn == "January" || mn == "February" || mn == "March" || mn == "April" || mn == "May" || mn == "June" || mn == "July" || mn == "August" || mn == "October" || mn == "September" || mn == "November" || mn == "December")) 
    {
        monthName = mn;
        month = number(monthName);
        day = 1;
        year = y;
        
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }
    
    else if ((d == 0) && (mn == "january" || mn == "february" || mn == "march" || mn == "april" || mn == "may" || mn == "june" || mn == "july" || mn == "august" || mn == "october" || mn == "september" || mn == "november" || mn == "december")) 
    {
        monthName = mn;
        month = number(monthName);
        day = 1;
        year = y;
        
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }
    
    else if ((d == 29 || d == 28) && (mn == "february" || mn == "February")) 
    {
        year = y;
        monthName = mn;
        month = number(monthName);
        day = daysPerMonth(month, year);
        
        if(d == 29 && isLeap(year) == false) {
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
        else if(d == 28 && isLeap(year) == true) {
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        }
        
    }
    
    else if((d > 31) && (mn == "January" || mn == "February" || mn == "March" || mn == "April" || mn == "May" || mn == "June" || mn == "July" || mn == "August" || mn == "October" || mn == "September" || mn == "November" || mn == "December"))
    {
        year = y;
        monthName = mn;
        month = number(monthName);
        day = daysPerMonth(month, year);
        
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }
    
    else if((d > 31) && (mn == "january" || mn == "february" || mn == "march" || mn == "april" || mn == "may" || mn == "june" || mn == "july" || mn == "august" || mn == "october" || mn == "september" || mn == "november" || mn == "december"))
    {
        year = y;
        monthName = mn;
        month = number(monthName);
        day = daysPerMonth(month, year);
        
        cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
    }

    else if ((d == 31 || d == 30) && (mn == "January" || mn == "February" || mn == "March" || mn == "April" || mn == "May" || mn == "June" || mn == "July" || mn == "August" || mn == "October" || mn == "September" || mn == "November" || mn == "December")) {
    
        year = y;
        monthName = mn;
        month = number(monthName);
        day = daysPerMonth(month, year);
        
        if((d == 31) && (mn == "April" || mn == "June" || mn == "September" || mn == "November"))
           {
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
           }
           
        else if((d == 30) && (mn == "January" || mn == "March" || mn == "May" || mn == "July" || mn == "August" || mn == "October" || mn == "December"))
           {
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        
           }
}
    
    
    else if ((d == 31 || d == 30) && (mn == "january" || mn == "february" || mn == "march" || mn == "april" || mn == "may" || mn == "june" || mn == "july" || mn == "august" || mn == "october" || mn == "september" || mn == "november" || mn == "december"))
    {
        year = y;
        monthName = mn;
        month = number(monthName);
        day = daysPerMonth(month, year);
        
        if((d == 31) && (mn == "april" || mn == "june" || mn == "september" || mn == "november"))
           {
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
           }
           
        else if((d == 30) && (mn == "january" || mn == "march" || mn == "may" || mn == "july" || mn == "august" || mn == "october" || mn == "december"))
           {
            cout << "Invalid date values: Date corrected to " << month << '/' << day << '/' << year << '.' << endl;
        
           }
    }
    
    
    else if((d < 30) && (mn == "january" || mn == "february" || mn == "march" || mn == "april" || mn == "may" || mn == "june" || mn == "july" || mn == "august" || mn == "october" || mn == "september" || mn == "november" || mn == "december")) 
    {
        year = y;
        monthName = mn;
        month = number(monthName);
        day = d;
        
    }
    
     else if((d < 30) && (mn == "January" || mn == "February" || mn == "March" || mn == "April" || mn == "May" || mn == "June" || mn == "July" || mn == "August" || mn == "October" || mn == "September" || mn == "November" || mn == "December")) 
    {
        year = y;
        monthName = mn;
        month = number(monthName);
        day = d;
        
    }
    else
    {
        year = 2000;
        month = 1;
        monthName = "January";
        day = 1;
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
    }
             
}

string Date::name(unsigned m) const {
 /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
    string monthName1;
    
     if(m == 1) {
        monthName1 ="January";
    }
    else if (m == 2) {
        monthName1 = "February";
    }
    else if (m == 3) {
        monthName1 = "March";
    }
    else if (m == 4) {
        monthName1 = "April" ;
    }
    else if (m == 5) {
        monthName1 = "May";
    }
    else if (m == 6) {
        monthName1 = "June";
    }
    else if (m == 7) {
        monthName1 = "July";
    }
    else if (m == 8) {
        monthName1 = "August";
    }
    else if (m == 9) {
        monthName1 = "September" ;
    }
    else if (m == 10) {
        monthName1 = "October";
    }
    else if (m == 11) {
        monthName1 = "November";
    }
    else if (m == 12) {
        monthName1 = "December";
    }
    return monthName1;
}

 /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
unsigned Date::number(const string &mn) const {
    int day1;
    
     if(mn == "January") {
        day1 = 1;
    }
    else if (mn == "February") {
        day1 = 2 ;
    }
    else if (mn == "March") {
        day1 = 3;
    }
    else if (mn == "April") {
        day1 = 4;
    }
    else if (mn == "May") {
        day1 = 5;
    }
    else if (mn == "June") {
        day1 = 6;
    }
    else if (mn == "July") {
        day1 = 7;
    }
    else if (mn == "August") {
        day1 = 8;
    }
    else if (mn == "September") {
        day1 = 9;
    }
    else if (mn == "October") {
        day1 = 10;
    }
    else if (mn == "November") {
        day1 = 11;
    }
    else if (mn == "December") {
        day1 = 12;
    }
    //LOWERCASE
    else if(mn == "january") {
        day1 = 1;
    }
    else if (mn == "february") {
        day1 = 2 ;
    }
    else if (mn == "march") {
        day1 = 3;
    }
    else if (mn == "april") {
        day1 = 4;
    }
    else if (mn == "may") {
        day1 = 5;
    }
    else if (mn == "june") {
        day1 = 6;
    }
    else if (mn == "july") {
        day1 = 7;
    }
    else if (mn == "august") {
        day1 = 8;
    }
    else if (mn == "september") {
        day1 = 9;
    }
    else if (mn == "october") {
        day1 = 10;
    }
    else if (mn == "november") {
        day1 = 11;
    }
    else if (mn == "december") {
        day1 = 12;
    }
    return day1;
}

 /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
bool Date::isLeap(unsigned y) const {
    bool leap = false;
    
    if (year % 4 == 0) 
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
                leap = true;
            else
                leap = false;
            
        }
        else 
            leap = true;
    }
    else 
        leap = false;   
    
return leap;
    
}



 /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
void Date::printNumeric() const {
    cout << month << '/' << day << '/' << year; 
}

/* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
void Date::printAlpha() const {
    cout << name(month) << " " << day << ", " << year;
    
}

 /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
    int numDays;
    if(m == 1 ||  m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        numDays = 31;
    }
    
    if(m == 4 || m == 6 || m == 9 || m == 11) {
        numDays = 30;
    }
    
    if(m == 2 && isLeap(y)) {
        numDays = 29;
    }
    else if (m == 2 && isLeap(y) == false) {
        numDays = 28;
    }

return numDays;
    
}


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
