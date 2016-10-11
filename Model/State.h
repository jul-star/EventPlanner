#pragma once

#include <Model/Constants.h>

using namespace std;

namespace EP {
namespace MD {
class State
{
public:
    State();
    void ActionSet( nAction::ID inAction ){ vAction = inAction; }
    nAction::ID ActionGet(){ return vAction; }
    void ViewSet( nView::ID inView){ vView = inView; }
     nView::ID ViewGet(){ return vView;}
private:
    nAction::ID vAction;
    nView::ID vView;

};

}}
