#include "editinformation.h"
#include "ui_editinformation.h"

#include <QDebug>

EditInformation::EditInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditInformation)
{
    //initialze private variabels
    valiedID = false;
    idExists = false;

    ui->setupUi(this);
    LoadTheme();
    QPropertyAnimation *animIn = new QPropertyAnimation(this,"windowOpacity",this);
    animIn->setDuration(500);
    animIn->setStartValue(0.0);
    animIn->setEndValue(1.0);
    animIn->start();

    //hiding frames
    HideFrames();




    //console
    console = new SharCatConsole(this);
    console->setGeometry( this->x() ,0, 300,400);
    console->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    console->setWindowTitle("$harCat Console >> Edit Information");
    if(Extraction::GetSettingValue(Property::SHOW_CONSOLE) == "true")
    {
        console->show();
    }


}
EditInformation::~EditInformation()
{
    delete ui;
}
void EditInformation::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}

void EditInformation::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}

void EditInformation::HideFrames()
{
    ui->frame_personalIno->setVisible(false);
    ui->frame_StudentInfo->setVisible(false);
    ui->pushButton_editGrades->setVisible(false);
    ui->frame_StaffInfo->setVisible(false);
    ui->frame_TeacherInfo->setVisible(false);
    ui->pushButton_editInformation_delete->setVisible(false);
    ui->pushButton_saveInfo->setVisible(false);
}

void EditInformation::LoadData(int dataID)
{
    console->ShowMessage("Loading Data ... ",MessageColor::Black);
    QString ID = ui->lineEdit_IDSerch->text();

    if(dataID == 1)//students
    {

        QFile comFile(PROJECT_PATH+"Database/Student/Computer ENG/info.txt");
        QFile chemFile(PROJECT_PATH+"Database/Student/Chemistry ENG/info.txt");
        QFile indFile(PROJECT_PATH+"Database/Student/Industrial ENG/info.txt");
        QFile petFile(PROJECT_PATH+"Database/Student/Petroleum ENG/info.txt");

        //Computer Eng
        if(Extraction::DoesExist(comFile,ID,Qt::CaseInsensitive))
        {
            idExists = true;
            console->ShowMessage("Found!",MessageColor::Green);
            ui->pushButton_saveInfo->setVisible(true);
            ui->lineEdit_Fname->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::FNAME));
            ui->lineEdit_Lname->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::LNAME));
            ui->lineEdit_Id->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::ID));
            ui->lineEdit_BirthDat->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::DATE));
            ui->lineEdit_Phone->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::PHONE));
            ui->lineEdit_Email->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::EMAIL));
            ui->comboBox_sex->setCurrentText(Extraction::GetPropertyValueByID(comFile,ID,Property::GENDER));
            ui->lineEdit_UserName->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::USERNAME));

            ui->comboBox_Student_Field->setCurrentText(Extraction::GetPropertyValueByID(comFile,ID,Property::FIELDNAME));
            ui->lineEdit_EntryYear->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::ENTRYYEAR));
            ui->lineEdit_TotalTerms->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::TOTALTERMS));
            ui->lineEdit_TotalUnits->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::TOTALUNITS));
            ui->lineEdit_CurrentTerm->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::CURRENTTERM));
            ui->lineEdit_PassedUnits->setText(Extraction::GetPropertyValueByID(comFile,ID,Property::PASSEDUNITS));
        }

        //Chemistry Eng
        else if(Extraction::DoesExist(chemFile,ID,Qt::CaseInsensitive))
        {
            idExists = true;
            console->ShowMessage("Found!",MessageColor::Green);
            ui->pushButton_saveInfo->setVisible(true);
            ui->lineEdit_Fname->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::FNAME));
            ui->lineEdit_Lname->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::LNAME));
            ui->lineEdit_Id->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::ID));
            ui->lineEdit_BirthDat->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::DATE));
            ui->lineEdit_Phone->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::PHONE));
            ui->lineEdit_Email->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::EMAIL));
            ui->comboBox_sex->setCurrentText(Extraction::GetPropertyValueByID(chemFile,ID,Property::GENDER));
            ui->lineEdit_UserName->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::USERNAME));

            ui->comboBox_Student_Field->setCurrentText(Extraction::GetPropertyValueByID(chemFile,ID,Property::FIELDNAME));
            ui->lineEdit_EntryYear->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::ENTRYYEAR));
            ui->lineEdit_TotalTerms->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::TOTALTERMS));
            ui->lineEdit_TotalUnits->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::TOTALUNITS));
            ui->lineEdit_CurrentTerm->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::CURRENTTERM));
            ui->lineEdit_PassedUnits->setText(Extraction::GetPropertyValueByID(chemFile,ID,Property::PASSEDUNITS));
        }
        //industrial Eng

        else if(Extraction::DoesExist(indFile,ID,Qt::CaseInsensitive))
        {
            idExists = true;
            console->ShowMessage("Found!",MessageColor::Green);
            ui->pushButton_saveInfo->setVisible(true);
            ui->lineEdit_Fname->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::FNAME));
            ui->lineEdit_Lname->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::LNAME));
            ui->lineEdit_Id->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::ID));
            ui->lineEdit_BirthDat->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::DATE));
            ui->lineEdit_Phone->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::PHONE));
            ui->lineEdit_Email->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::EMAIL));
            ui->comboBox_sex->setCurrentText(Extraction::GetPropertyValueByID(indFile,ID,Property::GENDER));
            ui->lineEdit_UserName->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::USERNAME));

            ui->comboBox_Student_Field->setCurrentText(Extraction::GetPropertyValueByID(indFile,ID,Property::FIELDNAME));
            ui->lineEdit_EntryYear->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::ENTRYYEAR));
            ui->lineEdit_TotalTerms->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::TOTALTERMS));
            ui->lineEdit_TotalUnits->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::TOTALUNITS));
            ui->lineEdit_CurrentTerm->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::CURRENTTERM));
            ui->lineEdit_PassedUnits->setText(Extraction::GetPropertyValueByID(indFile,ID,Property::PASSEDUNITS));
        }
        //petroleum eng

        else if(Extraction::DoesExist(petFile,ID,Qt::CaseInsensitive))
        {
            idExists = true;
            console->ShowMessage("Found!",MessageColor::Green);
            ui->pushButton_saveInfo->setVisible(true);
            ui->lineEdit_Fname->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::FNAME));
            ui->lineEdit_Lname->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::LNAME));
            ui->lineEdit_Id->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::ID));
            ui->lineEdit_BirthDat->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::DATE));
            ui->lineEdit_Phone->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::PHONE));
            ui->lineEdit_Email->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::EMAIL));
            ui->comboBox_sex->setCurrentText(Extraction::GetPropertyValueByID(petFile,ID,Property::GENDER));
            ui->lineEdit_UserName->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::USERNAME));

            ui->comboBox_Student_Field->setCurrentText(Extraction::GetPropertyValueByID(petFile,ID,Property::FIELDNAME));
            ui->lineEdit_EntryYear->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::ENTRYYEAR));
            ui->lineEdit_TotalTerms->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::TOTALTERMS));
            ui->lineEdit_TotalUnits->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::TOTALUNITS));
            ui->lineEdit_CurrentTerm->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::CURRENTTERM));
            ui->lineEdit_PassedUnits->setText(Extraction::GetPropertyValueByID(petFile,ID,Property::PASSEDUNITS));
        }
        else
        {
            idExists = false;
            HideFrames();
            console->ShowMessage("Not Found!",MessageColor::Red);
        }
    }
    else if (dataID == 2)//teacher
    {
        QFile teaFile(PROJECT_PATH+"Database/Teachers/info.txt");
        if(Extraction::DoesExist(teaFile,ID,Qt::CaseInsensitive))
        {
            idExists = true;
            console->ShowMessage("Found!",MessageColor::Green);
            ui->pushButton_saveInfo->setVisible(true);
            ui->lineEdit_Fname->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::FNAME));
            ui->lineEdit_Lname->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::LNAME));
            ui->lineEdit_Id->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::ID));
            ui->lineEdit_BirthDat->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::DATE));
            ui->lineEdit_Phone->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::PHONE));
            ui->lineEdit_Email->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::EMAIL));
            ui->comboBox_sex->setCurrentText(Extraction::GetPropertyValueByID(teaFile,ID,Property::GENDER));
            ui->lineEdit_UserName->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::USERNAME));

            ui->comboBox_Teacher_Degree->setCurrentText(Extraction::GetPropertyValueByID(teaFile,ID,Property::DEGREE));
            ui->comboBox_Techer_SB->setCurrentText(Extraction::GetPropertyValueByID(teaFile,ID,Property::SCIENTIFICBOARD));
            ui->lineEdit_Teacher_field->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::FIELD));
            ui->lineEdit_Teacher_hours->setText(Extraction::GetPropertyValueByID(teaFile,ID,Property::HOURSWEEK));
        }
        else
        {
            idExists = false;
            HideFrames();
            console->ShowMessage("Not Found!",MessageColor::Red);
        }

    }
    else if (dataID == 3)//staff
    {
        QFile staffFile(PROJECT_PATH+"Database/Staff/info.txt");
        if(Extraction::DoesExist(staffFile,ID,Qt::CaseInsensitive))
        {
            idExists = true;
            console->ShowMessage("Found!",MessageColor::Green);
            ui->pushButton_saveInfo->setVisible(true);
            ui->lineEdit_Fname->setText(Extraction::GetPropertyValueByID(staffFile,ID,Property::FNAME));
            ui->lineEdit_Lname->setText(Extraction::GetPropertyValueByID(staffFile,ID,Property::LNAME));
            ui->lineEdit_Id->setText(Extraction::GetPropertyValueByID(staffFile,ID,Property::ID));
            ui->lineEdit_BirthDat->setText(Extraction::GetPropertyValueByID(staffFile,ID,Property::DATE));
            ui->lineEdit_Phone->setText(Extraction::GetPropertyValueByID(staffFile,ID,Property::PHONE));
            ui->lineEdit_Email->setText(Extraction::GetPropertyValueByID(staffFile,ID,Property::EMAIL));
            ui->comboBox_sex->setCurrentText(Extraction::GetPropertyValueByID(staffFile,ID,Property::GENDER));
            ui->lineEdit_UserName->setText(Extraction::GetPropertyValueByID(staffFile,ID,Property::USERNAME));

            ui->comboBox_Staff_Dep->setCurrentText(Extraction::GetPropertyValueByID(staffFile,ID,Property::DEPARTMENT));
            ui->comboBox_Staff_Shift->setCurrentText(Extraction::GetPropertyValueByID(staffFile,ID,Property::WORKSHIFT));
            ui->comboBox_Staff_Type->setCurrentText(Extraction::GetPropertyValueByID(staffFile,ID,Property::TYPE));

        }
        else
        {
            idExists = false;
            HideFrames();
            console->ShowMessage("Not Found!",MessageColor::Red);
        }

    }
}

bool EditInformation::DeleteInfoByID(QString id)
{
    bool result = false;
    int index = ui->comboBox_PersonType->currentIndex();
    QString ID = id;

    QFile comFile(PROJECT_PATH+"Database/Student/Computer ENG/info.txt");
    QFile chemFile(PROJECT_PATH+"Database/Student/Chemistry ENG/info.txt");
    QFile indFile(PROJECT_PATH+"Database/Student/Industrial ENG/info.txt");
    QFile petFile(PROJECT_PATH+"Database/Student/Petroleum ENG/info.txt");
    QFile teaFile(PROJECT_PATH+"Database/Teachers/info.txt");
    QFile staffFile(PROJECT_PATH+"Database/Staff/info.txt");


    if(index == 1)//student
    {
        if(Extraction::DoesExist(comFile,ID,Qt::CaseInsensitive))
        {
            comFile.close();
            Insertion::DeleteInfoByID(ID,comFile,true);
            result = true;
        }
        else if(Extraction::DoesExist(chemFile,ID,Qt::CaseInsensitive))
        {
            chemFile.close();
            Insertion::DeleteInfoByID(ID,chemFile,true);
            result = true;
        }
        else if(Extraction::DoesExist(indFile,ID,Qt::CaseInsensitive))
        {
            indFile.close();
            Insertion::DeleteInfoByID(ID,indFile,true);
            result = true;
        }
        else if(Extraction::DoesExist(petFile,ID,Qt::CaseInsensitive))
        {
            petFile.close();
            Insertion::DeleteInfoByID(ID,petFile,true);
            result = true;
        }
    }
    else if(index == 2)//teacher
    {
        if(Extraction::DoesExist(teaFile,ID,Qt::CaseInsensitive))
        {
            teaFile.close();
            Insertion::DeleteInfoByID(ID,teaFile,true);
            result = true;
        }
    }
    else if(index == 3)//staff
    {
        if(Extraction::DoesExist(staffFile,ID,Qt::CaseInsensitive))
        {
            staffFile.close();
            Insertion::DeleteInfoByID(ID,staffFile,true);
            result = true;
        }
    }

    ui->lineEdit_IDSerch->setText("");
    HideFrames();
    return result;
}
void EditInformation::on_pushButton_Close_clicked()
{
    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    animOut->start();
    console->close();
}


void EditInformation::on_pushButton_refresh_clicked()
{
    //check inputs here
    bool canConvert;
    ui->lineEdit_IDSerch->text().toInt(&canConvert);
    if(ui->lineEdit_IDSerch->text().size() <= 8 || !canConvert)
    {
        console->ShowMessage("Fill Inputs Correctly!",MessageColor::Red);
        return;
    }







    int index = ui->comboBox_PersonType->currentIndex();
    switch (index)
    {
    case 0:
        //show a messege in console "select one option to continue"
        //set all frames hidden
        ui->frame_personalIno->setVisible(false);
        ui->frame_StudentInfo->setVisible(false);
        ui->pushButton_editGrades->setVisible(false);
        ui->frame_StaffInfo->setVisible(false);
        ui->frame_TeacherInfo->setVisible(false);
        ui->pushButton_editInformation_delete->setVisible(false);
        break;

    case 1://student
        //set to true for showing
       ui->frame_personalIno->setVisible(true);
       ui->frame_StudentInfo->setVisible(true);
       ui->pushButton_editGrades->setVisible(true);
       //set to false for hiding them
       ui->frame_StaffInfo->setVisible(false);
       ui->frame_TeacherInfo->setVisible(false);
       ui->pushButton_editInformation_delete->setVisible(true);
       //load data in frames
       LoadData(1);
        break;


    case 2://teacher
        //set to true for showing
       ui->frame_personalIno->setVisible(true);
       ui->frame_TeacherInfo->setVisible(true);

       //set to false for hiding them
       ui->frame_StaffInfo->setVisible(false);
       ui->frame_StudentInfo->setVisible(false);
       ui->pushButton_editGrades->setVisible(false);
       ui->pushButton_editInformation_delete->setVisible(true);
       //load data to frames
       LoadData(2);
        break;



    case 3://staff
        //set to true for showing
       ui->frame_personalIno->setVisible(true);
       ui->frame_StaffInfo->setVisible(true);

       //set to false for hiding them
       ui->frame_StudentInfo->setVisible(false);
       ui->frame_TeacherInfo->setVisible(false);
       ui->pushButton_editGrades->setVisible(false);
       ui->pushButton_editInformation_delete->setVisible(true);
       //load data in frames
       LoadData(3);
        break;



    default:
        break;
    }
}

void EditInformation::on_lineEdit_IDSerch_textChanged(const QString &arg1)
{
    arg1.toInt(&valiedID);
    if (!valiedID && !arg1.isEmpty())
    {
        ui->lineEdit_IDSerch->setStyleSheet("border: 1px solid rgb(255 , 0 , 0);");
    }
    else
    {
        ui->lineEdit_IDSerch->setStyleSheet("border: 2px solid rgb(0 , 75 , 0);");
    }
}



void EditInformation::on_pushButton_editInformation_delete_clicked()
{
   bool result = DeleteInfoByID(ui->lineEdit_IDSerch->text());
   if(result)
   {
        console->ShowMessage("Deleted Successfuly",MessageColor::Green);
   }
   else
   {
        console->ShowMessage("Couldn't Delete !!",MessageColor::Red);
   }
}

void EditInformation::on_pushButton_saveInfo_clicked()
{
    int index = ui->comboBox_PersonType->currentIndex();
    QString ID = ui->lineEdit_IDSerch->text();


    if(index == 1)//student
    {
        int stdIndex = ui->comboBox_Student_Field->currentIndex();
        if(DeleteInfoByID(ID))
        {
            //generate new student
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

            st->SetFieldName(ui->comboBox_Student_Field->currentText());
            st->SetEntryYear(ui->lineEdit_EntryYear->text());
            st->SetCurrentTerm(ui->lineEdit_CurrentTerm->text().toInt());
            st->SetTotalTerms(ui->lineEdit_TotalTerms->text().toInt());
            st->SetTotalUnits(ui->lineEdit_TotalUnits->text().toInt());
            st->SetPassedUnits(ui->lineEdit_PassedUnits->text().toInt());



            if(stdIndex == 0)//computer
            {
                QFile file1(PROJECT_PATH + "Database/Student/Computer ENG/info.txt");
                if(Extraction::DoesExist(file1,st->GetID(),Qt::CaseInsensitive))
                {
                    console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
                }
                else
                {
                    db->AddStudentToFile(st,Fields::ComputerENG);
                    console->ShowMessage("Changes Saved" , MessageColor::Green);
                    ResetLineNumbers(file1);
                    file1.close();
                }
            }
            else if (stdIndex == 1)//chemistry
            {
                QFile file2(PROJECT_PATH + "Database/Student/Chemistry ENG/info.txt");
                if(Extraction::DoesExist(file2,st->GetID(),Qt::CaseInsensitive))
                {
                    console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
                }
                else
                {
                    db->AddStudentToFile(st,Fields::ChemistryENG);
                    console->ShowMessage("Changes Saved" , MessageColor::Green);
                    ResetLineNumbers(file2);
                    file2.close();
                }
            }
            else if(stdIndex == 2)//industrial
            {
                QFile file3(PROJECT_PATH + "Database/Student/Industrial ENG/info.txt");
                if(Extraction::DoesExist(file3,st->GetID(),Qt::CaseInsensitive))
                {
                    console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
                }
                else
                {
                    db->AddStudentToFile(st,Fields::IndustrialENG);
                    console->ShowMessage("Changes Saved" , MessageColor::Green);
                    ResetLineNumbers(file3);
                    file3.close();
                }
            }
            else if(stdIndex == 3)//petroleum
            {
                QFile file4(PROJECT_PATH + "Database/Student/Petroleum ENG/info.txt");
                if(Extraction::DoesExist(file4,st->GetID(),Qt::CaseInsensitive))
                {
                    console->ShowMessage("This Student(ID) Already Exists!",MessageColor::Red);
                }
                else
                {
                    db->AddStudentToFile(st,Fields::PetroleumENG);
                    console->ShowMessage("Changes Saved" , MessageColor::Green);
                    ResetLineNumbers(file4);
                    file4.close();
                }
            }

            delete db;
            delete st;
        }
    }
    else if(index == 2)//teacher
    {
        if (DeleteInfoByID(ID))
        {
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

            te->SetDegree(ui->comboBox_Teacher_Degree->currentText());
            te->SetScience(ui->comboBox_Techer_SB->currentText());
            te->SetField(ui->lineEdit_Teacher_field->text());
            te->SetHoursWeek(ui->lineEdit_Teacher_hours->text().toInt());


            QFile file(PROJECT_PATH + "Database/Teachers/info.txt");
            if (Extraction::DoesExist(file,te->GetID(),Qt::CaseInsensitive))
            {
                console->ShowMessage("This Teacher(ID) Already Exsits!",MessageColor::Red);
                return;
            }
            db->AddTeacherToFile(te);
            ResetLineNumbers(file);
            console->ShowMessage("Changes Saved" , MessageColor::Green);
            file.close();

            delete db;
            delete te;
        }
    }
    else if (index == 3)//staff
    {
        if (DeleteInfoByID(ID))
        {
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

           st->SetDepartment(ui->comboBox_Staff_Dep->currentText());
           st->SetType(ui->comboBox_Staff_Type->currentText());
           st->SetWorkShift(ui->comboBox_Staff_Shift->currentText());

           QFile file1(PROJECT_PATH + "Database/Staff/info.txt");
           if(Extraction::DoesExist(file1,st->GetID(),Qt::CaseInsensitive))
           {
               console->ShowMessage("This Staff(ID) Already Exists!",MessageColor::Red);
           }
           else
           {
               db->AddStaffToFile(st);
               console->ShowMessage("Changes Saved" , MessageColor::Green);
               ResetLineNumbers(file1);
               file1.close();
           }

           delete db;
           delete st;
        }
    }
}


















