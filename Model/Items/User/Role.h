#pragma once
#include <string>
// #include <map>
#include <Model/Constants.h>
#include <Model/Items/user/Granted.h>
#include <Model/Items/user/Granted2Customer.h>
#include <Model/Items/user/Granted2Manager.h>
#include <Model/Items/user/Granted2Speaker.h>
#include <Model/Items/user/Granted2Participant.h>
#include <Model/Items/user/Granted2Empty.h>

using namespace std;

namespace EP {
	namespace MD {

		class Role
		{

		public:
            Role(nRole::ID inID);
			virtual ~Role();
			string getName() const;
            //bool isGranted(nEvent inAction);
            //bool setActionGrant(nEvent inAction, bool inGranted);
			void setName(string inName);
            nRole::ID getID() const;
            void setID(nRole::ID inRoleId);
            const Granted* Permission() const {return pGranted;}

		protected:
            void setNameByRole(nRole::ID inID);
            void setGrantedByRole(nRole::ID inID);
		private:
			string vName;
            nRole::ID vID;
            Granted* pGranted{nullptr};
            //map<nEvent, bool> vActionsGranted;

		};

		inline bool operator==(const Role& lhs, const Role& rhs)
		{
			return lhs.getName() == rhs.getName() \
				&& lhs.getID() == rhs.getID();
		}

	}
}

