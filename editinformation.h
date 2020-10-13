#ifndef EDITINFORMATION_H
#define EDITINFORMATION_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include "sharcatconsole.h"
#include "CoreEngine/database.h"


namespace Ui {
class EditInformation;
}

class EditInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditInformation(QWidget *parent = 0);
    ~EditInformation();
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void HideFrames();
    void LoadData(int);
    bool DeleteInfoByID(QString);
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }

private slots:
    void on_pushButton_Close_clicked();
    void on_pushButton_refresh_clicked();
    void on_lineEdit_IDSerch_textChanged(const QString &arg1);
    void on_pushButton_editInformation_delete_clicked();
    void on_pushButton_saveInfo_clicked();

private:
    Ui::EditInformation *ui;
    int Xbefore;
    int Ybefore;
    SharCatConsole *console;
    bool valiedID;
    bool idExists;

    Staff *staff;
    Student *student;
    Teacher *teacher;


};

#endif // EDITINFORMATION_H
