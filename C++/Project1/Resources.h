 /*
  *  Resources.h
  *
  *  COSC 052 Fall 2021
  *  Project #1
  *
  *  Due on: SEP 16, 2021
  *  Author: Patrick Cronin  pjc269
  *
  *
  *  In accordance with the class policies and Georgetown's
  *  Honor Code, I certify that, with the exception of the
  *  class resources and those items noted below, I have neither
  *  given nor received any assistance on this project.
  *
  *  References not otherwise commented within the program source code.
  *  Note that you should not mention any help from the TAs, the professor,
  *  or any code taken from the class textbooks.
  */
 
 #ifndef _COSC052_FALL2021_P1_RESOURCES_H_
 #define _COSC052_FALL2021_P1_RESOURCES_H_
 
 #define DEBUG_FILE_OPENING = 1
 //#define DEBUG_DATE
 
 #include <iostream>
 #include <iomanip>
 #include <exception>
 #include <stdexcept>
 #include <sstream>
 #include <fstream>
 #include <string>
 
 
 using std::invalid_argument;
 using std::cout;
 using std::endl;
 using std::string;
 using std::ostream;
 using std::istream;
 using std::logic_error;
 using std::ostringstream;

 
 const int MAX_LINES = 10;
 
 // use for array indexes (can improve readability)
 enum MONTH_LIST {DUMMY, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
 
 // use minimum values as defaults unless otherwise specified
 
 // this array stores max day value for month number corresponding to array index
 const int MAX_DD[] =  { -1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 const int MIN_DD = 1;
 
 const int MIN_YYYY = 1492;
 const int MAX_YYYY = 2192;
 
 const int MIN_MM = 1;
 const int MAX_MM = 12;
 
 
 const int MIN_HOUR = 0;
 const int MAX_HOUR = 24;    // assumes that 24:00 is valid for midnight, 00:00 would also be valid
 const int DEFAULT_HOUR = 24;
 
 const int MIN_MINUTE = 0;
 const int MAX_MINUTE = 59;
 const int DEFAULT_MINUTE = 0;
 
 std::string readDoubleQuotedString( std::istream& in ); // required
 std::string trimSpaces( std::string s ); // optional
 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                     class Date declaration                             **
  **                                                                        **
  **                 This code is provided to students                      **
  **                 in COSC 052 Fall 2021 to use in                        **
  **                 part or in total for class projects.                   **
  **                 Students may use this code as their                    **
  **                 own, without any attribution.                          **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 class Date
 {
     friend std::istream& operator>>(std::istream&, Date&);
     friend std::ostream& operator<<(std::ostream&, const Date&);
 
 public:
     Date(int=MIN_YYYY, int=MIN_MM, int=MIN_DD); //yyyy, mm, dd
     Date(const Date&);
     void setDate(int, int, int);  //yyyy, mm, dd
     void setDate(const Date&);
     Date operator=(const Date&);
     int getYear() const;
     int getMonth() const;
     int getDay() const;
     bool operator ==(const Date&) const;
     bool operator !=(const Date&) const;
     bool operator <=(const Date&) const;
     bool operator <(const Date&) const;
     bool operator >=(const Date&) const;
     bool operator >(const Date&) const;
 
 private:
 
     int yyyy; 
     int mm;   
     int dd;   
 }; //end class Date
 
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                 class Time declaration                                 **
  **                                                                        **
  **                 This code is provided to students                      **
  **                 in COSC 052 Fall 2021 to use in                        **
  **                 part or in total for class projects.                   **
  **                 Students may use this code as their                    **
  **                 own, without any attribution.                          **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 class Time
 {
     friend std::istream& operator>>(std::istream &in, Time &t);
     //Overloaded stream extraction operator
     //Postcondition: Extracts values for each data member from
     //the input stream.  Format of the data in the stream
     //is assumed to be:  hh:mm
     //The delimiting character is read and discarded.
 
     friend std::ostream& operator<<(std::ostream &os, const Time &t);
     //Overloaded stream insertion operator.
     //Postcondition: The time is output to the steam.  Delimiting
     //character is replaced.  The result is a time value
     //output in the same format as was read in (except values less than
     //10 shall be right padded with a 0 which may not have been
     //what was read in).
 
 private:
 
     int hh; 
     int mm; 
 public:
     Time(int = DEFAULT_HOUR, int = DEFAULT_MINUTE);
 
     void setTime(int, int);
 
     int getHour() const {return hh;}  
 
     int getMinute() const {return mm;}  
 
     Time operator=(const Time&);
 
     bool operator==( const Time& ) const;
 
     bool operator!=( const Time& ) const;
 
     bool operator>( const Time& ) const;
 
     bool operator<( const Time& ) const;
 
 }; //END class Time declaration
 
 
 
 
 
 
 
 
 #endif  /*  _COSC052_FALL2021_P1_RESOURCES_H_  */