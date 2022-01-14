/*
  *  main.cpp
  *
  *  COSC 052 Fall 2021
  *  Project #3
  *
  *  Due on: OCT 29, 2021
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

int main(int argc, const char * argv[])
{
    LL<Date> myLL;
    try
    {
        string errMsg1 = "must pass input file name and complete path as command line argument\n";


        if (argc < 2)
        {
            throw invalid_argument(errMsg1);
        }


        ifstream myFile;
        myFile.open(argv[1]);

        if(!myFile)
        {
            cout<<"file failed to open";
            throw logic_error("file failed to open in display reports");
        }

        string trash;
        getline(myFile, trash);
        Date dataDate;



        while ( myFile)
        {
            try
            {
                myFile>>dataDate;
                myLL.push_front( dataDate);

            }
            catch ( invalid_argument &e)
            {
                cout << "caught invalid_argument exception in while loop.\n";
                cout << e.what() << endl;
            }

        }
        myFile.close();
        cout << myLL <<endl;
        myLL.bubbleSort();
        cout << myLL;
        Date getDate(2002,8,1);
        cout<<myLL.linearSearch(getDate);


    } // END try

    catch ( invalid_argument &e)
    {
        cout << "caught invalid_argument exception in function main.\n";
        cout << e.what() << endl;
    }
    catch ( std::out_of_range &e)
    {
        cout << "Error out of range index: \n";
        cout << e.what() << endl;
    }
   catch ( no_such_object &e)
    {
        cout << "no object exists \n";
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "caught unknown exception in function main\n" << endl;
    }

    return 0;
}



