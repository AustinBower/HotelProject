#include "loginscreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //set up the app and create a login screen and show it
    QApplication a(argc, argv);
    LoginScreen w;
    w.show();

    return a.exec();
}
