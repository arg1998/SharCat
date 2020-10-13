#include "student.h"

Student::Student()
{
    //default
    this->_fieldName = "";
    this->_entryYear = "";
    this->_currentTerm = 0;
    this->_totalTerms = 0;
    this->_totalUnits = 0;
    this->_passedUnits = 0;

}

Student::Student(QString first_name , QString last_name , QString gender , QString username , QString telenumber ,QString date, QString email , QString id ,QString fieldName, QString entryYear, int currentTerm , int totalTerms , int totalUnits , int passedUnits) :
    Person(first_name,last_name,gender,username,telenumber,date,email,id)
{
    this->_fieldName = fieldName;
    this->_entryYear = entryYear;
    this->_currentTerm = currentTerm;
    this->_totalTerms = totalTerms;
    this->_totalUnits = totalUnits;
    this->_passedUnits = passedUnits;

}


//setter functions

void Student::SetFieldName(QString fieldName)
{
    this->_fieldName = fieldName;
}
void Student::SetEntryYear(QString entryYear)
{
    this->_entryYear = entryYear;
}

void Student::SetCurrentTerm(int currentTerm)
{
    this->_currentTerm = currentTerm;
}
void Student::SetTotalTerms(int totalTerms)
{
    this->_totalTerms = totalTerms;
}
void Student::SetTotalUnits(int totalUnits)
{
    this->_totalUnits = totalUnits;
}
void Student::SetPassedUnits(int passedUnits)
{
    this->_passedUnits = passedUnits;
}


//getter functions

QString Student::GetFieldName()
{
    return this->_fieldName;
}
QString Student::GetEntryYear()
{
    return this->_entryYear;
}

int Student::GetCurrentTerm()
{
    return this->_currentTerm;
}
int Student::GetTotalTerms()
{
    return this->_totalTerms;
}
int Student::GetTotalUnits()
{
    return this->_totalUnits;
}
int Student::GetPassedUnits()
{
    return this->_passedUnits;
}


