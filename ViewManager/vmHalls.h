#pragma once

#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QSlider>
#include <QGroupBox>
#include <QCheckBox>
#include <QSignalMapper>


#include <Model/Items/Hall/Hall.h>
#include <Model/Proxy.h>

#include <ViewManager/Common.h>
#include <ViewManager/vmOptions.h>

using namespace std;
using namespace EP::MD;

namespace EP {
namespace VM {

class vmHalls : public QObject
{
    Q_OBJECT
public:
    explicit vmHalls(QObject *parent ,
                  Proxy &inProxy);
signals:
    void EditOptions();
public slots:
    void setVacantHallsByDay(unsigned iDay, QVBoxLayout *vQVBLayout);
    void HallsShow(QVBoxLayout *vQVBLayout);
    void AddHallToOrder(int HallId);
protected:

    void SeatsSliderGet(QSlider *slider, unsigned inHallId);

    void SetSeats(QVBoxLayout *vInnerLayout);

    void SetTables(QVBoxLayout *vInnerLayout);

    void SetTribunes(QVBoxLayout *vLayout);

    void TablesSliderGet(QSlider *slider, unsigned inHallId);

    void TribuneSliderGet(QSlider *slider);

private:
    Proxy& vProxy;



};

}}
