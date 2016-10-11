///////////////////////////////////////////////////////////
//  Schedule.cpp
//  Implementation of the Class Schedule
//  Created on:      08-сен-2016 10:23:09
//  Original author: jstar
///////////////////////////////////////////////////////////
#include "Schedule.h"

namespace EP {
namespace MD {

Schedule::Schedule()
{
    DaysSetup();
}



Schedule::~Schedule()
{

}

bool Schedule::HasVacantHallsByDay(unsigned inDay, size_t NumberOfHalls)
{
    const Order* pOrder{nullptr};
    // Find all orders on the date
    int HallsCounter = 0;

      std::pair <DaypOrderMMap::iterator, DaypOrderMMap::iterator> ret;
      ret = vDayOrders.equal_range(inDay);
      for (DaypOrderMMap::iterator it=ret.first; it!=ret.second; ++it)
      {
          pOrder = it->second;
          for(EP::MD::Order::HallOptionMap::const_iterator itHO = pOrder->HallsGet()->cbegin();
             itHO != pOrder->HallsGet()->cend();
            ++itHO  )
          {
              // Can't be ordered one Hall on the same day
              ++HallsCounter;
          }
      }

      if (HallsCounter < NumberOfHalls )
      {
          return true;
      }
      else
      {
          return false;
      }
}

Order::HallOptionMap Schedule::GetReservedHallsByDay(unsigned inDay)
{
    Order::HallOptionMap out;
    std::pair<DaypOrderMMap::iterator, DaypOrderMMap::iterator> vRange = vDayOrders.equal_range(inDay);
    const Order* pOrder = nullptr;
    for(DaypOrderMMap::const_iterator it = vRange.first;
        it != vRange.second;
        ++it)
    {
        pOrder = it->second;
        for(EP::MD::Order::HallOptionMap::const_iterator itHO = pOrder->HallsGet()->cbegin();
           itHO != pOrder->HallsGet()->cend();
          ++itHO  )
        {
            out.insert(make_pair(itHO->first, itHO->second));
        }
    }
    return out;
}

void Schedule::DaysSetup()
{
    for(unsigned i = 1; i<31; ++i)
    {
        vDays.push_back(i);
    }
}


}
}
