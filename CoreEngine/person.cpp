#include "person.h"

Person::Person()
{   //default
    this->_fName = "";
    this->_lName = "";
    this->_gender = "";
    this->_username = "";
    this->_telenumber = "";
    this->_date = "";
    this->_id = "";



}
Person::Person(QString first_name , QString last_name , QString gender , QString username , QString telenumber , QString date ,QString email,QString id)
{   this->_fName = first_name;
    this->_lName = last_name;
    this->_gender = gender;
    this->_username = username;
    this->_telenumber = telenumber;
    this->_id = id;
    this->_date = date;
    this->_emial = email;
}


//SET functions
void Person::SetFullName(QString first_Name, QString last_Name)
{
    this->_fName = first_Name;
    this->_lName = last_Name;
}

void Person::SetFirstName(QString first_Name)
{
    this->_fName = first_Name;
}

void Person::SetLastName(QString last_Name)
{
    this->_lName = last_Name;
}

void Person::SetSex(QString gender)
{
    this->_gender = gender;
}

void Person::SetUserName(QString user)
{
    this->_username = user;
}

void Person::SetPhoneNumber(QString tele)
{
    this->_telenumber = tele;
}

void Person::SetID(QString id)
{
    this->_id = id;

}

void Person::SetDate(QString date)
{
    this->_date = date;
}
void Person::SetEMail(QString email)
{
    this->_emial = email;
}




//GET functions

QString Person::GetFirstName()
{
   return this->_fName;
}
QString Person::GetLastName()
{
    return this->_lName;
}
QString Person::GetSex()
{
    return this->_gender;
}
QString Person::GetUserName()
{
    return this->_username;
}
QString Person::GetPhoneNumber()
{
    return this->_telenumber;
}
QString Person::GetID()
{
    return this->_id;
}

QString Person::GetDate()
{
    return this->_date;
}

QString Person::GetEMail()
{
    return this->_emial;
}

