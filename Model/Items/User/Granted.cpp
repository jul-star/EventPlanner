#include "Granted.h"

namespace EP {
	namespace MD {
		Granted::Granted()
		{

		}

		Granted::~Granted()
		{
		}



        bool Granted::isGranted(nView::ID inView, nAction::ID inAction) const
        {
            pair<nView::ID, nAction::ID> vKey = make_pair(inView,inAction);
            if ( vGranted.find(vKey) != vGranted.end())
            {
                return  vGranted.at(vKey);
            }
            else
            {
                return false;
            }
        }


	}
}
