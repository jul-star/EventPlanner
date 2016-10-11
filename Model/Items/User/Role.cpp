///////////////////////////////////////////////////////////
//  Role.cpp
//  Implementation of the Class Role
//  Created on:      08-сен-2016 10:23:08
//  Original author: jstar
///////////////////////////////////////////////////////////
#include "Role.h"

namespace EP {
	namespace MD {

        Role::Role(nRole::ID inID) :
			vID(inID)
		{
			setNameByRole(vID);
            setGrantedByRole(vID);
		}



		Role::~Role() {
            delete pGranted;
		}

        void Role::setNameByRole(nRole::ID inID)
		{
			switch (inID)
			{
            case nRole::ID::Manager:
				vName = string("Manager");
				break;
            case nRole::ID::Customer:
				vName = string("Customer");
				break;
            case nRole::ID::Speaker:
				vName = string("Speaker");
				break;
            case nRole::ID::Participant:
				vName = string("Participant");
				break;
			default:
				vName = string("Guest");
				break;
            }
        }

        void Role::setGrantedByRole(nRole::ID inID)
        {
            switch (inID)
            {
            case nRole::ID::Manager:
                pGranted = new Granted2Manager();
                break;
            case nRole::ID::Customer:
                pGranted = new Granted2Customer();
                break;
            case nRole::ID::Speaker:
                pGranted = new Granted2Speaker();
                break;
            case nRole::ID::Participant:
                pGranted = new Granted2Participant();
                break;
            default:
                pGranted = new Granted2Empty();
                break;
            }
        }


		string Role::getName() const
		{

			return  vName;
		}


        void Role::setID(nRole::ID inRoleId)
		{
			vID = inRoleId;
		}

        nRole::ID Role::getID() const
		{
			return vID;
		}

		void Role::setName(string inName) {

		}


	}
}
