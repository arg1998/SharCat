#include "database.h"

DataBase::DataBase()
{

}

void DataBase::AddStudentToFile(Student *student , Fields field)
{
    QString Props = ":{";
    QFile *file;


    Props += Insertion::GenerateProperty(Property::FNAME,student->GetFirstName()) + " , ";
    Props += Insertion::GenerateProperty(Property::LNAME,student->GetLastName()) + " , ";
    Props += Insertion::GenerateProperty(Property::ID,student->GetID()) + " , ";
    Props += Insertion::GenerateProperty(Property::GENDER,student->GetSex()) + " , ";
    Props += Insertion::GenerateProperty(Property::USERNAME,student->GetUserName()) + " , ";
    Props += Insertion::GenerateProperty(Property::EMAIL,student->GetEMail()) + " , ";
    Props += Insertion::GenerateProperty(Property::DATE,student->GetDate()) + " ,";
    Props += Insertion::GenerateProperty(Property::PHONE,student->GetPhoneNumber()) + " , ";
    Props += Insertion::GenerateProperty(Property::MODIFICATIONDATE,date.currentDate().toString("yyyy/MM/dd")) + " , ";

    Props += Insertion::GenerateProperty(Property::FIELDNAME,student->GetFieldName()) + " , ";
    Props += Insertion::GenerateProperty(Property::ENTRYYEAR,student->GetEntryYear()) + " , ";
    Props += Insertion::GenerateProperty(Property::TOTALTERMS,QString::number(student->GetTotalTerms())) + " , ";
    Props += Insertion::GenerateProperty(Property::CURRENTTERM,QString::number(student->GetCurrentTerm())) + " , ";
    Props += Insertion::GenerateProperty(Property::TOTALUNITS,QString::number(student->GetTotalUnits())) + " , ";
    Props += Insertion::GenerateProperty(Property::PASSEDUNITS,QString::number(student->GetPassedUnits())) + "};";



    if (field == Fields::ComputerENG)
    {
            file = new QFile(PROJECT_PATH + "Database/Student/Computer ENG/info.txt");
            file->open(QFile::Text | QFile::Append | QFile::WriteOnly);
            QTextStream outfile(file);
            outfile.setCodec("UTF-8");

            outfile << Props;
            file->flush();
            file->close();

    }
    else if (field == Fields::ChemistryENG)
    {
        file = new QFile(PROJECT_PATH + "Database/Student/Chemistry ENG/info.txt");
        file->open(QFile::Text | QFile::Append | QFile::WriteOnly);
        QTextStream outfile(file);
        outfile.setCodec("UTF-8");

        outfile << Props;
        file->flush();
        file->close();
    }
    else if (field == Fields::IndustrialENG)
    {
        file = new QFile(PROJECT_PATH + "Database/Student/Industrial ENG/info.txt");
        file->open(QFile::Text | QFile::Append | QFile::WriteOnly);
        QTextStream outfile(file);
        outfile.setCodec("UTF-8");

        outfile << Props;
        file->flush();
        file->close();
    }
    if (field == Fields::PetroleumENG)
    {
        file = new QFile(PROJECT_PATH + "Database/Student/Petroleum ENG/info.txt");
        file->open(QFile::Text | QFile::Append | QFile::WriteOnly);
        QTextStream outfile(file);
        outfile.setCodec("UTF-8");

        outfile << Props;
        file->flush();
        file->close();
    }
    else{}
    Props = "";
    delete file;

}

void DataBase::AddStaffToFile(Staff *staff)
{
    QString Props = ":{";
    QFile *file;


    Props += Insertion::GenerateProperty(Property::FNAME,staff->GetFirstName()) + " , ";
    Props += Insertion::GenerateProperty(Property::LNAME,staff->GetLastName()) + " , ";
    Props += Insertion::GenerateProperty(Property::ID,staff->GetID()) + " , ";
    Props += Insertion::GenerateProperty(Property::GENDER,staff->GetSex()) + " , ";
    Props += Insertion::GenerateProperty(Property::USERNAME,staff->GetUserName()) + " , ";
    Props += Insertion::GenerateProperty(Property::EMAIL,staff->GetEMail()) + " , ";
    Props += Insertion::GenerateProperty(Property::DATE,staff->GetDate()) + " ,";
    Props += Insertion::GenerateProperty(Property::PHONE,staff->GetPhoneNumber()) + " , ";

    Props += Insertion::GenerateProperty(Property::DEPARTMENT,staff->GetDepartment()) + " , ";
    Props += Insertion::GenerateProperty(Property::TYPE,staff->GetType()) + " , ";
    Props += Insertion::GenerateProperty(Property::WORKSHIFT,staff->GetWorkShift()) + "};";



    file = new QFile(PROJECT_PATH + "Database/Staff/info.txt");
    file->open(QFile::Text | QFile::Append | QFile::WriteOnly);
    QTextStream outfile(file);
    outfile.setCodec("UTF-8");

    outfile << Props;
    file->flush();
    file->close();

    Props = "";
    delete file;

}

void DataBase::AddTeacherToFile(Teacher *teacher)
{
    QString Props = ":{";
    QFile *file;


    Props += Insertion::GenerateProperty(Property::FNAME,teacher->GetFirstName()) + " , ";
    Props += Insertion::GenerateProperty(Property::LNAME,teacher->GetLastName()) + " , ";
    Props += Insertion::GenerateProperty(Property::ID,teacher->GetID()) + " , ";
    Props += Insertion::GenerateProperty(Property::GENDER,teacher->GetSex()) + " , ";
    Props += Insertion::GenerateProperty(Property::USERNAME,teacher->GetUserName()) + " , ";
    Props += Insertion::GenerateProperty(Property::EMAIL,teacher->GetEMail()) + " , ";
    Props += Insertion::GenerateProperty(Property::DATE,teacher->GetDate()) + " ,";
    Props += Insertion::GenerateProperty(Property::PHONE,teacher->GetPhoneNumber()) + " , ";

    Props += Insertion::GenerateProperty(Property::DEGREE,teacher->GetDegree()) + " , ";
    Props += Insertion::GenerateProperty(Property::FIELD,teacher->GetField()) + " , ";
    Props += Insertion::GenerateProperty(Property::SCIENTIFICBOARD,teacher->GetScience()) + " , ";
    Props += Insertion::GenerateProperty(Property::HOURSWEEK,QString::number(teacher->GetHoursWeek())) + "};";


    file = new QFile(PROJECT_PATH + "Database/Teachers/info.txt");
    file->open(QFile::Text | QFile::Append | QFile::WriteOnly);
    QTextStream outfile(file);
    outfile.setCodec("UTF-8");

    outfile << Props;
    file->flush();
    file->close();

    Props = "";
    delete file;

}

QString DataBase::LoadDataFromFile(QFile *file)
{
    file->open(QFile::Text | QFile::ReadOnly);
    QTextStream in(file);
    in.setCodec("UTF-8");

    return in.readAll();
}

void DataBase::WriteDataToFile(QFile *file, QString FullText)
{
    file->open(QFile::Text | QFile::Append | QFile::WriteOnly);
    QTextStream out(file);
    out.setCodec("UTF-8");

    out << FullText;

    file->flush();
    file->close();

    delete file;

}
