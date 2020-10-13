#include "sharcatconsole.h"
#include "ui_sharcatconsole.h"

SharCatConsole::SharCatConsole(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SharCatConsole)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->label);
    time = new QTime();
}

SharCatConsole::~SharCatConsole()
{
    delete ui;
}

void SharCatConsole::ShowMessage(QString message, MessageColor color)
{
    if (color == MessageColor::Red)
    {
        message = QString("<span style='color: rgb(200,0,0);font-family:'Segoe UI Light';font-size:14px;'> %1  : %2 </span><br>").arg(time->currentTime().toString(Qt::TextDate)).arg(message);
        ui->label->setText(message + ui->label->text() );
    }
    else if (color == MessageColor::Green)
    {
        message = QString("<span style='color: rgb(0,180,0);font-family:'Segoe UI Light';font-size:14px;'> %1  : %2 </span><br>").arg(time->currentTime().toString(Qt::TextDate)).arg(message);
        ui->label->setText(message + ui->label->text());
    }
    else
    {
        ui->label->setText( time->currentTime().toString(Qt::TextDate) + "  :  " + message +"<br>" + ui->label->text());
    }
}
