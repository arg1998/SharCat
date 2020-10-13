#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "sharcatconsole.h"
#include "CoreEngine/database.h"


namespace Ui {
class AddStudent;
}

class AddStudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = 0);
    ~AddStudent();
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    bool IsEverythingOK();
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }


private slots:
    void on_pushButton_Close_clicked();

    void on_pushButton_saveInfo_clicked();

private:
    Ui::AddStudent *ui;
    int Xbefore;
    int Ybefore;
    SharCatConsole *console;




};

#endif // ADDSTUDENT_H
