///////////////////////////////////////////////////////////
//  User.cpp
//  Implementation of the Class User
//  Created on:      08-сен-2016 10:23:17
//  Original author: jstar
///////////////////////////////////////////////////////////
#include "User.h"

namespace EP {
namespace MD {

unsigned User::vUserCounter;

User::User(const User& rhs) :
    vID(rhs.vID),
    vFirstName(rhs.vFirstName),
    vLastName(rhs.vLastName),
    pRole(rhs.pRole),
    vEmail(rhs.vEmail),
    vPhone(rhs.vPhone),
    vOrders(rhs.vOrders),
    Talk::Talk(rhs)
{

}
User& User::operator=(const User& rhs)
{
    if (this != &rhs)
    {
        this->vID = rhs.vID;
        this->vFirstName = rhs.vFirstName;
        this->vLastName = rhs.vLastName;
        this->pRole = rhs.pRole;
        this->vEmail = rhs.vEmail;

        this->vPhone = rhs.vPhone;

        this->vOrders = rhs.vOrders;
    }
    return *this;
}

User::User(string inFirstName,
        string inLastdName,
        Role &inRole,
        string inPhone,
        string inEmail, Log *inLog) :
    vFirstName(inFirstName),
    vLastName(inLastdName),
    pRole(&inRole),
    vEmail(inEmail),
    vPhone(inPhone),
    Talk::Talk(inLog)
{
    vID = (++vUserCounter);
}



User::~User() {

}





string User::getEmail() const {

    return  vEmail;
}


string User::getFirstName() const
{
    return  vFirstName;
}


string User::getLastName() const {

    return  vLastName;
}


void User::setEmail(string inEmail) {
    vEmail = inEmail;
}


void User::setFirstName(string inFirstName) {
    vFirstName = inFirstName;

}


void User::setRole(Role& role)
{
    try {
        pRole = &role;
    }
    catch (exception& ex)
    {
        string vError(__FILE__);
        vError.append(to_string(__LINE__));
        vError.append(ex.what());
        perror(vError.c_str());
        return;
    }
}

string User::getOrderInfo(const unsigned inOrderId)
{
    string out("");
    map<unsigned, Order*>::iterator it = vOrders.find(inOrderId);
    if (it != vOrders.end())
    {
        out.append(it->second->getInfo(pRole->getID()));
    }
    return out;
}

unsigned User::getID() const
{
    return vID;
}



void User::setLastName(string inLastName)
{
    vLastName = inLastName;
}
}
}
