///////////////////////////////////////////////////////////
//  User.h
//  Implementation of the Class User
//  Created on:      08-сен-2016 10:23:17
//  Original author: jstar
///////////////////////////////////////////////////////////

#if !defined(EA_75FAD7BF_E152_4614_9FBA_7AD4D8884223__INCLUDED_)
#define EA_75FAD7BF_E152_4614_9FBA_7AD4D8884223__INCLUDED_

#pragma  once
#include <vector>
#include <Model/Items/Order/Order.h>
#include <Model/Items/User/Role.h>
#include <Model/Communication/Talk.h>

using namespace std;

namespace EP {
	namespace MD {
		/**
		 * Пользователь
		 */
                class User:public Talk
		{

		public:
			User(
				string inFirstName,
				string inLastdName,
				Role &inRole,
				string inPhone = string(""),
                                string inEmail = string(""),
                                Log* inLog=nullptr
				);
			User(const User& rhs);
			User& operator=(const User& rhs);
            friend bool operator==(const User& lhs, const User& rhs);

			virtual ~User();


			string getEmail() const;
			string getFirstName()  const;
			string getLastName() const;
			void setEmail(string inEmail);
			void setFirstName(string inName);
			void setLastName(string inSecondName);
			void setRole(Role &role);
            const Role* getRole() const{ return pRole;}
            map<unsigned, Order*>* getOrders() { return &vOrders; }
            const map<unsigned, Order*>* getOrders() const { return &vOrders; }

            unsigned getID() const;

			string getOrderInfo(const unsigned inOrderId);

			static unsigned vUserCounter;

		private:

			unsigned vID;
			string vFirstName;
			string vLastName;
            Role *pRole{nullptr};
			string vEmail;
			string vPhone;
			map<unsigned, Order*> vOrders;

		};

		inline bool operator==(const User& lhs, const User& rhs)
		{
            return lhs.vEmail == rhs.vEmail \
                && lhs.vLastName == rhs.vLastName\
                && lhs.vFirstName == rhs.vFirstName ;
		}


	}
}
#endif // !defined(EA_75FAD7BF_E152_4614_9FBA_7AD4D8884223__INCLUDED_)
