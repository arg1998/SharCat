#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>
#include <QTime>
#include <QPropertyAnimation>
#include <QDate>
#include <QDesktopServices>

#include "CoreEngine/corefunctions.h"
#include "addstudent.h"
#include "addteacher.h"
#include "addstaff.h"
#include "editinformation.h"
#include "backup.h"
#include "sharcatconsole.h"
#include "showinformation.h"
#include "lock.h"
#include "aboutus.h"
#include "settings.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTime *time;
    QDate *date;
    QPropertyAnimation *anim;

    AddStudent *AddStudentForm;
    AddTeacher *AddTeacherForm;
    AddStaff *AddStaffForm;
    EditInformation *EditInformationForm;
    BackUp *BackUpForm;
    SharCatConsole *ConsoleForm;
    ShowInformation *ShowInformationForm;
    Lock *LockForm;
    AboutUs *AboutUsForm;
    Settings *settings;



    int Xbefore;
    int Ybefore;


private slots:
    void ClockUpdate();
    void on_pushButton_exit_clicked();
    void on_pushButton_AddStudent_clicked();
    void on_pushButton_AddTeacher_clicked();
    void on_pushButton_AddStaff_clicked();
    void on_pushButton_EditInfo_clicked();
    void on_pushButton_BackUp_Restore_clicked();
    void on_pushButton_ShowInfo_clicked();
    void on_pushButton_lock_clicked();
    void on_pushButton_aboutUS_clicked();
    void on_pushButton_setting_clicked();
    void on_pushButton_Instagram_clicked();
    void on_pushButton_Telegarm_clicked();
    void on_pushButton_Facebook_clicked();
    void on_pushButton_Youtube_clicked();
    void on_pushButton_Twitter_clicked();
};

#endif // MAINWINDOW_H
