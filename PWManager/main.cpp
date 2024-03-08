#include "PWManager.h"
#include "login.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PWManager w;
    w.show();
    return a.exec();
}
