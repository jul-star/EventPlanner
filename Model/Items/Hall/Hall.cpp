///////////////////////////////////////////////////////////
//  Hall.cpp
//  Implementation of the Class Hall
//  Created on:      08-сен-2016 10:23:00
//  Original author: jstar
///////////////////////////////////////////////////////////
#include "Hall.h"

namespace EP {
namespace MD {

unsigned Hall::vHallCounter;

Hall::Hall(string inName,
        unsigned int inCapacity,
        unsigned int inSeats,
        unsigned int inTables,
        unsigned int inTribune,
        bool inHasAirConditioning,
        bool inHasChalkBoard,
        bool inHasProjector,
        bool inHasProjectorScreen,
        unsigned int inHeight,
        unsigned int inLength,
        unsigned int inWidth,
        Log *inLog) :
    vName(inName),
    vCapacity(inCapacity),
    vSeats(inSeats),
    vTables(inTables),
    vTribune(inTribune),
    vHasAirConditioning(inHasAirConditioning),
    vHasChalkBoard(inHasChalkBoard),
    vHasProjector(inHasProjector),
    vHasProjectorScreen(inHasProjectorScreen),
    vHeight(inHeight),
    vLength(inLength),
    vWidth(inWidth),
    Talk::Talk(inLog)
{
    vIndex = (++vHallCounter);
}



Hall::~Hall() {

}

unsigned int Hall::getCapacity() const
{
    return vCapacity;
}

bool Hall::HasChalkBoard() const
{
    return vHasChalkBoard;
}

void Hall::setHasChalkBoard(bool valB)
{
    vHasChalkBoard = valB;
}

string Hall::View(nRole::ID inRoleId) const
{
    string out("");
    ostringstream ssOut;
    typedef nRole::ID RoleID;
    switch (inRoleId)
    {
    case RoleID::Manager:
        ssOut << "Hall: " << vName \
              << endl << "Seats: " << vSeats \
              << ", " << "Capacity: " << vCapacity \
              << ", " << "Tables: " << vTables \
              << endl << "Size: " \
              << "Length: " << vLength \
              << ", Width: " << vWidth \
              << ", Height: " << vHeight \
              << endl << "Equipment: " \
              << endl << "Tribune: " << vTribune \
              << ((vHasAirConditioning) ? ", Has an Air condition" : "") \
              << ((vHasProjector) ? ", Has a Projector" : "") \
              << ((vHasProjectorScreen) ? ", Has a Projector Screen" : "") \
              << ((vHasChalkBoard) ? ", Has a ChalkBoard" : "");
        break;
    case RoleID::Customer:
        ssOut << "Hall: " << vName \
              << endl << "Seats: " << vSeats \
              << ", " << "Capacity: " << vCapacity \
              << ", " << "Tables: " << vTables \
              << endl << "Equipment: " \
              << endl << "Tribune: " << vTribune \
              << ((vHasAirConditioning) ? ", Has an Air condition" : "") \
              << ((vHasProjector) ? ", Has a Projector" : "") \
              << ((vHasProjectorScreen) ? ", Has a Projector Screen" : "") \
              << ((vHasChalkBoard) ? ", Has a ChalkBoard" : "");
        break;
    case RoleID::Speaker:
        ssOut << "Hall: " << vName \
              << endl << "Seats: " << vSeats \
              << endl << "Equipment: " \
              << endl << "Tribune: " << vTribune \
              << ((vHasAirConditioning) ? ", Has an Air condition" : "") \
              << ((vHasProjector) ? ", Has a Projector" : "") \
              << ((vHasProjectorScreen) ? ", Has a Projector Screen" : "") \
              << ((vHasChalkBoard) ? ", Has a ChalkBoard" : "");
        break;
    case RoleID::Participant:
        ssOut << "Hall: " << vName \
              << ((vHasAirConditioning) ? ", Has an Air condition" : "");
        break;
    default:
        string vError(__FILE__);
        vError.append(to_string(__LINE__));
        vError.append("unknown Role");
        perror(vError.c_str());
        return out;
        break;
    }

    return ssOut.str();
}

unsigned int Hall::getSeats() const
{
    return vSeats;
}


void Hall::setSeats(unsigned int inSeats) {

    vSeats = inSeats;
}


unsigned Hall::getIndex() const
{
    return vIndex;
}

void Hall::setTables(unsigned int inTables) {

    vTables = inTables;
}
}
}
