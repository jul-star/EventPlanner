#include "ParticipantsList.h"

namespace EP {
	namespace MD {
		ParticipantsList::ParticipantsList(string inListName):
			vListName(inListName)
		{

		}


        void ParticipantsList::addParticipant(unsigned inMember)
		{
			vParticipants.push_back(inMember);
		}

		string ParticipantsList::getListName()
		{
			return vListName;
		}

        vector<unsigned> *ParticipantsList::getParticipants()
		{
			return &vParticipants;
		}

        bool ParticipantsList::removeParticipant(unsigned inMember)
		{

            for (vector<unsigned>::const_iterator it = vParticipants.cbegin();
				it != vParticipants.cend();
				++it)
			{
				if (*it == inMember)
				{
					vParticipants.erase(it);
					return true;
				}
			}
			return false;
		}

		void ParticipantsList::setListName(string inName)
		{
			vListName = inName;
		}

		ParticipantsList::~ParticipantsList() {

		}
	}
}
