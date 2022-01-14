/*
 *  Exceptions.h
 *
 *  COSC 052 Fall 2021
 *  Project #4
 *
 *  Due on: NOV 11, 2021
 *  Author: Patrick Cronin pjc269
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




#ifndef _COSC052_FALL2021_P3_EXCEPTIONS_H_
#define _COSC052_FALL2021_P3_EXCEPTIONS_H_



#include <iostream>
#include <stdexcept>
#include <exception>


using std::invalid_argument;
using std::string;



/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                 class bad_vehicle_code declaration                     **
 **                                                                        **
 **                 This code is provided to students                      **
 **                 in COSC 052 Fall 2021 to use in                        **
 **                 part or in total for class projects.                   **
 **                 Students may use this code as their                    **
 **                 own, without any attribution.                          **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/

class bad_vehicle_code : public std::invalid_argument
{
public:
    bad_vehicle_code(string msg = "");

}; // END class bad_vehicle_code




class no_such_object : public std::logic_error
{
public:
    no_such_object(std::string);

}; // END no_such_object





#endif /*  _COSC052_FALL2021_P3_EXCEPTIONS_H_  */
