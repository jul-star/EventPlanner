#pragma once
#include <string>
#include <vector>

using namespace std;

namespace EP {
	namespace MD {
		/**
		 * Список Участников
		 */
		class ParticipantsList
		{
			// TODO: Implement!!! ParticipantsList
		public:
			ParticipantsList(string inListName=string(""));
			virtual ~ParticipantsList();

            void addParticipant(unsigned inMember);
			string getListName();
            vector<unsigned>* getParticipants();
            bool removeParticipant(unsigned inMember);
			void setListName(string inName);

		private:
            vector<unsigned> vParticipants;
			string vListName;

		};
	}
}

