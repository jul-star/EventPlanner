#pragma once

#include <map>
#include <Model/Constants.h>
using namespace std;

namespace EP {
	namespace MD {
		class Granted
		{
		public:
            typedef map<pair<nView::ID, nAction::ID>,bool> isGrantedMap;
			Granted();
            virtual ~Granted();
            bool isGranted(nView::ID inView, nAction::ID inAction) const;
		protected:
            virtual void InitializeGranted() =0;
            isGrantedMap vGranted;
		private:

		};
	}
}
