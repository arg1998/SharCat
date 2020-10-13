#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QPropertyAnimation>
#include <QDebug>


namespace Ui {
class SplashScreen;
}

class SplashScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent = 0);
    ~SplashScreen();

private:
    Ui::SplashScreen *ui;
    MainWindow mWindow;
};

#endif // SPLASHSCREEN_H
