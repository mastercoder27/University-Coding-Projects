/*
  *  Vehicle.cpp
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

#include "Vehicle.h"



Vehicle::Vehicle()
{
    setID("p0000000000000000");
    setName("none");
    setInspectionDate(Date(MIN_YYYY, MIN_MM, MIN_DD));
    setStatus('m');
}

Vehicle::Vehicle(string id, string n, Date d, char s) {
    setID(id);
    setName(n);
    setInspectionDate(d);
    setStatus(s);
}

Vehicle::~Vehicle()
{
}

//SET METHODS
void Vehicle::setStatus(char st) {
    if (toupper(st) != 'S' &&
        toupper(st) != 'M' &&
        toupper(st) != 'A')
    {
        throw invalid_argument("not a valid status code\n");
    }
    else
    {
        status = st;
    }
}

void Vehicle::setInspectionDate(Date iDate) {
    inspectionDate.setDate(iDate);
}

void Vehicle::setName(string n) {
    name = n;
}

void Vehicle::setID(string i)
{
    char carCode = i[0];
    std::string errSetID = "ERROR: in method setID\n";

    if (i.length()>17)
    {
        errSetID += "ID exceeds 17 characters\n";
        throw std::invalid_argument(errSetID);
    }

    if (toupper(carCode) != 'I' &&
        toupper(carCode) != 'P' &&
        toupper(carCode) != 'C')
    {
        throw bad_vehicle_code("not a valid vehicle code\n");
    }
    for (int x = 0; x < i.size(); x++)
    {
        if (i[x]== '@')
        throw bad_vehicle_code("bad character\n");
    }

    id = i;
}



//GET METHODS
char Vehicle::getStatus() const {
    return status;
}

Date Vehicle::getInspectionDate() const {
    return inspectionDate;
}

string Vehicle::getName() const {
    return name;
}

string Vehicle::getID() const {
    return id;
}




//OTHER METHODS
void Vehicle::read(istream &is)
{
    std::string errOutStream = "ERROR: in vehicle::read()<<\n";
    errOutStream += "the intput stream is in a failed state, no processing can take place...\n";
    if (!is)
    {
        throw std::invalid_argument(errOutStream);
    }
    else {
        string inpId, inpName;
        Date inpInspectionDate;
        char inpStatus;
        char trsh = '"';

        is >> inpId >> trsh && std::getline(is, inpName, '"')  >> inpInspectionDate >> inpStatus;
        //cout << inpId << endl << inpName << endl << inpInspectionDate << endl << inpStatus;
        setID(inpId);
        setName(inpName);
        setInspectionDate(inpInspectionDate);
        setStatus(inpStatus);
    }
}

void Vehicle::print(ostream &os) const
{
    std::string errOutStream = "ERROR: in class vehicle::print<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";
    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }
    else
    {
        os << setw(20) << "Vehicle ID:\t" << id << endl << setw(20) << "Make/Model:\t"<< name << endl << setw(20)<< "Last Inspection:\t" << inspectionDate << endl << setw(20)<<"Current Status:\t" << status << endl <<endl;
        cout << setw(20) << "Vehicle ID:\t" << id << endl << setw(20) << "Make/Model:\t"<< name << endl << setw(20)<< "Last Inspection:\t" << inspectionDate << endl << setw(20)<<"Current Status:\t" << status << endl <<endl;
    }
}





Individual::Individual(): Vehicle()
{

}

Individual::Individual(string id, string name, Date inspectionDate, char status) : Vehicle(id,
                                                                                           name, inspectionDate, status)
{
    setID(id);
    setName(name);
    setInspectionDate(inspectionDate);
    setStatus(status);
}





Passenger::Passenger(unsigned short cap)
{
    setCapacity(cap);
}

Passenger::Passenger(string id, string name, Date inspectionDate, char status, unsigned short cap) : Vehicle(id,
        name, inspectionDate, status)
{
    setID(id);
    setName(name);
    setInspectionDate(inspectionDate);
    setStatus(status);
    setCapacity(cap);
}

unsigned short Passenger::getCapacity() const
{
    return capacity;
}

void Passenger::setCapacity(unsigned short cap)
{
    if(MAX_PASSENGER_CAPACITY<cap)
    {
        throw too_many_passengers("excessive passengers\n");
    }
    capacity = cap;
}

void Passenger::print(ostream &os) const
{
    std::string errOutStream = "ERROR: in IncidentLog class displayReports2<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";
    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }
    else
    {

        os << setw(20) << "Vehicle ID:\t" << id << endl << setw(20) << "Make/Model:\t"<< name << endl << setw(20)<< "Last Inspection:\t" << inspectionDate << endl << setw(20)<<"Current Status:\t" << status << endl << setw(20) << "Max. Passengers:\t" << capacity << endl<<endl;
        cout << setw(20) << "Vehicle ID:\t" << id << endl << setw(20) << "Make/Model:\t"<< name << endl << setw(20)<< "Last Inspection:\t" << inspectionDate << endl << setw(20)<<"Current Status:\t" << status << endl << setw(20) << "Max. Passengers:\t" << capacity << endl<<endl;
    }
}

void Passenger::read(istream &is)
{
    std::string errOutStream = "ERROR: in IncidentLog class displayReports2<<\n";
    errOutStream += "the intput stream is in a failed state, no processing can take place...\n";
    if (!is)
    {
        throw std::invalid_argument(errOutStream);
    }
    else {
        int inpCap;
        string inpId, inpName;
        Date inpInspectionDate;
        char inpStatus;
        char trsh = '"';

        is >> inpId >> trsh && std::getline(is, inpName, '"')  >> inpInspectionDate >> inpStatus >> inpCap;
        //cout << inpId << endl << inpName << endl << inpInspectionDate << endl << inpStatus <<endl<< inpCap;
        setID(inpId);
        setName(inpName);
        setInspectionDate(inpInspectionDate);
        setStatus(inpStatus);
        setCapacity(inpCap);
    }
}







Cargo::Cargo(double capacity) {
    setCapacity(capacity);
}

Cargo::Cargo(string id, string name, Date inspectionDate, char status, double cap)
{
    setID(id);
    setName(name);
    setInspectionDate(inspectionDate);
    setStatus(status);
    setCapacity(cap);
}

double Cargo::getCapacity() const
{
    return capacity;
}

void Cargo::setCapacity(double cap) 
{
    if(MAX_CARGO_CAPACITY<cap)
    {
        throw too_much_cargo("excessive cargo\n");
    }

    capacity= cap;
}

void Cargo::print(ostream &os) const 
{
    std::string errOutStream = "ERROR: in IncidentLog class displayReports2<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";
    if (!os)
    {
        cout<<"cargo print";

        throw std::invalid_argument(errOutStream);
    }
    else
    {
        os << setw(20) << "Vehicle ID:\t" << id << endl << setw(20) << "Make/Model:\t"<< name 
            << endl << setw(20)<< "Last Inspection:\t" << inspectionDate 
            << endl << setw(20)<<"Current Status:\t" << status 
            << endl << setw(20) << "Max. Payload:\t" << capacity << " tons"<<endl<<endl;
        cout << setw(20) << "Vehicle ID:\t" << id << endl << setw(20) << "Make/Model:\t"<< name
            << endl << setw(20)<< "Last Inspection:\t" << inspectionDate 
            << endl << setw(20)<<"Current Status:\t" << status 
            << endl << setw(20) << "Max. Payload:\t" << capacity << " tons"<<endl << endl;
    }
}

void Cargo::read(istream &is) {
    std::string errOutStream = "ERROR: in IncidentLog class displayReports2<<\n";
    errOutStream += "the intput stream is in a failed state, no processing can take place...\n";
    if (!is)
    {
        throw std::invalid_argument(errOutStream);
    }
    else {
        double inpCap;
        string inpId, inpName;
        Date inpInspectionDate;
        char inpStatus;
        char trsh = '"';

        is >> inpId >> trsh && std::getline(is, inpName, '"')  >> inpInspectionDate 
            >> inpStatus >> inpCap;

        setID(inpId);
        setName(inpName);
        setInspectionDate(inpInspectionDate);
        setStatus(inpStatus);
        setCapacity(inpCap);
    }
}
