#pragma once

#include <vector>
#include <map>

#include <Model/Constants.h>

#include <Model/Context/Halls.h>
#include <Model/Context/Users.h>
#include <Model/Context/Orders.h>


#include <Model/Items/Planner.h>
#include <Model/Items/Schedule.h>
#include <Model/Communication/Log.h>

#include <Model/State.h>

using namespace std;

namespace EP {
namespace MD {


class Proxy
{

public:


    Proxy();
    virtual ~Proxy();

    string ShowHalls(const vector<Hall *> *halls);
    Halls::pHallMap HallsVacantOnDate(unsigned inDate);

    Halls::pHallMap getReservedHalls4Orders(vector<Order *> *inOrders);
    void SetCurrentUser(unsigned inID);


    Halls* HallsGet() {return &vHalls; }
    const Halls* HallsGet() const {return &vHalls; }

    Users* UsersGet() {return &vUsers; }
    const Users* UsersGet() const {return &vUsers; }

    Orders* OrdersGet() {return &vOrders; }
    const Orders* OrdersGet() const {return &vOrders; }

    /*!
     * \brief NewOrder Create new Order and add it to Orders.
     * \return true on Success
     */
    bool NewOrder();

    Schedule* ScheduleGet() { return &vSchedule; }
    const Schedule* ScheduleGet() const { return &vSchedule; }

    /*!
     * \brief LogGet
     * \return &vLog
     */
    Log* LogGet() { return &vLog; }
    const Log* LogGet() const { return &vLog; }
    /*!
     * \brief GetStateAndClearLog
     * \return Messages from Objects which wrote to Log
     */
    string GetStateAndClearLog();
    State* StateGet() { return &vState; }
    const State* StateGet() const { return &vState; }
    /*!
     * \brief OptionGet - Current Option
     * \return Option*
     */
    const Option *OptionGet() const;



protected:


private:
    Log &vLog;
    Halls &vHalls;
    Users &vUsers;
    Orders &vOrders;

    Planner &vPlanner;
    Schedule &vSchedule;
    State &vState;




};

}}
