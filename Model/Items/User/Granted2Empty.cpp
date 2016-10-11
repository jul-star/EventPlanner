#include "Granted2Empty.h"

namespace EP {
namespace MD {
Granted2Empty::Granted2Empty():
    Granted::Granted()
{
    InitializeGranted();
}

void Granted2Empty::InitializeGranted()
{
    vGranted.insert(make_pair(make_pair(nView::ID::Order, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Hall, nAction::ID::View), true));

    vGranted.insert(make_pair(make_pair(nView::ID::Option,  nAction::ID::View), true));

}

}}
