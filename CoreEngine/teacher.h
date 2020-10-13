#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

class Teacher : public Person
{
private:

    QString _degree;
    QString _field;
    QString _scientificBoard;
    int _hoursWeek;

public:
    //constructor
    Teacher();
    Teacher(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,int);

    //setter functions
    void SetDegree(QString);
    void SetField(QString);
    void SetScience(QString);
    void SetHoursWeek(int);

    //getter functions
    QString GetDegree();
    QString GetField();
    QString GetScience();
    int GetHoursWeek();

};

#endif // TEACHER_H
