#include <QApplication>
#include "StartUp.h"

int main(int argc, char *argv[])
{
    // Sets whether Qt should use the system's standard colors, fonts, etc.
    QApplication::setDesktopSettingsAware(false);

    QApplication a(argc, argv);


    StartUp st; /// вызов и инициализация: чтение настроек по умолчанию...
    st.show();


    return a.exec();
}
