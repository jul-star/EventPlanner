///////////////////////////////////////////////////////////
//  Option.cpp
//  Implementation of the Class Option
//  Created on:      08-сен-2016 10:23:03
//  Original author: jstar
///////////////////////////////////////////////////////////
#include "Option.h"

namespace EP {
namespace MD {
unsigned Option::vID=0;
Option::Option(Log *inLog):
    vVideography(false),
    Talk::Talk(inLog)
{
    BeverageSetup();
    SnackSetup();
    FurnitureSetup();
    EquipmentSetup();

}
Option::Option(const Option& rhs):
    vBeverage(rhs.vBeverage),
    vSnack(rhs.vSnack),
    vFurniture(rhs.vFurniture),
    vEquipment(rhs.vEquipment),
    vVideography(rhs.vVideography),
    Talk::Talk(rhs)
{

}

void Option::BeverageSetup()
{
    ++vID;
    vBeverage.insert(make_pair(vID,*new Item(vID, string("Rootbear"), 0)));
    ++vID;
    vBeverage.insert(make_pair(vID,*new Item(vID,string("Cola"), 0)));
    ++vID;
    vBeverage.insert(make_pair(vID,*new Item(vID,string("Pepsi"), 0)));
}
void Option::SnackSetup()
{
    ++vID;
    vSnack.insert(make_pair(vID,*new Item(vID,string("Cudighi"), 0)));
    ++vID;
    vSnack.insert(make_pair(vID,*new Item(vID,string("Runza"), 0)));
    ++vID;
    vSnack.insert(make_pair(vID,*new Item(vID,string("Shawarma"), 0)));
}


void Option::FurnitureSetup()
{
    ++vID;
    vFurniture.insert(make_pair(vID,*new Item(vID,string("Chair"), 0)));
    ++vID;
    vFurniture.insert(make_pair(vID,*new Item(vID,string("Table"), 0)));
}

void Option::EquipmentSetup()
{
    ++vID;
    vEquipment.insert(make_pair(vID,*new Item(vID,string("Tribune"), 0)));
    ++vID;
    vEquipment.insert(make_pair(vID,*new Item(vID,string("Projector"), 0)));
    ++vID;
    vEquipment.insert(make_pair(vID,*new Item(vID,string("ProjectorScreen"), 0)));
    ++vID;
    vEquipment.insert(make_pair(vID,*new Item(vID,string("ChalkBoard"), 0)));
}

Option& Option::operator=(const Option& rhs)
{
    if (this!=&rhs)
    {
        this->vBeverage = rhs.vBeverage;
        this->vSnack = rhs.vSnack;
        this->vFurniture = rhs.vFurniture;
        this->vEquipment = rhs.vEquipment;
    }
    return *this;
}

string Option::getItems(map<unsigned, Item>* inOptions)
{
    string out("");
    const Item* pItem{nullptr};
    for(map<unsigned, Item>::const_iterator it = inOptions->cbegin();
        it != inOptions->cend();
        ++it)
    {
        pItem = &it->second;
        out.append(pItem->getName());
        out.append(string(": "));
        out.append(to_string(pItem->getVal()));
        out.append(string("\n"));
    }
    return out;
}

string Option::View(nRole::ID inRole)
{
    string out("");
    switch(inRole)
    {
    case nRole::ID::Empty:

        break;
    case nRole::ID::Manager:
    case nRole::ID::Customer:
        out.append(getItems(&vFurniture));
       out.append(getItems(&vEquipment));
       out.append(string("\nMenu\n"));
       out.append(getItems(&vSnack));
       out.append(getItems(&vBeverage));
        break;
    case nRole::ID::Speaker:
        out.append(getItems(&vFurniture));
       out.append(getItems(&vEquipment));
       out.append(string("\nMenu\n"));
       out.append(getItems(&vBeverage));
        break;
    case nRole::ID::Participant:
        out.append(string("\nMenu\n"));
        out.append(getItems(&vSnack));
        out.append(getItems(&vBeverage));
        break;
    default:

        break;
    }

    return out;
}


Option::~Option()
{

}
}
}
