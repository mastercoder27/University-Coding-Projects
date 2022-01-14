 /*
  *  IncidentLog.h
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
 
 
 
 #ifndef _COSC052_FALL2021_P1_INCIDENT_LOG_H
 #define _COSC052_FALL2021_P1_INCIDENT_LOG_H
 
 
 
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <exception>
 #include <stdexcept>
 
 #include "PHMSA7000.h"
 #include "Resources.h"
 
 using std::ostream;
 using std::cout;
 using std::logic_error;
 using namespace std;
 
 
 /****************************************************************************
  ****************************************************************************
  **                                                                        **
  **                 class IncidentLog declaration                          **
  **                                                                        **
  **                 This code is provided to students                      **
  **                 in COSC 052 Fall 2021 to use in                        **
  **                 part or in total for class projects.                   **
  **                 Students may use this code as their                    **
  **                 own, without any attribution.                          **
  **                                                                        **
  ****************************************************************************
  ****************************************************************************/
 
 class IncidentLog
 {
 private:
 
     vector<HazMat7k> allIncidents; 
 public:
 
     IncidentLog();
     ~IncidentLog();
 
     void displayReports(string outputFileName) const;
     void displayReports(ostream &os = cout) const;
 
     HazMat7k& find(string incidentNum);
 
     void read( string inputFileName );
     void read( istream& in );
 
     void write( string outputFileName ) const;
     void write( ostream& out = cout ) const;
 
     unsigned long size() const { return allIncidents.size(); }
 
 }; //END class IncidentLog declaration
 
 
 
 
 
 
 #endif   /*  _COSC052_FALL2021_P1_INCIDENT_LOG_H  */
