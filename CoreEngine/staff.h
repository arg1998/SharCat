#ifndef STAFF_H
#define STAFF_H

#include "person.h"

class Staff : public Person
{
private:

    QString _department;
    QString _type;
    QString _workShift;

public:

    //constructor
    Staff();
    Staff(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);


    //setter functions
    void SetDepartment(QString);
    void SetType(QString);
    void SetWorkShift(QString);

    //getter functions
    QString GetDepartment();
    QString GetType();
    QString GetWorkShift();

};

#endif // STAFF_H
