#pragma once

#include <QObject>

//Model
#include <Model/Proxy.h>

//ViewManager
#include <ViewManager/Calendar.h>
#include <ViewManager/vmHalls.h>
#include <ViewManager/vmOptions.h>
#include <ViewManager/vmOrders.h>
#include <ViewManager/vmParticipants.h>
#include <ViewManager/ControlSettings.h>

//View
#include <View/MainWindow.h>


using namespace std;
using namespace EP::VM;
using namespace EP::MD;
// using namespace EP::MD;

class StartUp final: public QObject
{
    Q_OBJECT
public:
    explicit StartUp();
    ~StartUp();
   void show() const;

private:
   // Model
    Proxy *vProxy{nullptr};

    Calendar &vCalendar;
    vmHalls &vHalls;
    vmOptions &vOptions;
    vmOrders &vOrders;
    vmParticipants &vParticipants;
    MainWindow &vMainWindow;


   ControlSettings &vControlSettings;






    //Block
    explicit StartUp(const StartUp& rhs) = delete;
    StartUp& operator= (const StartUp& rhs) = delete;


};
