#include "Calendar.h"

namespace EP {
namespace VM {
Calendar::Calendar(QObject *parent, Proxy &inProxy):
    QObject(parent),
    vProxy(inProxy)
{
    CreateDayButtons();
    SetSignals();
}

Calendar::~Calendar()
{
    for(DayButtonType::iterator it = vDays.begin();
        it != vDays.end();
        ++it)
    {
        delete it->second;
    }
}



void Calendar::CreateDayButtons()
{
    Schedule *pSchedule = vProxy.ScheduleGet();
    for(DaysType::const_iterator it =  pSchedule->Days()->cbegin();
        it != pSchedule->Days()->cend();
        ++it)
    {
        QPushButton *pButton =  new QPushButton(QString::number(*it));
        Common::QPushButtonAppeareanceSet(pButton);

        if(!pSchedule->HasVacantHallsByDay(*it, vProxy.HallsGet()->Size()))
        {
            pButton->setEnabled(false);
        }
        vDays.insert(make_pair(*it,pButton));
    }
}

void Calendar::SetSignals()
{
    for(DayButtonType::iterator it = vDays.begin();
        it != vDays.end();
        ++it)
    {
        QObject::connect(it->second, SIGNAL(clicked()), this, SLOT(clickedSlot()));
        //        (QPushButton*)(it->second)->setSizePolicy(QSizePolicy::Minimum);
    }
}




void Calendar::clickedSlot()
{
    QString vButton = ((QPushButton*)sender())->text();
    unsigned iDay = (unsigned)vButton.toInt();
    //    perror(vButton.toStdString().c_str());
    if (vProxy.OrdersGet()->Item()  !=  nullptr)
    {
        if(vProxy.StateGet()->ActionGet() == nAction::ID::Edit)
        {
            vProxy.OrdersGet()->Item()->setDate(iDay);
        }
    }
        emit ShowVacantHallsOnDay(iDay);
}


}}
