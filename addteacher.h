#ifndef ADDTEACHER_H
#define ADDTEACHER_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "sharcatconsole.h"
#include "CoreEngine/database.h"


namespace Ui {
class AddTeacher;
}

class AddTeacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddTeacher(QWidget *parent = 0);
    ~AddTeacher();
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
    Ui::AddTeacher *ui;
    int Xbefore;
    int Ybefore;
    SharCatConsole *console;
};

#endif // ADDTEACHER_H
