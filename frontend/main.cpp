#include <QApplication>
#include <QPushButton>
#include <QWindow>
#include "windows/mainwindow.h"
#include "cpr/cpr.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow main;
    main.show();
    return QApplication::exec();
}
