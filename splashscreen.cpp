#include "splashscreen.h"
#include "ui_splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    mWindow.setWindowFlags(Qt::FramelessWindowHint);
    QPropertyAnimation *animIn = new QPropertyAnimation(this,"windowOpacity",this);
    animIn->setDuration(500);
    animIn->setStartValue(0.0);
    animIn->setEndValue(1.0);
    animIn->start();
    QPropertyAnimation *animMiddle = new QPropertyAnimation(this,"windowOpacity",this);
    animMiddle->setDuration(3000);
    animMiddle->setStartValue(1.0);
    animMiddle->setEndValue(1.0);

    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);

    connect(animIn,SIGNAL(finished()),animMiddle,SLOT(start()));
    connect(animMiddle,SIGNAL(finished()),animOut,SLOT(start()));
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    connect(animOut,SIGNAL(finished()),&mWindow,SLOT(show()));





}

SplashScreen::~SplashScreen()
{
    delete ui;
}
