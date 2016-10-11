#pragma once

#include <QMainWindow>

#include <Model/Proxy.h>


//ViewManager
#include <ViewManager/Calendar.h>
#include <ViewManager/vmHalls.h>
#include <ViewManager/vmOptions.h>
#include <ViewManager/vmOrders.h>
#include <ViewManager/vmParticipants.h>



using namespace EP::VM;
using namespace EP::MD;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent,
                        Proxy &inProxy,
                        Calendar &inCalendar,
                        vmHalls &inHalls,
                        vmOptions &inOptions,
                        vmOrders &inOrders,
                        vmParticipants &inParticipants);
    ~MainWindow();
public slots:
    void VacantHallsByDay(unsigned iDay);
    void HallsView();
    void CalendarView();

    void OptionsGet();
    void UsersGet();
    void OrdersView();

    void Exit();
    void Dull();
protected:
    void UpdateStatusBar(string message);

    void MenuSet();
    void OptionsShow();

    void OptionsClearLayouts();

    void HallsLayoutsClear();
    void SwitchPage(QWidget* vWidget, string inMessage = string());
    void UsersShow();
    void UserClearLayouts();
    void OrderClearLayouts();
private slots:
    void on_bCustomer_clicked();
    void on_bNewOrder_clicked();

    void on_bSpeaker_clicked();

    void on_bParticipant_clicked();

    void on_bManager_clicked();

private:
    Ui::MainWindow *ui;
    Proxy& vProxy;
    Calendar&  vCalendar;
    vmHalls& vHalls;
    vmOptions &vOptions;
    vmOrders& vOrders;
    vmParticipants& vParticipants;


    void WidgetsSet();
    void CalendarSet();
    void OptionsSet();
};
