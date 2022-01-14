/*
  *  Exceptions.cpp
  *
  *  COSC 052 Fall 2021
  *  Project #4
  *
  *  Due on: NOV 11, 2021
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


#include "ProcessTimer.h"


/****************************************************************************
 **                                                                        **
 **                  class ProcessTimer implementation                     **
 **                                                                        **
 ****************************************************************************/

ProcessTimer::ProcessTimer()

{

    timeStart = 0;

    timeEnd = 0;

}



ProcessTimer::ProcessTimer(clock_t tmSt)

{

    timeStart = tmSt;

    timeEnd = 0;

}



ProcessTimer::~ProcessTimer()

{

    std::cout << "Inside destructor for ProcessTimer object" << std::endl;

}



std::ostream& operator<<(std::ostream &os, const ProcessTimer &tmStmp)

{

    std::cout << "Start time:\t" << tmStmp.timeStart << "\n";

    std::cout << "End time:\t" << tmStmp.timeEnd << "\n";

    std::cout << "Elapsed time:\t";

    std::cout << (tmStmp.timeEnd - static_cast<double>(tmStmp.timeStart))/CLOCKS_PER_SEC;

    std::cout << "\n";

    std::cout << std::endl;



    return os;

}



void ProcessTimer::setTimeStart(clock_t tmStart)

{

    timeStart = tmStart;

}



void ProcessTimer::setTimeEnd(clock_t tmEnd)

{

    timeEnd = tmEnd;

}



clock_t ProcessTimer::getTimeStart()

{

    return timeStart;

}



clock_t ProcessTimer::getTimeEnd()

{

    return timeEnd;

}



double ProcessTimer::getTimeElapsed()

{

    return static_cast<double>( (timeEnd - static_cast<double>(timeStart))/CLOCKS_PER_SEC );

}


