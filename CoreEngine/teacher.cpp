#include "teacher.h"

Teacher::Teacher()
{
    //default values
    this->_degree = "";
    this->_field = "";
    this->_scientificBoard = "";
    this->_hoursWeek = 0;
}
Teacher::Teacher(QString first_name , QString last_name , QString gender , QString username , QString telenumber ,QString date, QString email , QString id ,QString degree , QString field , QString science , int hoursWeek) :
    Person (first_name,last_name,gender,username,telenumber,date,email,id)
{
        this->_degree = degree;
        this->_field = field;
        this->_scientificBoard = science;
        this->_hoursWeek = hoursWeek;

}



//setter functions

void Teacher::SetDegree(QString degree)
{
     this->_degree = degree;
}
void Teacher::SetField(QString field)
{
    this->_field = field;
}
void Teacher::SetScience(QString science)
{
    this->_scientificBoard =  science;
}
void Teacher::SetHoursWeek(int hour)
{
    this->_hoursWeek = hour;
}



//getter function

QString Teacher::GetDegree()
{
    return  this->_degree;
}

QString Teacher::GetField()
{
    return this->_field;
}

QString Teacher::GetScience()
{
    return this-> _scientificBoard;
}

int Teacher::GetHoursWeek()
{
    return this-> _hoursWeek;

}



