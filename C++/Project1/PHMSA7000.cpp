 /*
  *  PHMSA7000.cpp
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

#include "PHMSA7000.h"

HazMat7k::~HazMat7k()
{

}
 
HazMat7k::HazMat7k()
{
    Date reportReceivedDate;           
    reportNumber = "0000000000";               
    supplementalNumber = "";         
    reportType = "ORIGINAL";                 
    operatorID = "";                 
    name = "";                       
    operatorStreetAddress = "";      
    operatorCityName = "";           
    operatorStateAbbreviation = "";  
    operatorPostalCode = "";         
    Date localDate;                    
    Time localTime;                    
    string  commodityReleasedType= "";      
    unintentionalReleaseBbls = 0.0 ;
    intentionalReleaseBbls = 0.0;
    recoveredBbls = 0.0;
 
    fatal = 0;                
    injure = 0;               
    igniteInd = "";         
    explodeInd = "";        
    Date  preparedDate;        
    string  authorizerName = "";    
    string  authorizerEmail = "";   
    string  narrative = "";  
}

void HazMat7k::setReportNumber(string value)
{
  std::ostringstream errStrm;

  bool badArguments = false;

  string firstFour = "";
  int i =0;
  while(i<4)
  {
      firstFour = firstFour+value[i];
      i +=1; 
  }
  int numYear = reportReceivedDate.getYear();
  std::string strgYear = std::to_string(numYear);


  if ( value.size() != 8 )
  {
      // one on more of the values passed in are not valid
      badArguments = true;
  }
  else if ( firstFour != strgYear)
  {
      badArguments = true;
  }


  if (badArguments)
  {
    errStrm << "ERROR: in method HazMat7k::setReportNumber " << value << endl;

    std::string errHazMat7k = errStrm.str();
    std::invalid_argument e(errHazMat7k);
    throw e;
  }

  this->reportNumber = value;
}

void HazMat7k::setReportType(string value)
{
  std::ostringstream errStrm;

  if ( value != "ORIGINAL" &&  value != "ORIGINAL FINAL" && value != "SUPPLEMENTAL" && 
    value != "SUPPLEMENTAL FINAL")
  {
    errStrm << "ERROR: in method HazMat7k::setReportType" << value << endl;

    std::string errHazMat7k = errStrm.str();

    std::invalid_argument e(errHazMat7k);
    throw e;
  }
  this->reportType = value;                 

}

void HazMat7k::summaryReport(ostream &os) const 
{
  std::string errOutStream = "ERROR: in HazMat7k class summary report\n";
  if (!os)
  {
    throw std::invalid_argument(errOutStream);
  }

  os << "Report Number and Date:\t" << reportNumber << "   " << reportReceivedDate<< endl;
  os << "Local Date and Time:\t" <<  localDate << "   " << localTime<< endl;
  os << "Number of Injuries:\t" << injure << endl;
  os << "Number of Fatalities:\t" << fatal << endl;
  os << "Narrative: " << narrative << endl << endl;

  // set the fill character back to a blank space to prevent really ugly output of other values
  os << std::setfill(' ');

  cout << "Report Number and Date:\t" << reportNumber << "   " << reportReceivedDate<< endl;
  cout << "Local Date and Time:\t" <<  localDate << "   " << localTime<< endl;
  cout << "Number of Injuries:\t" << injure << endl;
  cout << "Number of Fatalities:\t" << fatal << endl;
  cout << "Narrative: " << narrative << endl << endl;

}

std::ostream& operator<<(ostream &os, const HazMat7k &rhsObj)
{
  os << rhsObj.reportReceivedDate << rhsObj.reportNumber << rhsObj.supplementalNumber << '"' << 
  rhsObj.reportType << '"'<< rhsObj.operatorID <<  '"'<<rhsObj.name<< '"'<< '"'<<
  rhsObj.operatorStreetAddress<< '"' <<  '"'<<rhsObj.operatorCityName << '"'<< 
  rhsObj.operatorStateAbbreviation << '"'<<rhsObj.operatorPostalCode<< '"' << rhsObj.localDate <<
  rhsObj.localTime <<  '"'<<rhsObj.commodityReleasedType << '"' << rhsObj.unintentionalReleaseBbls
  << rhsObj.intentionalReleaseBbls << rhsObj.recoveredBbls << rhsObj.fatal << rhsObj.injure << 
  rhsObj.igniteInd << rhsObj.explodeInd << rhsObj.preparedDate << '"'<<rhsObj.authorizerName << 
  '"'<<  '"'<< rhsObj.authorizerEmail << '"' <<  '"'<<rhsObj.narrative<< '"';

  return os;  
}




std::istream& operator>>(istream &is, HazMat7k &rhsObj)
{
  std::string errInStream = "ERROR: in Time class overloaded operator>>\n";
  errInStream += "the input stream is in a failed state, no processing can take place...\n";

  if (!is)
  {
      throw std::invalid_argument(errInStream);
  }


  Date  reportReceivedDate, localDate, preparedDate;           
  
  string  reportNumber, supplementalNumber, reportType, operatorID, name, operatorStreetAddress,
      operatorCityName, operatorStateAbbreviation, operatorPostalCode, commodityReleasedType, 
      igniteInd,explodeInd, authorizerName, authorizerEmail, narrative, trash;         
                       
  Time  localTime;                  
     
  double  unintentionalReleaseBbls, intentionalReleaseBbls, recoveredBbls;
 
  int  fatal, injure;               

  char trp= '"';



  bool streamFailed = false;


  is >> reportReceivedDate >> reportNumber >> supplementalNumber ; 
  reportType = readDoubleQuotedString(is);
  is >> operatorID;
  name = readDoubleQuotedString(is);
  operatorStreetAddress = readDoubleQuotedString(is);
  operatorCityName=readDoubleQuotedString(is);
  is >> operatorStateAbbreviation;
  operatorPostalCode=readDoubleQuotedString(is);
  is >> localDate >> localTime; 
  commodityReleasedType = readDoubleQuotedString(is);
  is >> unintentionalReleaseBbls >> intentionalReleaseBbls >> recoveredBbls >> fatal >> injure >>
    igniteInd >> explodeInd >> preparedDate;
  authorizerName=readDoubleQuotedString(is);
  authorizerEmail=readDoubleQuotedString(is);
  narrative=readDoubleQuotedString(is);
  // getline(is, trash, '\n');

  
  rhsObj.setReportReceivedDate(reportReceivedDate);
  rhsObj.setReportNumber(reportNumber);
  rhsObj.setSupplementalNumber(supplementalNumber);
  rhsObj.setReportType(reportType);
  rhsObj.setOperatorID(operatorID);
  rhsObj.setName(name);
  rhsObj.setOperatorStreetAddress(operatorStreetAddress);
  rhsObj.setOperatorCityName(operatorCityName);
  rhsObj.setOperatorStateAbbreviation(operatorStateAbbreviation);
  rhsObj.setOperatorPostalCode(operatorPostalCode);
  rhsObj.setLocalDate(localDate);
  rhsObj.setLocalTime(localTime);
  rhsObj.setCommodityReleasedType(commodityReleasedType);
  rhsObj.setUnintentionalReleaseBbls(unintentionalReleaseBbls);
  rhsObj.setIntentionalReleaseBbls(intentionalReleaseBbls);
  rhsObj.setRecoveredBbls(recoveredBbls);
  rhsObj.setFatal(fatal);
  rhsObj.setInjure(injure);
  rhsObj.setIgniteInd(igniteInd);
  rhsObj.setExplodeInd(explodeInd);
  rhsObj.setPreparedDate(preparedDate);
  rhsObj.setAuthorizerName(authorizerName);
  rhsObj.setAuthorizerEmail(authorizerEmail);
  rhsObj.setNarrative(narrative);

  


  return is;
}