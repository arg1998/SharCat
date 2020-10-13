#include "addstaff.h"
#include "ui_addstaff.h"

AddStaff::AddStaff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddStaff)
{
    ui->setupUi(this);
    LoadTheme();
    console = new SharCatConsole(this);
    console->setGeometry( this->x() ,0, 300,400);
    console->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    console->setWindowTitle("$harCat Console >> Add Staff");
    if(Extraction::GetSettingValue(Property::SHOW_CONSOLE) == "true")
    {
        console->show();
    }


    QPropertyAnimation *animIn = new QPropertyAnimation(this,"windowOpacity",this);
    animIn->setDuration(500);
    animIn->setStartValue(0.0);
    animIn->setEndValue(1.0);
    animIn->start();



}

AddStaff::~AddStaff()
{
    delete ui;
}

void AddStaff::on_pushButton_Close_clicked()
{
    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    animOut->start();
    console->close();
}

void AddStaff::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}

void AddStaff::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}


bool AddStaff::IsEverythingOK()
{
    if (ui->lineEdit_Id->text().isEmpty() || ui->lineEdit_Fname->text().isEmpty() || ui->lineEdit_Lname->text().isEmpty() || ui->lineEdit_Phone->text().isEmpty() || ui->lineEdit_UserName->text().isEmpty())
    {
       return false;
    }
    return true;
}

void AddStaff::on_pushButton_saveInfo_clicked()
{
    if(!IsEverythingOK())
    {
        console->ShowMessage("Fill All Fields Please." , MessageColor::Red);
        return;
    }

    DataBase *db = new DataBase();
    Staff *st = new Staff();

    st->SetFirstName(ui->lineEdit_Fname->text());
    st->SetLastName(ui->lineEdit_Lname->text());
    st->SetSex(ui->comboBox_sex->currentText());
    st->SetUserName(ui->lineEdit_UserName->text());
    st->SetPhoneNumber(ui->lineEdit_Phone->text());
    st->SetDate(ui->lineEdit_BirthDat->text());
    st->SetEMail(ui->lineEdit_Email->text());
    st->SetID(ui->lineEdit_Id->text());

   st->SetDepartment(ui->comboBox_department->currentText());
   st->SetType(ui->comboBox_type->currentText());
   st->SetWorkShift(ui->comboBox_workshift->currentText());

   QFile file1(PROJECT_PATH + "Database/Staff/info.txt");
   if(Extraction::DoesExist(file1,st->GetID(),Qt::CaseInsensitive))
   {
       console->ShowMessage("This Staff(ID) Already Exists!",MessageColor::Red);
       return;
   }
   db->AddStaffToFile(st);
   console->ShowMessage("Staff Added To The Database" , MessageColor::Green);
   ResetLineNumbers(file1);
   file1.close();


   delete st;
   delete db;

}













