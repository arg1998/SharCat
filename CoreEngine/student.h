#ifndef STUDENT_H
#define STUDENT_H


#include "person.h"


class Student : public Person
{
private:

    QString _fieldName;
    QString _entryYear;
    int _currentTerm;
    int _totalTerms;
    int _totalUnits;
    int _passedUnits;

public:

   //constructor
   Student();
   Student(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,int,int,int,int);


   //setter functions 
   void SetFieldName(QString);
   void SetEntryYear(QString);
   void SetCurrentTerm(int);
   void SetTotalTerms(int);
   void SetTotalUnits(int);
   void SetPassedUnits(int);

   //getter functions
   QString GetFieldName();
   QString GetEntryYear();
   int GetCurrentTerm();
   int GetTotalTerms();
   int GetTotalUnits();
   int GetPassedUnits();
};

#endif // STUDENT_H
