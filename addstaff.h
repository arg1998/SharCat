#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "sharcatconsole.h"
#include "CoreEngine/database.h"


namespace Ui {
class AddStaff;
}

class AddStaff : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddStaff(QWidget *parent = 0);
    ~AddStaff();
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
    Ui::AddStaff *ui;
    int Xbefore;
    int Ybefore;
    SharCatConsole *console;




};

#endif // ADDSTAFF_H
