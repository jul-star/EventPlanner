#include "StartUp.h"

StartUp::StartUp():
        QObject(nullptr),
        vProxy(new Proxy()),
        vCalendar(*new Calendar(this,*vProxy)),
        vHalls(*new vmHalls(this,*vProxy)),
        vOptions(*new vmOptions(this, *vProxy)),
        vOrders(*new vmOrders(this, *vProxy)),
        vParticipants(*new vmParticipants(this, *vProxy)),
        vMainWindow(*new MainWindow(nullptr,
                                                        *vProxy,
                                                        vCalendar,
                                                        vHalls,
                                                        vOptions,
                                                        vOrders,
                                                        vParticipants)),
        vControlSettings(*new ControlSettings((QObject*)this,
                                                              *vProxy,
                                                              vCalendar,
                                                              vHalls,
                                                              vOptions,
                                                              vOrders,
                                                              vParticipants,
                                                             vMainWindow))

{

}

StartUp::~StartUp()
{
 delete vProxy;

}

void StartUp::show() const
{
  vMainWindow.show();

}
