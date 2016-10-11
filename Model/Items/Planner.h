#pragma once
#include <vector>
#include <Model/Items/User/User.h>
#include <Model/Items/Order/Order.h>

using namespace std;

namespace EP {
	namespace MD {
		/**
		 * Планировщик
		 */
		class Planner
		{
			// TODO: Implement!!!! class Planner
		public:
			Planner();
			virtual ~Planner();

            bool addReminder(const Order *inOrder);
			bool sendEMail(const vector<User>* inUsers);

		};
	}
}
