#include "PWManager.h"
#include "login.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Lucida Sans Unicode");
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);

    PWManager w;
    w.show();
    return a.exec();
}
