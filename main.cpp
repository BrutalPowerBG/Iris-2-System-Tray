#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
   // w.show();

    int showOrHide = w.settings->value("ShowOrHide", -1).toInt();
 //w->hide();
    if (showOrHide==-1)
    {
        w.settings->setValue("ShowOrHide", 0);
        w.hide();
    }
    else
    {
        if (showOrHide==0)
        {
            w.hide();
        }
        if (showOrHide==1)
        {
            w.show();
        }
    }
    return a.exec();
}
