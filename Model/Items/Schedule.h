#pragma once
#include <vector>
#include <Model/Items/Order/Order.h>

using namespace std;

namespace EP {
    namespace MD {
		/**
         * Расписание: Список Заказов на день
         *
		 */
		class Schedule
		{
            typedef vector<Order*> pOrdersVec;
            typedef  multimap<unsigned, Order*> DaypOrderMMap;

		public:
			Schedule();
			virtual ~Schedule();
            vector<unsigned>* Days(){return &vDays; }
            const vector<unsigned>* Days()const{return &vDays; }
            /*!
             * \brief HasVacantHallsByDay
             * \param inDay - Day on Schedule
             * \param NumberOfHalls - Number Of Halls Company Has
             * \return
             */
            bool HasVacantHallsByDay(unsigned inDay, size_t NumberOfHalls);
            /*!
             * \brief GetReservedHallsByDay
             * \param inDay
             * \return map<Hall_ID,Hall*>
             */
            Order::HallOptionMap GetReservedHallsByDay(unsigned inDay);

        protected:


            void DaysSetup();

		private:
            vector <unsigned> vDays;
            /*!
             * \brief vSchedule: <Day,Order*>
             */
            DaypOrderMMap vDayOrders;
            // map <unsigned, unsigned> vOrderDay;

		};
	}
}
