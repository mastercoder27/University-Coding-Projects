/*
  *  Exceptions.cpp
  *
  *  COSC 052 Fall 2021
  *  Project #2
  *
  *  Due on: OCT 28, 2021
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

no_such_object::no_such_object(string msg): std::logic_error(msg)
{
    std::cout << "ERROR: out_of_range index :\n";
}