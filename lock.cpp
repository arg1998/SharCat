#include "lock.h"
#include "ui_lock.h"

Lock::Lock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lock)
{
    ui->setupUi(this);
    LoadTheme();
    ui->pushButton_forget->setVisible(0);
    ui->label_lock_wrongpassword->setVisible(0);
}

Lock::~Lock()
{
    delete ui;
}

void Lock::on_pushButton_login_clicked()
{
    QString userpass = Security::getHashPassWord(ui->lineEdit_pass->text());
    QString pass = Extraction::GetSettingValue(Property::PASSWORD);
    if(userpass == pass)
    {
        this->close();
    }
    else
    {
        ui->label_lock_wrongpassword->setVisible(1);
        //ui->pushButton_forget->setVisible(1);

    }
}
