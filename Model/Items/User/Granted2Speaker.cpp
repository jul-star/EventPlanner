#include "Granted2Speaker.h"

namespace EP {
    namespace MD {
Granted2Speaker::Granted2Speaker():
    Granted::Granted()
{
InitializeGranted();
}

void Granted2Speaker::InitializeGranted()
{
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Hall, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Option,  nAction::ID::Edit), true));

    vGranted.insert(make_pair(make_pair(nView::ID::ParticipantList, nAction::ID::View), true));
}

    }}
