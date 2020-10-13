#ifndef DATABASE_H
#define DATABASE_H

#include "corefunctions.h"
#include "student.h"
#include "teacher.h"
#include "staff.h"
#include <QDate>


class DataBase
{
private:
    QString LoadedData;
    QDate date;

public:

    DataBase();

    void AddStudentToFile(Student*,Fields);
    void AddStaffToFile(Staff*);
    void AddTeacherToFile(Teacher*);



    QString LoadDataFromFile(QFile*);
    void WriteDataToFile(QFile*,QString);
};

#endif // DATABASE_H
