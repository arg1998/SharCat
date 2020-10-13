#include "addteacher.h"
#include "ui_addteacher.h"

AddTeacher::AddTeacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddTeacher)
{
    ui->setupUi(this);
    LoadTheme();
    console = new SharCatConsole(this);
    console->setGeometry( this->x() ,0, 300,400);
    console->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    console->setWindowTitle("$harCat Console >> Add Teacher");
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

AddTeacher::~AddTeacher()
{
    delete ui;
}
void AddTeacher::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}

void AddTeacher::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}
void AddTeacher::on_pushButton_Close_clicked()
{
    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    animOut->start();
    console->close();
}






bool AddTeacher::IsEverythingOK()
{
    if (ui->lineEdit_Id->text().isEmpty() || ui->lineEdit_Fname->text().isEmpty() || ui->lineEdit_Lname->text().isEmpty() || ui->lineEdit_Phone->text().isEmpty() || ui->lineEdit_UserName->text().isEmpty())
    {
       return false;
    }
    return true;
}

void AddTeacher::on_pushButton_saveInfo_clicked()
{
    if(!IsEverythingOK())
    {
        console->ShowMessage("Fill All Fields Please." , MessageColor::Red);
        return;
    }

    DataBase *db = new DataBase();
    Teacher *te = new Teacher();

    te->SetFirstName(ui->lineEdit_Fname->text());
    te->SetLastName(ui->lineEdit_Lname->text());
    te->SetSex(ui->comboBox_sex->currentText());
    te->SetUserName(ui->lineEdit_UserName->text());
    te->SetPhoneNumber(ui->lineEdit_Phone->text());
    te->SetDate(ui->lineEdit_BirthDat->text());
    te->SetEMail(ui->lineEdit_Email->text());
    te->SetID(ui->lineEdit_Id->text());

    te->SetDegree(ui->comboBox_Degere->currentText());
    te->SetScience(ui->comboBox_ScientificBoard->currentText());
    te->SetField(ui->lineEdit_Field->text());
    te->SetHoursWeek(ui->lineEdit_horsInWeek->text().toInt());


    QFile file(PROJECT_PATH + "Database/Teachers/info.txt");
    if (Extraction::DoesExist(file,te->GetID(),Qt::CaseInsensitive))
    {
        console->ShowMessage("This Teacher(ID) Already Exsits!",MessageColor::Red);
        return;
    }
    db->AddTeacherToFile(te);
    ResetLineNumbers(file);
    console->ShowMessage("Teacher Added To The Databse" , MessageColor::Green);
    file.close();

    delete db;
    delete te;
}



















