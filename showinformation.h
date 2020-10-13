#ifndef SHOWINFORMATION_H
#define SHOWINFORMATION_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "CoreEngine/database.h"
#include "sharcatconsole.h"


namespace Ui {
class ShowInformation;
}

class ShowInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowInformation(QWidget *parent = 0);
    ~ShowInformation();
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    bool CheckInputExists(QFile*,bool printMessage);
    void PrintDataForPersonFrame(QString,QFile&);
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }




private slots:
    void on_pushButton_Close_clicked();

    void on_pushButton_refresh_clicked();

    void on_radioButton_ID_toggled(bool checked);

    void on_radioButton_PhoneNumber_toggled(bool checked);

private:
    Ui::ShowInformation *ui;

    int Xbefore;
    int Ybefore;
    SharCatConsole *console;



};

#endif // SHOWINFORMATION_H
