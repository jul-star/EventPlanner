#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T09:51:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EventPlanner
TEMPLATE = app

QMAKE_CXXFLAGS = -std=c++11

FORMS += \
    View/MainWindow.ui

HEADERS += \
    Model/Communication/Log.h \
    Model/Communication/Talk.h \
    Model/Context/Halls.h \
    Model/Context/Orders.h \
    Model/Context/TemplateMethodMap.hpp \
    Model/Context/Users.h \
    Model/Items/Hall/Hall.h \
    Model/Items/Hall/Item.h \
    Model/Items/Hall/Option.h \
    Model/Items/Order/Order.h \
    Model/Items/Order/ParticipantsList.h \
    Model/Items/User/Granted.h \
    Model/Items/User/Granted2Customer.h \
    Model/Items/User/Granted2Empty.h \
    Model/Items/User/Granted2Manager.h \
    Model/Items/User/Granted2Participant.h \
    Model/Items/User/Granted2Speaker.h \
    Model/Items/User/Role.h \
    Model/Items/User/User.h \
    Model/Items/Planner.h \
    Model/Items/Schedule.h \
    Model/Constants.h \
    Model/Proxy.h \
    Model/State.h \
    View/MainWindow.h \
    ViewManager/Calendar.h \
    ViewManager/Common.h \
    ViewManager/ControlSettings.h \
    ViewManager/vmHalls.h \
    ViewManager/vmOptions.h \
    ViewManager/vmOrders.h \
    ViewManager/vmParticipants.h \
    StartUp.h

SOURCES += \
    Model/Communication/Log.cpp \
    Model/Communication/Talk.cpp \
    Model/Context/Halls.cpp \
    Model/Context/Orders.cpp \
    Model/Context/Users.cpp \
    Model/Items/Hall/Hall.cpp \
    Model/Items/Hall/Item.cpp \
    Model/Items/Hall/Option.cpp \
    Model/Items/Order/Order.cpp \
    Model/Items/Order/ParticipantsList.cpp \
    Model/Items/User/Granted.cpp \
    Model/Items/User/Granted2Customer.cpp \
    Model/Items/User/Granted2Empty.cpp \
    Model/Items/User/Granted2Manager.cpp \
    Model/Items/User/Granted2Participant.cpp \
    Model/Items/User/Granted2Speaker.cpp \
    Model/Items/User/Role.cpp \
    Model/Items/User/User.cpp \
    Model/Items/Planner.cpp \
    Model/Items/Schedule.cpp \
    Model/Constants.cpp \
    Model/Proxy.cpp \
    Model/State.cpp \
    View/MainWindow.cpp \
    ViewManager/Calendar.cpp \
    ViewManager/Common.cpp \
    ViewManager/ControlSettings.cpp \
    ViewManager/vmHalls.cpp \
    ViewManager/vmOptions.cpp \
    ViewManager/vmOrders.cpp \
    ViewManager/vmParticipants.cpp \
    main.cpp \
    StartUp.cpp

