#pragma once

#include <QObject>
#include <QWidget>

//Model
#include <Model/Proxy.h>

//ViewManager
#include <ViewManager/Calendar.h>
#include <ViewManager/vmHalls.h>
#include <ViewManager/vmOrders.h>
#include <ViewManager/vmParticipants.h>


//View
#include <View/MainWindow.h>

using namespace EP::MD;

namespace EP {
namespace VM {

class ControlSettings : public QObject
{
    Q_OBJECT
public:
    explicit ControlSettings(QObject *parent,
                                         Proxy& inProxy,
                                         Calendar& inCalendar,
                                         vmHalls&   inHalls,
                                         vmOptions& inOptions,
                                         vmOrders&   inOrders,
                                         vmParticipants&  inParticipants,
                                         MainWindow& inMainWindow);

signals:

public slots:

protected:
    void SignalsSet();
private:
    QObject *vParent;

    Proxy& vProxy;
    Calendar&  vCalendar;
    vmHalls& vHalls;
    vmOptions &vOptions;
    vmOrders& vOrders;
    vmParticipants& vParticipants;
    MainWindow& vMainWindow;

};
}}
