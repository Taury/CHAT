#include "mainwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWin w;
    w.show();

    QIcon icon("image/robot.png");
    a.setWindowIcon(icon);

    return a.exec();
}
