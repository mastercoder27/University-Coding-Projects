 /*
  *  main.cpp
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
 
#include "main.h"

int main (int argc, const char * argv[]){

  IncidentLog testLog;
  
  try
    {
		string errMsg1 = "must pass input file name and complete path as command line argument\n";
		if (argc < 2)
		{
			throw invalid_argument(errMsg1); 
		}

        else
        {
            testLog.read(argv[1]);
            testLog.displayReports("IncidentReport.txt");
        }

        
    } // END try
    
	catch ( invalid_argument &e)
	{
		cout << "caught invalid_argument exception in function main.\n";
		cout << e.what() << endl;
	}
    catch (logic_error &e)
	{
		cout << "caught invalid_argument exception in function main.\n";
		cout << e.what() << endl;
	}
  catch (...)
  {
      cout << "caught unknown exception in function main\n" << endl;
  }
  return 0;
}