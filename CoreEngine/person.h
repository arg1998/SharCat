#ifndef PERSON_H
#define PERSON_H

#include <QString>


class Person
{
private:
    QString _fName;
    QString _lName;
    QString _gender;
    QString _username;
    QString _telenumber;
    QString _date;
    QString _emial;
    QString _id;


public:
   //constructor
    Person();
    Person(QString,QString,QString,QString,QString,QString,QString,QString);


    //setter function
    void SetFullName(QString first_Name, QString last_Name);
    void SetFirstName(QString);
    void SetLastName(QString);
    void SetSex(QString);
    void SetUserName(QString);
    void SetPhoneNumber(QString);
    void SetDate(QString);
    void SetEMail(QString);
    void SetID(QString);




    //getter function
    QString GetFirstName();
    QString GetLastName();
    QString GetSex();
    QString GetUserName();
    QString GetPhoneNumber();
    QString GetDate();
    QString GetEMail();
    QString GetID();


};





#endif // PERSON_H
