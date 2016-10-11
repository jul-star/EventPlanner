#pragma once

#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <map>

#include <Model/Proxy.h>
#include <Model/Items/Schedule.h>
#include <ViewManager/Common.h>

using namespace std;
using namespace EP::MD;

namespace EP {
namespace VM {



class Calendar: public QObject
{
        Q_OBJECT
public:
    typedef map<unsigned, QPushButton*> DayButtonType;
    typedef vector<unsigned> DaysType;
  //   enum DayType {button, label};
    Calendar(QObject *parent, Proxy& inProxy);
    ~Calendar();
    void CreateDayButtons();
    void SetSignals();
    map<unsigned,QPushButton*>* Days(){ return &vDays; }
    const map<unsigned,QPushButton*>* Days()const { return &vDays; }

signals:
    void ShowVacantHallsOnDay(unsigned iDay);

public slots:
    void clickedSlot();

protected:

private:
    DayButtonType vDays;
    // map<int,pair<DayType,void*>> vDays;
    Proxy& vProxy;



};

}}
