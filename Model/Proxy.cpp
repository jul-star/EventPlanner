#include "Proxy.h"

namespace EP {
namespace MD {

Proxy::Proxy():
   vLog(*new Log()),
    vHalls(*new Halls(&vLog)),
    vUsers(*new Users(&vLog)),
    vOrders(*new Orders(&vLog)),
    vPlanner(*new Planner()),
    vSchedule(*new Schedule()),
    vState(*new State())
{
}

Proxy::~Proxy()
{
    delete &vState;
    delete &vSchedule;
    delete &vPlanner;
    delete &vOrders;
    delete &vHalls;
    delete &vLog;
}

string Proxy::GetStateAndClearLog()
{
    string vMessage2VMLayer("");
       for(auto message: *vLog.LogGet())
       {
           vMessage2VMLayer.append(message);
       }
    vLog.Clear();
    return vMessage2VMLayer;
}

const Option *Proxy::OptionGet() const
{
    if(vHalls.Item() != nullptr && vOrders.Item() != nullptr)
    {
        if(vOrders.Item()->HallsGet()->find(vHalls.Item()) != vOrders.Item()->HallsGet()->end())
        {
            return &vOrders.Item()->HallsGet()->at(vHalls.Item());
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        return nullptr;
    }
}

Halls::pHallMap Proxy::getReservedHalls4Orders(vector<Order*> *inOrders)
{
    Halls::pHallMap out ;
    Order* pOrder;
    const Order::HallOptionMap* tmpHalls;
    Hall* pHall;

    for(vector<Order*>::iterator itOrder = inOrders->begin();
        itOrder != inOrders->end();
        ++itOrder)
    {
        pOrder =(Order*)(*itOrder);
        tmpHalls = pOrder->HallsGet();

        for( EP::MD::Order::HallOptionMap::const_iterator itHall = tmpHalls->cbegin();
             itHall != tmpHalls->cend();
             ++itHall)
        {
            pHall =(Hall*)(itHall->first);
            out.insert(make_pair(pHall->getIndex(), pHall));
        }
    }
    return out;
}


bool Proxy::NewOrder()
{
    vOrders.AddItem(*new Order(&vLog));
    vState.ActionSet(nAction::ID::Edit);
    vState.ViewSet(nView::ID::Order);
    return true;
}

Halls::pHallMap Proxy::HallsVacantOnDate(unsigned inDate)
{
    Halls::pHallMap out;

    Order::HallOptionMap vReservedHall = vSchedule.GetReservedHallsByDay(inDate);
    for( Halls::HallMap::iterator itH = vHalls.begin();
        itH != vHalls.end();
        ++itH)
    {
        bool bReserved=false;
        for(Order::HallOptionMap::iterator itR = vReservedHall.begin();
            itR != vReservedHall.end();
            ++itR)
        {
            if(itR->first->getIndex() == itH->first)
            {
                bReserved = true;
                break;
            }
        }

        if (!bReserved)
        {
            out.insert(make_pair(itH->first, &itH->second));
        }
    }
    return out;
}


}}
