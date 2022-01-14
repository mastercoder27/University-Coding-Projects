/*
  *  main.cpp
  *
  *  COSC 052 Fall 2021
  *  Project #3
  *
  *  Due on: Nov 30, 2021
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
    try
    {

        RD_Array<int> intArray;
        RD_Array<int> intArray2;

//        cout<< "size: "<< intArray.size()<<endl;
//        cout<< "capacity: "<< intArray.capacity()<<endl;

        intArray.push_back(2);
        intArray.push_back(3);
        intArray.push_back(4);

        intArray.insert(5,7);



//        intArray2 = intArray;

        for (int i = 0;  i< intArray2.size(); i++) {
            cout<<intArray2[i]<<endl;

        }


//        cout<< "size: "<< intArray.size()<<endl;
//        cout<< "capacity: "<< intArray.capacity()<<endl;

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



