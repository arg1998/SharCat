#include "staff.h"

Staff::Staff()
{
    this->_department ="";
    this->_type ="";
    this->_workShift ="";
}

Staff::Staff(QString first_name , QString last_name , QString gender , QString username , QString telenumber ,QString date, QString email , QString id , QString department , QString type , QString workShift) :
    Person(first_name,last_name,gender,username,telenumber,date,email,id)
{
    this->_department = department;
    this->_type = type;
    this->_workShift = workShift;
}

//setter functions

void Staff::SetDepartment(QString department)
{
    this->_department = department;
}

void Staff::SetType(QString type)
{
    this->_type = type;
}

void Staff::SetWorkShift(QString work)
{
    this->_workShift = work;
}

//getter functions

QString Staff::GetDepartment()
{
    return this->_department;
}

QString Staff::GetType()
{
    return this->_type;
}
QString Staff::GetWorkShift()
{
    return this->_workShift;
}


