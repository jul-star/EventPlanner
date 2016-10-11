#include "Granted2Customer.h"

namespace EP {
    namespace MD {
Granted2Customer::Granted2Customer()
{
    InitializeGranted();
}


void Granted2Customer::InitializeGranted()
{
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::Place), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::Edit), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::View), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::Delete), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Hall, nAction::ID::Edit), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Hall, nAction::ID::View), true));


    vGranted.insert(make_pair(make_pair(nView::ID::Option, nAction::ID::Edit), true));
    vGranted.insert(make_pair(make_pair(nView::ID::Option, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Schedule, nAction::ID::View), true));

}

    }}
