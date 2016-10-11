#pragma once
#include <vector>

#include <Model/Context/Halls.h>
#include <Model/Items/Hall/Hall.h>
#include <Model/Items/Hall/Option.h>
#include <Model/Items/Order/ParticipantsList.h>
#include <Model/Communication/Talk.h>


namespace EP {
	namespace MD {

using namespace std;


		/**
		 * Заказ
		 */
        class Order: public Talk
		{
		public:
            typedef map<Hall*, Option> HallOptionMap;
            Order(Log* inLog);
			virtual ~Order();
			Order(const Order& rhs);
			Order& operator=(const Order& rhs);

            bool HallAdd(Hall *inHall);

            const HallOptionMap* HallsGet() const;

			unsigned getIndex() const;
            string getInfo(nRole::ID inUserRole) const;
            void setDate(unsigned inDate);
            unsigned getDate() const{return vDate;}

            string getDescription() const            {return  vDescription; }

            void setDescription(string inDescription){ vDescription = inDescription; }

//            void Close() { setStatus(nsEnums::nsEvent::Status::Close);}
//            void Accept() {setStatus(nsEnums::nsEvent::Status::Active); }
//            // TODO: Implement Order::Delete()
//            void Delete(){ setStatus(nsEnums::nsEvent::Status::Close); }
//            void StateSet(nsEnums::nsState::nsOrder::ID inOrderState){vOrderState=inOrderState;}
//            bool isEdit() { return vOrderState == nsEnums::nsState::nsOrder::ID::Edit; }

		protected:
            // void setStatus(nsEnums::nsEvent::Status inStatus) { vStatus = inStatus; }

		private:
			static unsigned vOrderCounter;
			unsigned int vIndex;
            /*!
             * \brief unsigned = HallID!!!
             */
            HallOptionMap vHallOptions;
            ParticipantsList vParticipantsList;

            unsigned vDate{0};

            bool IsUserKeyPlayer(unsigned inUserId) const;
           string vDescription;


//           nsEnums::nsEvent::Status vStatus;
//           nAction::ID vOrderState{nAction::ID::View};

		};


	}
}

