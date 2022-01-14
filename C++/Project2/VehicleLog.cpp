/*
  *  VehicleLog.cpp
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

#include "VehicleLog.h"
#include "Exceptions.h"


class bad_vehicle_code;

//VehicleLog constrctor and destructor
VehicleLog::VehicleLog()
{
    cout<<"enter vehicle constructor"<<endl;
}

VehicleLog::~VehicleLog()
{
    cout<<"enter vehicleLog destructor"<<endl;
    for(int i=0; i<vehicles.size(); i++){
        delete vehicles[i];
    }

}




//Get functions
int VehicleLog::getTotalPassengerCapacity() const
{
    int passTot = 0;
    Passenger *ptrPass;
    ptrPass = NULL;
    int totalCapacity = 0;
    for (int i = 0; i < vehicles.size(); ++i)
    {
        //clculate total lives remaining all Cat objects
        ptrPass = dynamic_cast<Passenger*>(vehicles.at(i));

        if (ptrPass)
        {
            //dynamic cast was successful
            passTot= passTot+ptrPass->getCapacity();
        }
    }
    return passTot;
}

double VehicleLog::getTotalCargoCapacity() const
{
    double cargoTot = 0.0;
    Cargo *ptrCargo;
    ptrCargo = NULL;
    int totalCapacity = 0;
    for (int i = 0; i < vehicles.size(); ++i)
    {
        //clculate total lives remaining all Cat objects
        ptrCargo = dynamic_cast<Cargo*>(vehicles.at(i));

        if (ptrCargo)
        {
            //dynamic cast was successful
            cargoTot= cargoTot+ptrCargo->getCapacity();
        }
    }
    return cargoTot;
}





void VehicleLog::print( ostream& os ) const
{
    std::string errOutStream = "ERROR: in class vehicleLog::print<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";
    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }

    for (int i; i<vehicles.size(); i++)
    {
        vehicles[i]->print(os);
    }

}

void VehicleLog::read( string dataFileName )
{
    std::string errInStream = "ERROR: in IncidentLog class Read2<<\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";

    ifstream inFile;
    inFile.open(dataFileName.c_str());


    if (!inFile)
    {
        cout << dataFileName << endl;
        throw invalid_argument("file failed to open");

    }

    else
    {
        cout << "file opened for input\n";

        char  carCode = '?';
        inFile >> carCode;
        Individual *ptrInd = NULL;
        Passenger *ptrPass = NULL;
        Cargo *ptrCargo = NULL;



        while (inFile)
        {

            try {
                inFile.putback(carCode);

                if (carCode == 'p' || carCode == 'P') {
                    ptrPass = new Passenger;
                    ptrPass->read(inFile);
                    vehicles.push_back(ptrPass);
                }

                else if (carCode == 'c' || carCode == 'C')
                {
                    ptrCargo = new Cargo;
                    ptrCargo->read(inFile);
                    vehicles.push_back(ptrCargo);
                }

                else
                {
                    ptrInd = new Individual;
                    ptrInd->read(inFile);
                    vehicles.push_back(ptrInd);
                }

                }
            catch (bad_vehicle_code &e) {
                string garbage;
                getline(inFile, garbage);
                cout << garbage;
                }
            catch (std::invalid_argument &e) {
                string garbage;
                std::cout << "ERROR: ";
                std::cout << "caught invalid_argument while reading\n";
                std::cout << e.what() << endl;
                getline(inFile, garbage);
                cout << garbage;
            }
            catch (...) {
                std::cout << "ERROR: unknown exception caught while reading\n";
                //throw;
                }
            inFile>>carCode;
        }
    }
}

unsigned long VehicleLog::size() const
{
    unsigned long sizeVect;
    sizeVect = vehicles.size();
    return sizeVect;
}

Vehicle &VehicleLog::at(unsigned long ndx)
{
    if (ndx>vehicles.size())
    {
        throw out_of_range("index too large");
    }
    return *vehicles[ndx];
}




