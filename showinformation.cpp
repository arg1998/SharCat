#include "showinformation.h"
#include "ui_showinformation.h"

ShowInformation::ShowInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowInformation)
{

    ui->setupUi(this);
    LoadTheme();

    QPropertyAnimation *animIn = new QPropertyAnimation(this,"windowOpacity",this);
    animIn->setDuration(500);
    animIn->setStartValue(0.0);
    animIn->setEndValue(1.0);
    animIn->start();


    ui->label_ChooseLineEdit->setVisible(false);
    ui->lineEdit_IDSerch->setVisible(false);
    ui->lineEdit_PhoneSearch->setVisible(false);

    ui->frame_PersonalInfo->setVisible(0);
    ui->frame_staff->setVisible(0);
    ui->frame_student->setVisible(0);
    ui->frame_teacher->setVisible(0);


    console = new SharCatConsole(this);
    console->setGeometry( this->x() ,0, 300,400);
    console->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    console->setWindowTitle("$harCat Console >> Show Information");
    if(Extraction::GetSettingValue(Property::SHOW_CONSOLE) == "true")
    {
        console->show();
    }


}

ShowInformation::~ShowInformation()
{
    delete ui;
}
void ShowInformation::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}
void ShowInformation::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}
bool ShowInformation::CheckInputExists(QFile *file, bool printMessage = true)
{
    if(Extraction::DoesExist(*file,ui->lineEdit_IDSerch->text(),Qt::CaseInsensitive) && ui->lineEdit_IDSerch->text().size() > 8)
    {
        if(printMessage) {console->ShowMessage("Found" , MessageColor::Green);}
        return true;
    }
    else if(Extraction::DoesExist(*file,ui->lineEdit_PhoneSearch->text(),Qt::CaseInsensitive) && ui->lineEdit_PhoneSearch->text().size() > 10)
    {
        if(printMessage){console->ShowMessage("Found" , MessageColor::Green);}
        return true;
    }
    else
    {
        if(printMessage){console->ShowMessage("Not Found! Check Your Inputs Again" , MessageColor::Red);}
        return false;
    }
}
void ShowInformation::on_pushButton_Close_clicked()
{
    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    animOut->start();
    console->close();
}
void ShowInformation::PrintDataForPersonFrame(QString SearchPattern,QFile &file)
{
    if(ui->radioButton_ID->isChecked())
    {
        ui->label_fname->setText( "First Name : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::FNAME));
        ui->label_lname->setText("Last Name : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::LNAME));
        ui->label_id->setText( "ID : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::ID));
        ui->label_email->setText( "Email : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::EMAIL));
        ui->label_phone->setText( "Phone : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::PHONE));
        ui->label_sex->setText( "Sex : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::GENDER));
        ui->label_birthdate->setText( "Birth Date : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::DATE));
        ui->label_username->setText( "Useename : " + Extraction::GetPropertyValueByID(file,SearchPattern,Property::USERNAME));
    }
    else if(ui->radioButton_PhoneNumber->isChecked())
    {
        ui->label_fname->setText( "First Name : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::FNAME));
        ui->label_lname->setText("Last Name : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::LNAME));
        ui->label_id->setText( "ID : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::ID));
        ui->label_email->setText( "Email : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::EMAIL));
        ui->label_phone->setText( "Phone : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::PHONE));
        ui->label_sex->setText( "Sex : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::GENDER));
        ui->label_birthdate->setText( "Birth Date : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::DATE));
        ui->label_username->setText( "Useename : " + Extraction::GetPropertyValueByPhoneNumber(file,SearchPattern,Property::USERNAME));
    }

}
void ShowInformation::on_pushButton_refresh_clicked()
{
    if(ui->lineEdit_IDSerch->text().isEmpty() && ui->lineEdit_PhoneSearch->text().isEmpty())
    {
        console->ShowMessage("Fill All Fields Please!" , MessageColor::Red);
        return;
    }

    //frames interactions
    int index = ui->comboBox_PersonType->currentIndex();

    if(index == 0)//empty
    {
        ui->frame_PersonalInfo->setVisible(0);
        ui->frame_staff->setVisible(0);
        ui->frame_student->setVisible(0);
        ui->frame_teacher->setVisible(0);


    }
    else if(index == 1)//student
    {

        QFile filePE(PROJECT_PATH + "Database/Student/Petroleum ENG/info.txt");
        QFile fileIE(PROJECT_PATH + "Database/Student/Industrial ENG/info.txt");
        QFile fileChE(PROJECT_PATH + "Database/Student/Chemistry ENG/info.txt");
        QFile fileCE(PROJECT_PATH + "Database/Student/Computer ENG/info.txt");


        if(CheckInputExists(&filePE,false))
        {
            if(ui->radioButton_ID->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_IDSerch->text() , filePE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByID(filePE,ui->lineEdit_IDSerch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByID(filePE,ui->lineEdit_IDSerch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByID(filePE,ui->lineEdit_IDSerch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByID(filePE,ui->lineEdit_IDSerch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByID(filePE,ui->lineEdit_IDSerch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByID(filePE,ui->lineEdit_IDSerch->text(),Property::TOTALUNITS));
            }
            else if(ui->radioButton_PhoneNumber->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_PhoneSearch->text() , filePE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByPhoneNumber(filePE,ui->lineEdit_PhoneSearch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByPhoneNumber(filePE,ui->lineEdit_PhoneSearch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByPhoneNumber(filePE,ui->lineEdit_PhoneSearch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByPhoneNumber(filePE,ui->lineEdit_PhoneSearch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByPhoneNumber(filePE,ui->lineEdit_PhoneSearch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByPhoneNumber(filePE,ui->lineEdit_PhoneSearch->text(),Property::TOTALUNITS));
            }
            console->ShowMessage("Found",MessageColor::Green);
        }

        else if(CheckInputExists(&fileIE,false))
        {
            if(ui->radioButton_ID->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_IDSerch->text() , fileIE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByID(fileIE,ui->lineEdit_IDSerch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByID(fileIE,ui->lineEdit_IDSerch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByID(fileIE,ui->lineEdit_IDSerch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByID(fileIE,ui->lineEdit_IDSerch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByID(fileIE,ui->lineEdit_IDSerch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByID(fileIE,ui->lineEdit_IDSerch->text(),Property::TOTALUNITS));
            }
            else if(ui->radioButton_PhoneNumber->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_PhoneSearch->text() , fileIE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByPhoneNumber(fileIE,ui->lineEdit_PhoneSearch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByPhoneNumber(fileIE,ui->lineEdit_PhoneSearch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByPhoneNumber(fileIE,ui->lineEdit_PhoneSearch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByPhoneNumber(fileIE,ui->lineEdit_PhoneSearch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByPhoneNumber(fileIE,ui->lineEdit_PhoneSearch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByPhoneNumber(fileIE,ui->lineEdit_PhoneSearch->text(),Property::TOTALUNITS));
            }
            console->ShowMessage("Found",MessageColor::Green);
        }


        else if(CheckInputExists(&fileChE,false))
        {
            if(ui->radioButton_ID->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_IDSerch->text() , fileChE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByID(fileChE,ui->lineEdit_IDSerch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByID(fileChE,ui->lineEdit_IDSerch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByID(fileChE,ui->lineEdit_IDSerch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByID(fileChE,ui->lineEdit_IDSerch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByID(fileChE,ui->lineEdit_IDSerch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByID(fileChE,ui->lineEdit_IDSerch->text(),Property::TOTALUNITS));
            }
            else if(ui->radioButton_PhoneNumber->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_PhoneSearch->text() , fileChE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByPhoneNumber(fileChE,ui->lineEdit_PhoneSearch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByPhoneNumber(fileChE,ui->lineEdit_PhoneSearch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByPhoneNumber(fileChE,ui->lineEdit_PhoneSearch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByPhoneNumber(fileChE,ui->lineEdit_PhoneSearch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByPhoneNumber(fileChE,ui->lineEdit_PhoneSearch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByPhoneNumber(fileChE,ui->lineEdit_PhoneSearch->text(),Property::TOTALUNITS));
            }
            console->ShowMessage("Found",MessageColor::Green);
        }


        else if(CheckInputExists(&fileCE,false))
        {
            if(ui->radioButton_ID->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_IDSerch->text() , fileCE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByID(fileCE,ui->lineEdit_IDSerch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByID(fileCE,ui->lineEdit_IDSerch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByID(fileCE,ui->lineEdit_IDSerch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByID(fileCE,ui->lineEdit_IDSerch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByID(fileCE,ui->lineEdit_IDSerch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByID(fileCE,ui->lineEdit_IDSerch->text(),Property::TOTALUNITS));
            }
            else if(ui->radioButton_PhoneNumber->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_PhoneSearch->text() , fileCE);
                ui->label_student_currentTerm->setText("Current Term : " + Extraction::GetPropertyValueByPhoneNumber(fileCE,ui->lineEdit_PhoneSearch->text(),Property::CURRENTTERM));
                ui->label_student_entryyear->setText("Entry Year : " + Extraction::GetPropertyValueByPhoneNumber(fileCE,ui->lineEdit_PhoneSearch->text(),Property::ENTRYYEAR));
                ui->label_student_fieldname->setText("Field Name : " + Extraction::GetPropertyValueByPhoneNumber(fileCE,ui->lineEdit_PhoneSearch->text(),Property::FIELDNAME));
                ui->label_student_passedunits->setText("Passed Units : " + Extraction::GetPropertyValueByPhoneNumber(fileCE,ui->lineEdit_PhoneSearch->text(),Property::PASSEDUNITS));
                ui->label_student_totalterms->setText("Total Terms : " + Extraction::GetPropertyValueByPhoneNumber(fileCE,ui->lineEdit_PhoneSearch->text(),Property::TOTALTERMS));
                ui->label_student_totalUnits->setText("Total Units : " + Extraction::GetPropertyValueByPhoneNumber(fileCE,ui->lineEdit_PhoneSearch->text(),Property::TOTALUNITS));
            }
            console->ShowMessage("Found",MessageColor::Green);
        }


        else
        {
            console->ShowMessage("Not Found! Check your Inputs Again",MessageColor::Red);
            ui->frame_PersonalInfo->setVisible(0);
            ui->frame_teacher->setVisible(0);
            ui->frame_student->setVisible(0);
            ui->frame_teacher->setVisible(0);
            return;
        }

        ui->frame_PersonalInfo->setVisible(1);
        ui->frame_student->setVisible(1);
        ui->frame_staff->setVisible(0);
        ui->frame_teacher->setVisible(0);
    }
    else if(index == 2)//teacher
    {
        QFile file(PROJECT_PATH + "Database/Teachers/info.txt");
        if(CheckInputExists(&file))
        {
            ui->frame_PersonalInfo->setVisible(1);
            ui->frame_teacher->setVisible(1);
            ui->frame_student->setVisible(0);
            ui->frame_staff->setVisible(0);
            if(ui->radioButton_ID->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_IDSerch->text() , file);
                ui->label_teachers_degree->setText( "Degree : " + Extraction::GetPropertyValueByID(file,ui->lineEdit_IDSerch->text(),Property::DEGREE));
                ui->label_teachers_field->setText( "Field : " + Extraction::GetPropertyValueByID(file,ui->lineEdit_IDSerch->text(),Property::FIELD));
                ui->label_teachers_sci_board->setText( "Scientific Board : " + Extraction::GetPropertyValueByID(file,ui->lineEdit_IDSerch->text(),Property::SCIENTIFICBOARD));
                ui->label_teachers_hoursInWeek->setText( "Work Hours : " + Extraction::GetPropertyValueByID(file,ui->lineEdit_IDSerch->text(),Property::HOURSWEEK));
            }
            else if(ui->radioButton_PhoneNumber->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_PhoneSearch->text() , file);
                ui->label_teachers_degree->setText( "Degree : " + Extraction::GetPropertyValueByPhoneNumber(file,ui->lineEdit_PhoneSearch->text(),Property::DEGREE));
                ui->label_teachers_field->setText( "Field : " + Extraction::GetPropertyValueByPhoneNumber(file,ui->lineEdit_PhoneSearch->text(),Property::FIELD));
                ui->label_teachers_sci_board->setText( "Scientific Board : " + Extraction::GetPropertyValueByPhoneNumber(file,ui->lineEdit_PhoneSearch->text(),Property::SCIENTIFICBOARD));
                ui->label_teachers_hoursInWeek->setText( "Work Hours : " + Extraction::GetPropertyValueByPhoneNumber(file,ui->lineEdit_PhoneSearch->text(),Property::HOURSWEEK));
            }
        }
        else
        {
            ui->frame_PersonalInfo->setVisible(0);
            ui->frame_teacher->setVisible(0);
            ui->frame_student->setVisible(0);
            ui->frame_teacher->setVisible(0);
        }
    }
    else if(index == 3)//staff
    {
        QFile file(PROJECT_PATH + "Database/Staff/info.txt");
        if(CheckInputExists(&file))
        {
            if(ui->radioButton_ID->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_IDSerch->text() , file);
                ui->label_Staff_department->setText( "Department : " + Extraction::GetPropertyValueByID(file,ui->lineEdit_IDSerch->text(),Property::DEPARTMENT));
                ui->label_Staff_type->setText( "Type : " + Extraction::GetPropertyValueByID(file,ui->lineEdit_IDSerch->text(),Property::TYPE));
                ui->label_Staff_workshift->setText( "Work Shift : " + Extraction::GetPropertyValueByID(file,ui->lineEdit_IDSerch->text(),Property::WORKSHIFT));
            }
            else if(ui->radioButton_PhoneNumber->isChecked())
            {
                PrintDataForPersonFrame(ui->lineEdit_PhoneSearch->text() , file);
                ui->label_Staff_department->setText( "Department : " + Extraction::GetPropertyValueByPhoneNumber(file,ui->lineEdit_PhoneSearch->text(),Property::DEPARTMENT));
                ui->label_Staff_type->setText( "Type : " + Extraction::GetPropertyValueByPhoneNumber(file,ui->lineEdit_PhoneSearch->text(),Property::TYPE));
                ui->label_Staff_workshift->setText( "Work Shift : " + Extraction::GetPropertyValueByPhoneNumber(file,ui->lineEdit_PhoneSearch->text(),Property::WORKSHIFT));
            }
        }
        else
        {
            ui->frame_PersonalInfo->setVisible(0);
            ui->frame_teacher->setVisible(0);
            ui->frame_student->setVisible(0);
            ui->frame_teacher->setVisible(0);
            return;
        }


        ui->frame_PersonalInfo->setVisible(1);
        ui->frame_staff->setVisible(1);
        ui->frame_student->setVisible(0);
        ui->frame_teacher->setVisible(0);

    }
    else{}

}
void ShowInformation::on_radioButton_ID_toggled(bool checked)
{
    if(checked)
    {
        ui->label_ChooseLineEdit->setVisible(true);
        ui->label_ChooseLineEdit->setText("Enter ID : ");
        ui->lineEdit_IDSerch->setVisible(true);
        ui->lineEdit_PhoneSearch->setVisible(false);
        ui->lineEdit_PhoneSearch->setText("");

    }

}
void ShowInformation::on_radioButton_PhoneNumber_toggled(bool checked)
{
    if(checked)
    {
        ui->label_ChooseLineEdit->setVisible(true);
        ui->label_ChooseLineEdit->setText("Enter Phone Number : ");
        ui->lineEdit_IDSerch->setVisible(false);
        ui->lineEdit_PhoneSearch->setVisible(true);
        ui->lineEdit_IDSerch->setText("");
    }
}
