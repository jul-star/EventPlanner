#include "vmHalls.h"


namespace EP {
namespace VM {
vmHalls::vmHalls(QObject *parent, Proxy &inProxy) :
    QObject(parent),
     vProxy(inProxy)
{

}

void vmHalls::AddHallToOrder(int HallId)
{
    unsigned vID = (unsigned)HallId;
    vProxy.OrdersGet()->Item()->HallAdd(vProxy.HallsGet()->GetByID(vID));
    vProxy.HallsGet()->ItemSet(vID);
    emit EditOptions();
}

void vmHalls::setVacantHallsByDay(unsigned iDay, QVBoxLayout *vQVBLayout)
{    
    Halls::pHallMap vHalls;
    Hall* vCurrentHall = nullptr;
    vHalls = vProxy.HallsVacantOnDate(iDay);
   Halls::pHallMap::iterator next;
    for(Halls::pHallMap::iterator it = vHalls.begin();
        it != vHalls.end();
        ++it)
    {
        // Hall

       vCurrentHall = ((Hall*)(it->second));
       string vStr(to_string(vCurrentHall->getIndex()));
       vStr.append(vCurrentHall->View(vProxy.UsersGet()->Item()->getRole()->getID()));
       QLabel* lbl = new QLabel();
       lbl->setBackgroundRole(QPalette::ColorRole::BrightText);
       lbl->setText(QString::fromStdString(vStr));
       vQVBLayout->addWidget(lbl);
       if(vProxy.UsersGet()->Item()->getRole()->Permission()->isGranted(nView::ID::Order, nAction::ID::Edit))
       {
            QPushButton *btn = new QPushButton();
            Common::QPushButtonAppeareanceSet(btn);
            btn->setText("Add to Order");
            //@@!!!!!!!!!!!!!@@//
            QSignalMapper *smTmp = new QSignalMapper(this);
            connect(btn,SIGNAL(clicked()),smTmp, SLOT(map()));
            smTmp->setMapping(btn,(int)vCurrentHall->getIndex());
            connect(smTmp,SIGNAL(mapped(int)), this,SLOT(AddHallToOrder(int)));

            vQVBLayout->addWidget(btn);
       }

        next = it; ++next;
       if ((next) != vHalls.end())
       {
           QFrame* hFrame = new QFrame;
           hFrame->setFrameShape(QFrame::HLine);
           vQVBLayout->addWidget(hFrame);
       }
    }

}

void vmHalls::HallsShow(QVBoxLayout *vQVBLayout)
{
    Halls* vHalls  = vProxy.HallsGet();
    Hall* vCurrentHall = nullptr;
    Halls::HallMap::iterator next;
    for(Halls::HallMap::iterator it = vHalls->begin();
        it != vHalls->end();
        ++it)
    {
        // Hall

       vCurrentHall = ((Hall*)(&it->second));
       string vStr(to_string(vCurrentHall->getIndex()));
       vStr.append(vCurrentHall->View(vProxy.UsersGet()->Item()->getRole()->getID()));
       Common::AddLabel(vQVBLayout, QString::fromStdString(vStr));
       next = it;
       ++next;
       if ((next) != vHalls->end())
       {
           QFrame* hFrame = new QFrame;
           hFrame->setFrameShape(QFrame::HLine);
           vQVBLayout->addWidget(hFrame);
       }
    }
}


}}
