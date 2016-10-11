#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent,
                       Proxy &inProxy,
                       Calendar &inCalendar,
                       vmHalls &inHalls,
                       vmOptions &inOptions,
                       vmOrders &inOrders,
                       vmParticipants &inParticipants) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    vProxy(inProxy),
    vCalendar(inCalendar),
    vHalls(inHalls),
    vOptions(inOptions),
    vOrders(inOrders),
    vParticipants(inParticipants)
{
    ui->setupUi(this);
    WidgetsSet();
    MenuSet();

    UpdateStatusBar("Users");
    ui->Users->setVisible(true);
    ui->vStackedWidget->setCurrentWidget(ui->Users);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MenuSet()
{
    QAction *vUsersAction = ui->menuBar->addAction("Users");
    connect(vUsersAction, SIGNAL(triggered()),this, SLOT(UsersGet()));

    QAction *vHallsAction = ui->menuBar->addAction("Halls");
    connect(vHallsAction, SIGNAL(triggered()), this, SLOT(HallsView()));

    QAction *vCalendarAction = ui->menuBar->addAction("Calendar");
    connect (vCalendarAction, SIGNAL(triggered()),this, SLOT(CalendarView()));

    QAction *vOptionsAction = ui->menuBar->addAction("Options");
    connect(vOptionsAction, SIGNAL(triggered()),this, SLOT(OptionsGet()));

    QAction *vOrdersAction = ui->menuBar->addAction("Orders");
    connect(vOrdersAction, SIGNAL(triggered()),this, SLOT(OrdersView()));

    QAction *vEmptyAction = ui->menuBar->addAction("               ");
    connect(vEmptyAction, SIGNAL(triggered()),this, SLOT(Dull()));
    vEmptyAction->setEnabled(false);
    vEmptyAction->setCheckable(false);

    QAction *vExitsAction = ui->menuBar->addAction("Exit");
    connect(vExitsAction, SIGNAL(triggered()),this, SLOT(Exit()));
}

void MainWindow::Exit()
{
    exit(0);
}

void MainWindow::Dull()
{

}

void MainWindow::VacantHallsByDay(unsigned iDay)
{
    HallsLayoutsClear();
    vHalls.setVacantHallsByDay(iDay, ui->vlHalls);
    SwitchPage(ui->Halls, "Vacant Halls");
}

void MainWindow::HallsView()
{
    HallsLayoutsClear();
    vHalls.HallsShow(ui->vlHalls);
    SwitchPage(ui->Halls, "All Halls");
}

void MainWindow::SwitchPage(QWidget* vWidget, string inMessage)
{
    QWidget* vCurrentWidget = ui->vStackedWidget->currentWidget();
    if (vCurrentWidget != nullptr)
    {
        vCurrentWidget->setVisible(false);
    }
    vWidget->update();
    vWidget->show();
    vWidget->setVisible(true);
    ui->vStackedWidget->setCurrentWidget(vWidget);
    inMessage.append(vProxy.GetStateAndClearLog());
    UpdateStatusBar(inMessage);
}

void MainWindow::HallsLayoutsClear()
{
    Common::ClearLayout(ui->vlHalls);
}
void MainWindow::CalendarView()
{
    SwitchPage(ui->Calendar, "Calendar");
}

void MainWindow::OptionsClearLayouts()
{
    Common::ClearLayout(ui->vlOptionsLeft);
    Common::ClearLayout(ui->vlOptionCenter);
    Common::ClearLayout(ui->vlOptionRight);
    Common::ClearLayout(ui->hlOptionBottom);
}

void MainWindow::OptionsGet()
{
    OptionsClearLayouts();
    if(nullptr != vProxy.OrdersGet()->Item())
    {
        switch(vProxy.StateGet()->ActionGet())
        {
        case nAction::ID::View:
            vOptions.List(ui->vlOptionsLeft, ui->vlOptionCenter, ui->vlOptionRight, ui->hlOptionBottom);
            break;

        case  nAction::ID::Edit:
            vOptions.Edit(ui->vlOptionsLeft, ui->vlOptionCenter, ui->vlOptionRight, ui->hlOptionBottom);
            break;

        default:
            vOptions.List(ui->vlOptionsLeft, ui->vlOptionCenter, ui->vlOptionRight, ui->hlOptionBottom);
            break;
        }
    }
    else // не всегда выбран заказ
    {
        vOptions.List(ui->vlOptionsLeft, ui->vlOptionCenter, ui->vlOptionRight, ui->hlOptionBottom);
    }
    OptionsShow();
    ui->vlOptionsLeft->update();
}

void MainWindow::OptionsShow()
{
    SwitchPage(ui->Options, "Options");
}
void MainWindow::UserClearLayouts()
{

}

void MainWindow::UsersGet()
{
    UserClearLayouts();

    switch(vProxy.UsersGet()->Item()->getRole()->getID())
    {
    case nRole::ID::Customer:
    case nRole::ID::Speaker:
    case nRole::ID::Participant:
        break;
    case nRole::ID::Manager:
        break;
    default:
        break;
    }
    UsersShow();
}
void MainWindow::OrderClearLayouts()
{
    Common::ClearLayout(ui->vlOrderList);
}

void MainWindow::OrdersView()
{
    OrderClearLayouts();
    vOrders.View(ui->vlOrderList);   //.HallsShow(ui->vlHalls);
    SwitchPage(ui->Order, "Orders");
}

void MainWindow::UsersShow()
{
    SwitchPage(ui->Users, "Users");
}

void MainWindow::WidgetsSet()
{
    CalendarSet();
}

void MainWindow::CalendarSet()
{
    const int vCols = 6;
    int r = 0, c = 0;
    for(map<unsigned,QPushButton*>::iterator it = vCalendar.Days()->begin();
        it != vCalendar.Days()->end();
        ++it)
    {
        ui->glCalendar->addWidget(it->second, r, c);
        ++c;
        if (c%vCols == 0)
        {
            ++r;
            c=0;
        }
    }
}


void MainWindow::on_bCustomer_clicked()
{
    if (ui->Users->isActiveWindow())
    {
        vProxy.UsersGet()->ItemSet(2);     // HardCoded
        SwitchPage(ui->Orders, "Orders");
    }
}

void MainWindow::on_bNewOrder_clicked()
{
    if(ui->Orders)
    {
        vProxy.NewOrder();
        SwitchPage(ui->Calendar, "Calendar");
    }
}

void MainWindow::UpdateStatusBar(string message)
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString::fromStdString(message));
}

void MainWindow::on_bSpeaker_clicked()
{
    if (ui->Users->isActiveWindow())
    {
        vProxy.UsersGet()->ItemSet(3);   // HardCoded
        SwitchPage(ui->Orders, "Orders");
    }
}

void MainWindow::on_bParticipant_clicked()
{
    if (ui->Users->isActiveWindow())
    {
        vProxy.UsersGet()->ItemSet(4);   // HardCoded
        SwitchPage(ui->Orders, "Orders");
    }
}

void MainWindow::on_bManager_clicked()
{
    if (ui->Users->isActiveWindow())
    {
        vProxy.UsersGet()->ItemSet(1);   // HardCoded
        SwitchPage(ui->Orders, "Orders");
    }
}
