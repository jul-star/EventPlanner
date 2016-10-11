#include "ControlSettings.h"


namespace EP {
namespace VM {



ControlSettings::ControlSettings(QObject *parent,
                                 Proxy &inProxy,
                                 Calendar &inCalendar,
                                 vmHalls &inHalls,
                                 vmOptions &inOptions,
                                 vmOrders &inOrders,
                                 vmParticipants &inParticipants,
                                 MainWindow &inMainWindow):
    vParent(parent),
    vProxy(inProxy),
    vCalendar(inCalendar),
    vHalls(inHalls),
    vOptions (inOptions),
    vOrders(inOrders),
    vParticipants(inParticipants),
    vMainWindow(inMainWindow)
{
        SignalsSet();
}

void ControlSettings::SignalsSet()
{

    QObject::connect( &vCalendar, SIGNAL(ShowVacantHallsOnDay(unsigned)),
                      &vMainWindow, SLOT(VacantHallsByDay(unsigned)));

    QObject::connect(&vHalls, SIGNAL(EditOptions()),
                     &vMainWindow, SLOT(OptionsGet()));

}

}}
