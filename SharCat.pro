#-------------------------------------------------
#
# Project created by QtCreator 2017-03-30T12:36:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SharCat
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addstudent.cpp \
    addteacher.cpp \
    addstaff.cpp \
    editinformation.cpp \
    backup.cpp \
    sharcatconsole.cpp\
    showinformation.cpp \
    lock.cpp \
    CoreEngine/database.cpp \
    CoreEngine/person.cpp \
    CoreEngine/staff.cpp \
    CoreEngine/student.cpp \
    CoreEngine/teacher.cpp \
    splashscreen.cpp \
    aboutus.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    addstudent.h \
    addteacher.h \
    addstaff.h \
    editinformation.h \
    backup.h \
    sharcatconsole.h\
    showinformation.h \
    lock.h \
    CoreEngine/corefunctions.h \
    CoreEngine/database.h \
    CoreEngine/flags.h \
    CoreEngine/linux_core.h \
    CoreEngine/person.h \
    CoreEngine/staff.h \
    CoreEngine/student.h \
    CoreEngine/windows_core.h \
    CoreEngine/teacher.h \
    splashscreen.h \
    aboutus.h \
    settings.h

FORMS    += mainwindow.ui \
    addstudent.ui \
    addteacher.ui \
    addstaff.ui \
    editinformation.ui \
    backup.ui \
    sharcatconsole.ui\
    showinformation.ui \
    lock.ui \
    splashscreen.ui \
    aboutus.ui \
    settings.ui

RESOURCES += \
    res.qrc
