#include "Granted2Manager.h"

namespace EP {
    namespace MD {
Granted2Manager::Granted2Manager():
    Granted::Granted()
{

}

void Granted2Manager::InitializeGranted()
{
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::Accept), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::View), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::Close), true));


    vGranted.insert(make_pair(make_pair(nView::ID::Option, nAction::ID::View), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Option,  nAction::ID::Edit), true));

    vGranted.insert(make_pair(make_pair(nView::ID::ParticipantList, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::User, nAction::ID::View), true));
    vGranted.insert(make_pair(make_pair(nView::ID::User, nAction::ID::Edit), true));
    vGranted.insert(make_pair(make_pair(nView::ID::User, nAction::ID::Delete), true));

}
    }}
