#include "addstudent.h"
#include "ui_addstudent.h"




AddStudent::AddStudent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddStudent)
{

    ui->setupUi(this);
    LoadTheme();
    console = new SharCatConsole(this);
    console->setGeometry( this->x() ,0, 300,400);
    console->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    console->setWindowTitle("$harCat Console >> Add Student");
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

AddStudent::~AddStudent()
{

    delete ui; 
}


void AddStudent::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}

void AddStudent::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}

bool AddStudent::IsEverythingOK()
{
    if (ui->lineEdit_Id->text().isEmpty() || ui->lineEdit_Fname->text().isEmpty() || ui->lineEdit_Lname->text().isEmpty() || ui->lineEdit_Phone->text().isEmpty() || ui->lineEdit_UserName->text().isEmpty())
    {
       return false;
    }
    return true;
}

void AddStudent::on_pushButton_Close_clicked()
{
    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    animOut->start();
    console->close();

}

void AddStudent::on_pushButton_saveInfo_clicked()
{
    if(!IsEverythingOK())
    {
        console->ShowMessage("Fill All Fields Please." , MessageColor::Red);
        return;
    }

    DataBase *db = new DataBase();
    Student *st = new Student();

    st->SetFirstName(ui->lineEdit_Fname->text());
    st->SetLastName(ui->lineEdit_Lname->text());
    st->SetSex(ui->comboBox_sex->currentText());
    st->SetUserName(ui->lineEdit_UserName->text());
    st->SetPhoneNumber(ui->lineEdit_Phone->text());
    st->SetDate(ui->lineEdit_BirthDat->text());
    st->SetEMail(ui->lineEdit_Email->text());
    st->SetID(ui->lineEdit_Id->text());

    st->SetFieldName(ui->comboBox_Field->currentText());
    st->SetEntryYear(ui->lineEdit_EntryYear->text());
    st->SetCurrentTerm(ui->lineEdit_CurrentTerm->text().toInt());
    st->SetTotalTerms(ui->lineEdit_TotalTerms->text().toInt());
    st->SetTotalUnits(ui->lineEdit_TotalUnits->text().toInt());
    st->SetPassedUnits(ui->lineEdit_PassedUnits->text().toInt());
    int index = ui->comboBox_Field->currentIndex();



    if(index == 0)
    {
        QFile file1(PROJECT_PATH + "Database/Student/Computer ENG/info.txt");
        if(Extraction::DoesExist(file1,st->GetID(),Qt::CaseInsensitive))
        {
            console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
            return;
        }
        db->AddStudentToFile(st,Fields::ComputerENG);
        console->ShowMessage("Student Added To The Database" , MessageColor::Green);
        ResetLineNumbers(file1);
        file1.close();
    }
    else if(index == 1)
    {

        QFile file2(PROJECT_PATH + "Database/Student/Chemistry ENG/info.txt");
        if(Extraction::DoesExist(file2,st->GetID(),Qt::CaseInsensitive))
        {
            console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
            return;
        }
        db->AddStudentToFile(st,Fields::ChemistryENG);
        console->ShowMessage("Student Added To The Database" , MessageColor::Green);
        ResetLineNumbers(file2);
        file2.close();
    }
    else if(index == 2)
    {

        QFile file3(PROJECT_PATH + "Database/Student/Industrial ENG/info.txt");
        if(Extraction::DoesExist(file3,st->GetID(),Qt::CaseInsensitive))
        {
            console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
            return;
        }
        db->AddStudentToFile(st,Fields::IndustrialENG);
        console->ShowMessage("Student Added To The Database" , MessageColor::Green);
        ResetLineNumbers(file3);
        file3.close();
    }
    else if(index == 3)
    {

        QFile file4(PROJECT_PATH + "Database/Student/Petroleum ENG/info.txt");
        if(Extraction::DoesExist(file4,st->GetID(),Qt::CaseInsensitive))
        {
            console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
            return;
        }
        db->AddStudentToFile(st,Fields::PetroleumENG);
        console->ShowMessage("Student Added To The Database" , MessageColor::Green);
        ResetLineNumbers(file4);
        file4.close();
    }
    else{}

    delete db;
    delete st;
}















