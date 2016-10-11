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
#include <Model/Items/Hall/Option.h>
#include <Model/Items/Order/ParticipantsList.h>
#include <Model/Items/Schedule.h>
#include <Model/Constants.h>
#include <Model/Proxy.h>



using namespace std;
using namespace EP::MD;

namespace EP {
namespace VM {

class Common
{
public:

    static void AddLabel(QVBoxLayout *vLayout, QString str);
    static void SetCheckBox(QVBoxLayout *vLayout, QString str, QObject* receiver, void(*f)(int));
    static void SliderAppearance(QSlider *vSlider);

    static void ClearLayout(QLayout *layout);
    static void QPushButtonAppeareanceSet(QPushButton *pButton);
private:
    Common()=delete;
};

}}
