#ifndef SHARCATCONSOLE_H
#define SHARCATCONSOLE_H

#include <QMainWindow>
#include <QTime>
#include <QtCore>

namespace Ui {
class SharCatConsole;
}

enum MessageColor
{
    Red,Green,Black
};

class SharCatConsole : public QMainWindow
{
    Q_OBJECT

public:
    explicit SharCatConsole(QWidget *parent = 0);
    ~SharCatConsole();

private:
    Ui::SharCatConsole *ui;
    QTime *time;


public slots:
    void ShowMessage(QString message , MessageColor color);
};


#endif // SHARCATCONSOLE_H
