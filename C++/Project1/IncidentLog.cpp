 /*
  *  IncidentLog.cpp
  *
  *  COSC 052 Fall 2021
  *  Project #1
  *
  *  Due on: SEP 18, 2021
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

#include "IncidentLog.h"
#include "Resources.h"

IncidentLog::IncidentLog()
{

}
IncidentLog::~IncidentLog()
{

}
 
void  IncidentLog::displayReports(string outputFileName) const
{
  ofstream myFile;
  myFile.open(outputFileName);

  if(!myFile)
  {
    cout<<"file failed to open";
    throw logic_error("file failed to open in display reports");
  }
  else
  {
      cout<<"file opened for output\n";
      cout<<outputFileName<<endl;
      displayReports(myFile);

      myFile.close();
  }

}

void IncidentLog::displayReports(ostream &os ) const
{
  std::string errOutStream = "ERROR: in IncidentLog class displayReports2<<\n";
  errOutStream += "the output stream is in a failed state, no processing can take place...\n";
  if (!os)
  {
      throw std::invalid_argument(errOutStream);
  }
  else
  {
    int i = 0;
    cout << "Form PHMSA F 7000-1 Accident Report - Hazardous Liquid Pipeline Systems"
            <<" (181) records:" << endl;
    while(i < allIncidents.size())
    {
      allIncidents[i].summaryReport(os);
      i = i+1;
    }

  }
}

HazMat7k& IncidentLog::find(string incidentNum)
{
  cout << "enter find:" << endl;
  int i = 0;
  int z = -1;
  std::ostringstream errStrm;


  while(i<allIncidents.size())
  {
    if(allIncidents[i].getReportNumber() == incidentNum)
    {
      z=i;
    }
    i= i +1;
  } 

  if(z==-1)
  {
    errStrm << "ERROR: in method IncidentLog::Find " << incidentNum << endl;
    std::string errIncidentLog = errStrm.str();
    std::logic_error e(errIncidentLog);
    throw e;
  }
  return allIncidents[z];
}

void IncidentLog::read( string dataFileName )
{
  ifstream inFile;
  inFile.open(dataFileName.c_str());


  if(!inFile){
      throw logic_error("file failed to open");
  }
  else
  {
      cout<<"file opened for input\n";
      cout<<dataFileName<<endl;
      read(inFile);
  }
}

void IncidentLog::read( istream& in )
{
  std::string errInStream = "ERROR: in IncidentLog class Read2<<\n";
  errInStream += "the input stream is in a failed state, no processing can take place...\n";
  if (!in)
  {
      throw std::invalid_argument(errInStream);
  }
  HazMat7k hm1;
  int i = 0;
  while (in)
  {
      try 
      {
        in >> hm1;
        allIncidents.push_back(hm1);
        i =i+1;
        if (allIncidents.size()==182)
        {
          string throwaway;
          in >> throwaway;
        }
        
      }
      catch (std::invalid_argument &e)
      {
        string garbage;
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument while reading\n";
        std::cout << e.what() << endl;
        getline(in, garbage);
      }
      catch (...)
      {
        std::cout << "ERROR: unknown exception caught while reading\n";
      //throw;
      } 
  }
}
 
void IncidentLog::write( string outputFileName ) const
{
  ofstream myFile;
  myFile.open(outputFileName);

  if(!myFile)
  {
    cout<<"file failed to open\n";
    throw logic_error("file failed to open in write\n");
  }
  else
  {
      cout<<"file opened for  write \n";
      write(myFile);
      myFile.close();
  }
}

void IncidentLog::write( ostream& out) const
{
  std::string errOutStream = "ERROR: in IncidentLog class write2<<\n";
  errOutStream += "the output stream is in a failed state, no processing can take place...\n";
  if (!out)
  {
      throw std::invalid_argument(errOutStream);
  }
  else
  {
    int i = 0;
    while(i < allIncidents.size())
    {
      out << allIncidents[i];
      i = i+1;
    }
  }
}
 
 

