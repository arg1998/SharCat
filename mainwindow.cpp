#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),date(new QDate)
{
    ui->setupUi(this);
    LoadTheme();

    QPropertyAnimation *animIn = new QPropertyAnimation(this,"windowOpacity",this);
    animIn->setDuration(700);
    animIn->setStartValue(0.0);
    animIn->setEndValue(1.0);
    animIn->start();

    //set up the clock
    QString textDate = date->currentDate().toString();
    ui->label_Date->setText(textDate);
    this->setMouseTracking(true);
    timer = new QTimer(this);
    time = new QTime();
    ClockUpdate();
    connect(timer,SIGNAL(timeout()),this,SLOT(ClockUpdate()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool colon = true;
void MainWindow::ClockUpdate()
{

    int hour = time->currentTime().hour();
    int minut = time->currentTime().minute();
    QString sHour = QString::number(hour) , sMinut =QString::number(minut);
    if(hour < 10){sHour = " " + QString::number(hour);}
    if(minut < 10){sMinut = " " + QString::number(minut);}
    if(colon)
    {
    ui->label_Clock->setText(sHour + ":" + sMinut);
    colon = false;
    }
    else
    {
        ui->label_Clock->setText(sHour + " " + sMinut);
        colon = true;
    }
}



void MainWindow::on_pushButton_exit_clicked()
{
    anim = new QPropertyAnimation(this,"windowOpacity",this);
    anim->setDuration(1000);
    anim->setStartValue(this->windowOpacity());
    anim->setEndValue(0.0);
    anim->start();
    connect(anim,SIGNAL(finished()),this,SLOT(close()));

}

void MainWindow::on_pushButton_AddStudent_clicked()
{
    AddStudentForm = new AddStudent(this);
    AddStudentForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    AddStudentForm->setWindowModality(Qt::WindowModal);
    AddStudentForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    AddStudentForm->show();
}

void MainWindow::on_pushButton_AddTeacher_clicked()
{
    AddTeacherForm = new AddTeacher(this);
    AddTeacherForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    AddTeacherForm->setWindowModality(Qt::WindowModal);
    AddTeacherForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    AddTeacherForm->show();
}

void MainWindow::on_pushButton_AddStaff_clicked()
{
    AddStaffForm = new AddStaff(this);
    AddStaffForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    AddStaffForm->setWindowModality(Qt::WindowModal);
    AddStaffForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    AddStaffForm->show();
}

void MainWindow::on_pushButton_EditInfo_clicked()
{
    EditInformationForm = new EditInformation(this);
    EditInformationForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    EditInformationForm->setWindowModality(Qt::WindowModal);
    EditInformationForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    EditInformationForm->show();
}

void MainWindow::on_pushButton_BackUp_Restore_clicked()
{
    BackUpForm = new BackUp(this);
    BackUpForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    BackUpForm->setWindowModality(Qt::WindowModal);
    BackUpForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    BackUpForm->show();
}

void MainWindow::on_pushButton_ShowInfo_clicked()
{
    ShowInformationForm = new ShowInformation(this);
    ShowInformationForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    ShowInformationForm->setWindowModality(Qt::WindowModal);
    ShowInformationForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    ShowInformationForm->show();
}

void MainWindow::on_pushButton_lock_clicked()
{
    LockForm = new Lock(this);
    LockForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    LockForm->setWindowModality(Qt::WindowModal);
    LockForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    LockForm->show();
}

void MainWindow::on_pushButton_aboutUS_clicked()
{
    AboutUsForm = new AboutUs(this);
    AboutUsForm->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    AboutUsForm->setWindowModality(Qt::WindowModal);
    AboutUsForm->setGeometry(this->x(),this->y(),this->width(),this->height());
    AboutUsForm->show();
}

void MainWindow::on_pushButton_setting_clicked()
{
    settings = new Settings(this);
    settings->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    settings->setWindowModality(Qt::WindowModal);
    settings->setGeometry(this->x(),this->y(),this->width(),this->height());
    settings->show();
}

void MainWindow::on_pushButton_Instagram_clicked()
{

}

void MainWindow::on_pushButton_Telegarm_clicked()
{
    QString link = "https://t.me/QtOnlineCourseFa";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_pushButton_Facebook_clicked()
{
    QString link = "http://www.Facebook.com";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_pushButton_Youtube_clicked()
{
    QString link = "https://www.youtube.com/playlist?list=PL2D1942A4688E9D63";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_pushButton_Twitter_clicked()
{
    QString link = "http://twitter.com/qtproject";
    QDesktopServices::openUrl(QUrl(link));
}
