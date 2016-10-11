#include "Granted2Participant.h"

namespace EP {
namespace MD {
Granted2Participant::Granted2Participant():
    Granted::Granted()
{

    InitializeGranted();
}

void Granted2Participant::InitializeGranted()
{
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Hall, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Option,  nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::ParticipantList, nAction::ID::View), true));
}

}}
