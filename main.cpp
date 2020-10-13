#include "mainwindow.h"
#include "splashscreen.h"
#include <QApplication>
#include <QDebug>


#include "CoreEngine/corefunctions.h"






int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DirectoryInteractions::SetUpDirectories();
    DirectoryInteractions::SetUpFiles();


    SplashScreen sc;
    sc.setWindowFlags(Qt::SubWindow | Qt::WindowTitleHint | Qt::FramelessWindowHint | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    sc.setGeometry(483,284,sc.width(),sc.height());
    sc.show();




    return a.exec();
}
