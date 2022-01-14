/*
  *  Exceptions.cpp
  *
  *  COSC 052 Fall 2021
  *  Project #2
  *
  *  Due on: OCT 7, 2021
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


#include "Exceptions.h"

bad_vehicle_code::bad_vehicle_code(string msg): invalid_argument(msg)
{
    std::cout << "ERROR: caught bad_vehicle_code while reading\n";
    std::cout<< msg << std::endl;
}

too_many_passengers::too_many_passengers(string msg): invalid_argument(msg)
{
    std::cout << "ERROR: caught too_many_passengers while reading\n";
    std::cout<< msg << std::endl;
}
too_much_cargo::too_much_cargo(string msg): invalid_argument(msg)
{
    std::cout << "ERROR: caught too_much_cargo while reading\n";
    std::cout<< msg << std::endl;
}


