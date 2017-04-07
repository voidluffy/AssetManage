#include "logindialog.h"
#include "mainwidget.h"
#include "mainwindow.h"
#include <QApplication>
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWidget mainwidget;
    LoginDialog logindialog;

    MainWindow *w = new MainWindow;
    //w->show();
    //mainwidget.show();

    LoginWindow login;


    login.resize(800,700 );


    if(login.exec() == QDialog::Accepted)
    {
        mainwidget.show();
    }
    else
    {
        return 0;
    }
    return a.exec();
}
