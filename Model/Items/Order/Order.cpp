#include "Order.h"

namespace EP {
namespace MD {

unsigned Order::vOrderCounter;

Order::Order(Log *inLog):
    Talk::Talk(inLog)
{
    vIndex = (++vOrderCounter);
}

Order& Order::operator=(const Order& rhs)
{
    if (this != &rhs)
    {
        this->vHallOptions = rhs.vHallOptions;
        this->vIndex = rhs.vIndex;
        this->vDescription = rhs.vDescription;
        this->vDate = rhs.vDate;
        this->vParticipantsList = rhs.vParticipantsList;
    }
    return *this;
}

Order::Order(const Order& rhs) :
    vIndex(rhs.vIndex),
    vHallOptions(rhs.vHallOptions),
    vDescription(rhs.vDescription),
    vDate(rhs.vDate),
    vParticipantsList(rhs.vParticipantsList),
    Talk::Talk(rhs)
{

}

unsigned Order::getIndex() const
{
    return vIndex;
}

string Order::getInfo( nRole::ID inUserRole) const
{
    string out("");

        for (auto it : vHallOptions)
        {
            out.append(it.first->View(inUserRole));
            out.append(it.second.View(inUserRole));
            out.append("\n");
        }
    return out;

}

void Order::setDate(unsigned inDate)
{
 if (vHallOptions.empty())
 {
     vDate = inDate;
 }
 else
 {
     string vError(__FILE__);
     vError.append(to_string(__LINE__));
     vError.append("Can't Change Day.");
     perror(vError.c_str());
     this->Tell(vError);
 }
}


const Order::HallOptionMap *Order::HallsGet() const
{
    return &vHallOptions;
}

bool Order::HallAdd(Hall* inHall)
{
    if ( vDate != 0 )
    {
        vHallOptions.insert(make_pair(inHall, *new Option(this->GetLog())));
        return true;
    }
    else
    {
        string vError(__FILE__);
        vError.append(to_string(__LINE__));
        vError.append("Choose Day first");
        this->Tell(vError);
        perror(vError.c_str());
        return false;
    }
}




Order::~Order()
{

}
}
}
