#ifndef DBCOREFUNCTIONS_H
#define DBCOREFUNCTIONS_H

#include <QString>
#include <QtCore>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QDir>
#include "flags.h"

//OS Base Header Files , set directory path
//#include "windows_core.h"
#include "linux_core.h"

//text-date format for conversion(if we needed ;-)
const QString DATE_FORMAT = "yyyy/MM/dd";
//qApp->quit();
//QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


//this will rest line numbers in a given full text
static QString ResetLineNumbers(QString &FullText)
{
    QStringList LineList = FullText.split(';');
    for (int i = 0; i < FullText.count(';') ; ++i)
    {
        LineList[i].replace(0,LineList[i].indexOf(':'),QString::number(i));
    }
    FullText = LineList.join(';');
    return FullText;
}
//this is an overloaded function from the one above, this functiopn recievec a file and will automatically reset line numbers
// in it.
static QString ResetLineNumbers(QFile &File)
{
    //section 1: open for read and load data to memory
    File.open(QFile::Text | QFile::ReadOnly);
    QTextStream in(&File);
    in.setCodec("UTF-8");
    QString FullText = in.readAll();

    File.flush();
    File.close();

    //section 2: main part for reseting line numbers
    QStringList LineList = FullText.split(';');
    for (int i = 0; i < FullText.count(';') ; ++i)
    {
        LineList[i].replace(0,LineList[i].indexOf(':'),QString::number(i));
    }
    FullText = LineList.join(";\n");

    //section 3: writing reformated data into data base
    // note: use TRUNCATE for writing, this could be a heavy operation (which means , it needs some optomization ;-)
    File.open(QFile::Truncate | QFile::WriteOnly | QFile::Text );
    QTextStream out(&File);
    out.setCodec("UTF-8");
    out << FullText;

    File.flush();
    File.close();

    //section 4: return reformated FullText as if it needed
    return FullText;
}


//this namespace will handle the directory and file creation works
namespace DirectoryInteractions
{
    //checks id this path exists or not
    static bool DoesPathExist(QString path,bool create = true)
    {
        QDir *dir = new QDir(path);
        if (dir->exists())
        {
            delete dir;
            return true;
        }
        else
        {
            if (create)
            {
                dir->mkpath(path);
            }
            delete dir;
            return false;
        }
    }
    //this function initialize directories and create an empty version of them
    static void SetUpDirectories()
    {
        QDir *dir = new QDir();
        dir->mkpath(PROJECT_PATH+"Local Data/App Settings");
		dir->mkpath(PROJECT_PATH+"Local Data/App Settings/Theme");
        dir->mkpath(PROJECT_PATH+"Local Data/Global Info");
        dir->mkpath(PROJECT_PATH+"Database/Student/Computer ENG");
        dir->mkpath(PROJECT_PATH+"Database/Student/Chemistry ENG");
        dir->mkpath(PROJECT_PATH+"Database/Student/Industrial ENG");
        dir->mkpath(PROJECT_PATH+"Database/Student/Petroleum ENG");
        dir->mkpath(PROJECT_PATH+"Database/Teachers");
        dir->mkpath(PROJECT_PATH+"Database/Staff");

        delete dir;
    }
    static void SetUpFiles()
    {
        QStringList *list = new QStringList();
        list->append(PROJECT_PATH+"Local Data/App Settings/settings.txt");
        list->append(PROJECT_PATH+"Local Data/Global Info/IDs.txt");

        list->append(PROJECT_PATH+"Database/Student/Local Info.txt");
        list->append(PROJECT_PATH+"Database/Student/Computer ENG/info.txt");
        list->append(PROJECT_PATH+"Database/Student/Chemistry ENG/info.txt");
        list->append(PROJECT_PATH+"Database/Student/Industrial ENG/info.txt");
        list->append(PROJECT_PATH+"Database/Student/Petroleum ENG/info.txt");

        list->append(PROJECT_PATH+"Database/Teachers/info.txt");
        list->append(PROJECT_PATH+"Database/Teachers/Local Info.txt");

        list->append(PROJECT_PATH+"Database/Staff/info.txt");
        list->append(PROJECT_PATH+"Database/Staff/Local Info.txt");



        foreach (QString path, *list)
        {
            QFile *file = new QFile(path);
            if (!file->exists())
            {
                file->open(QFile::Append | QFile::WriteOnly);
                if(path.contains("settings.txt"))
                {
                    QTextStream out(file);
                    out << "0:{PASSWORD='' , SHOW_CONSOLE='true' , ID='1364798520' , THEME='Dark.css'};";
                }
                file->flush();
                file->close();
                delete file;
            }
            else
            {
                file->flush();
                file->close();
                delete file;
            }
        }
        delete list;

    }

}

namespace Extraction
{




    static int GetNumberOfLines(QString FullText)
    {
        return (FullText.count(';'));
    }
    //it returns the text between a given character ,
    //input frmat for text should be like this => "name=/AMIR/" => if the FieladSeperator is "/" , "AMIR" gets returned.
    static QString TextBetween(QString text ,char FieldSeperator)
    {
        return text.section(FieldSeperator,1,1);
    }
    //it takes a whole string data(or File) and return the string between "{" and "}" at given line number
    static QString TextAtLine(QString FullText ,char LineSeperator = ';' ,int LineNumber = 0)
    {
        foreach (QString qs , FullText.split(LineSeperator))
        {
            int lineNum = qs.section(':',0,0).trimmed().toInt();
            if (LineNumber == lineNum)
            {
                return qs.section('{',1,1).section('}',0,0);
            }
        }
        return "Not Found !!!";
    }
    static QString TextAtLine(QFile *FileObj ,char LineSeperator = ';',int LineNumber = 0 , bool CloseFile = true)
    {

        FileObj->open(QFile::ReadOnly);
        QTextStream str(FileObj);
        QString FullText = str.readAll();
        foreach (QString qs, FullText.split(LineSeperator))
        {
            int lineNum = qs.section(':',0,-2).trimmed().toInt();
            if (LineNumber == lineNum)
            {
                FileObj->flush();
                FileObj->close();
                return qs.section('{',1,1).section('}',0,-2);
            }
        }
        if (CloseFile)
        {
            FileObj->flush();
            FileObj->close();
        }
        return "Not Found !!!";
    }
    static QString ReturnOnlyProperties(QString TextLine)
    {
        return TextLine.section('{',1,1).section('}',0,-2);
    }
    //returns the value which assigned to that property
    //input format must be like this => "NAME='Afshin',ID='811995165'"
    static QString GetPropertyValueAtLine(QString OnlyProperties , Property PropertyName)
    {
        foreach (QString text, OnlyProperties.split(','))
        {
            if (text.indexOf(PropertyString(PropertyName)) != -1)
            {
                return text.section('\'',1,1);
            }
        }
        return "Not Found !!!";
    }
    static QString GetPropertyValueAtLine(QString FullText ,int LineNumber , Property PropertyName )
    {
        return GetPropertyValueAtLine(TextAtLine(FullText,';',LineNumber),PropertyName);
    }
    //it returns the requiered value by searching through the entire Text by giving an unique ID
    static QString GetPropertyValueByID(QString FullText, QString ID , Property PropertyName)
    {
        foreach (QString TempText, FullText.split(';'))
        {
            if (ID == GetPropertyValueAtLine(ReturnOnlyProperties(TempText),Property::ID))
            {
                return GetPropertyValueAtLine(ReturnOnlyProperties(TempText),PropertyName);
            }
        }
        return "Not Found !!!";
    }
    static QString GetPropertyValueByID(QFile &file, QString ID , Property PropertyName)
    {
        file.open(QFile::ReadOnly);
        QTextStream in(&file);
        in.setCodec("UTF-8");

        QString FullText = in.readAll();

        foreach (QString TempText, FullText.split(';'))
        {
            if (ID == GetPropertyValueAtLine(ReturnOnlyProperties(TempText),Property::ID))
            {
                file.flush();
                file.close();
                return GetPropertyValueAtLine(ReturnOnlyProperties(TempText),PropertyName);
            }
        }
        file.close();
        return "Not Found !!!";
    }
    static QString GetPropertyValueByPhoneNumber(QFile &file, QString PhoneNum , Property PropertyName)
    {
        file.open(QFile::ReadOnly | QFile::Text);
        QTextStream in(&file);
        in.setCodec("UTF-8");

        QString FullText = in.readAll();

        foreach (QString TempText, FullText.split(';'))
        {
            if (PhoneNum == GetPropertyValueAtLine(ReturnOnlyProperties(TempText),Property::PHONE))
            {
                file.flush();
                file.close();
                return GetPropertyValueAtLine(ReturnOnlyProperties(TempText),PropertyName);
            }
        }
        file.close();
        return "Not Found !!!";
    }
    static bool DoesExist(QFile &file , QString value , Qt::CaseSensitivity CaseSensitivity = Qt::CaseInsensitive)
    {
        //AmirReza

        //-> amirreza
        file.close();
        file.open(QFile::ReadOnly | QFile::Text);
        QTextStream in(&file);
        QString FullText = in.readAll();

        foreach (QString tempText, FullText.split(';'))
        {
            if (tempText.contains(value,CaseSensitivity))
            {
               file.flush();
               file.close();
               return true;
            }
        }
        file.flush();
        file.close();
        return false;
    }

    static QString GetSettingValue(Property property)
    {
        QFile settingFile(PROJECT_PATH+"Local Data/App Settings/settings.txt");
        if(property == Property::PASSWORD)
        {
            return Extraction::GetPropertyValueByID(settingFile,"1364798520",Property::PASSWORD);
        }
        else if(property == Property::THEME)
        {
            return Extraction::GetPropertyValueByID(settingFile,"1364798520",Property::THEME);
        }
        else if(property == Property::SHOW_CONSOLE)
        {
            return Extraction::GetPropertyValueByID(settingFile,"1364798520",Property::SHOW_CONSOLE);
        }
    }
    static QString GetCurrentThemeStyleSheet()
    {
        QFile themePath(PROJECT_PATH+"Local Data/App Settings/Theme/" + GetSettingValue(Property::THEME));
        themePath.open(QFile::ReadOnly | QFile::Text);
        QString tempCSS;
        QTextStream out(&themePath);
        out.setCodec("UTF-8");
        tempCSS = out.readAll();
        themePath.flush();
        themePath.close();
        return tempCSS;
    }

}

namespace Insertion
{
    static QString EditPropertyAtLine(Property PropertyName,QString NewValue, QString FullText,int LineNumber ,ReturnType RType)
    {
        QString result;

        foreach (QString line, FullText.split(';'))
        {
            int lineNum = line.section(':',0,-2).trimmed().toInt();
            if (LineNumber == lineNum)
            {
                int start = line.indexOf(PropertyString(PropertyName)) + PropertyString(PropertyName).length() + 2;
                int length = Extraction::GetPropertyValueAtLine(FullText,LineNumber,PropertyName).length();

                result = line.replace(start, length ,NewValue);
                if(RType == ReturnType::SelectedLine)
                {
                    return result;
                }
            }
        }
        if (RType == ReturnType::FullText)
        {
            QStringList list = FullText.split(';');
            list[LineNumber] = result;
            return list.join(';');

        }
        return "Nothing...";
    }
    static QString EditPropertyByID(QString ID,Property PropertyName,QString NewValue, QString FullText , ReturnType RType)
    {
        QString result;
        int LineNumber;

        foreach (QString TempText, FullText.split(';'))
        {
            if (ID == Extraction::GetPropertyValueAtLine(Extraction::ReturnOnlyProperties(TempText),Property::ID))
            {
                int start = TempText.indexOf(PropertyString(PropertyName)) + PropertyString(PropertyName).length() + 2;
                int length = Extraction::GetPropertyValueByID(FullText,ID,PropertyName).length();
                LineNumber = TempText.section(':',0,-2).trimmed().toInt();

                result = TempText.replace(start, length ,NewValue);
                if(RType == ReturnType::SelectedLine)
                {
                    return result;
                }
            }
        }
        if (RType == ReturnType::FullText)
        {
            QStringList list = FullText.split(';');
            list[LineNumber] = result;
            return list.join(';');

        }
        return "Nothing...";
    }
	static QString EditPropertyByID(QString ID,Property PropertyName,QString NewValue, QFile &file , ReturnType RType)
    {
        file.open(QFile::ReadOnly);
        QTextStream ts(&file);

        QString FullText = ts.readAll();
        file.flush();
        file.close();

        QString result;
        int LineNumber;

        foreach (QString TempText, FullText.split(';'))
        {
            if (ID == Extraction::GetPropertyValueAtLine(Extraction::ReturnOnlyProperties(TempText),Property::ID))
            {
                int start = TempText.indexOf(PropertyString(PropertyName)) + PropertyString(PropertyName).length() + 2;
                int length = Extraction::GetPropertyValueByID(FullText,ID,PropertyName).length();
                LineNumber = TempText.section(':',0,-2).trimmed().toInt();

                result = TempText.replace(start, length ,NewValue);
                if(RType == ReturnType::SelectedLine)
                {
                    return result;
                }
            }
        }
        if (RType == ReturnType::FullText)
        {
            QStringList list = FullText.split(';');
            list[LineNumber] = result;
            file.open(QFile::Text | QFile::Truncate | QFile::WriteOnly);
            QTextStream out(&file);
            out << list.join(';');
            file.flush();
            file.close();



            return list.join(';');

        }
        return "Nothing...";
    }
    static QString DeleteInfoAtLine(int LineNumber , QString &FullText , bool resetLineNumbers = true)
    {
        int tempLineNumber;
        QStringList List = FullText.split(';');

        foreach (QString LineText, List)
        {
            tempLineNumber = LineText.section(':',0,-2).trimmed().toInt();
            if (tempLineNumber == LineNumber)
            {
                   List.removeAt(tempLineNumber);
                   break;
            }
        }
        FullText = List.join(';');
        if (resetLineNumbers)
        {
            return ResetLineNumbers(FullText);
        }
        return FullText;
    }
    static QString DeleteInfoByID(QString ID , QString &FullText , bool resetLineNumbers = true)
    {
        int tempLineNumber;
        QStringList List = FullText.split(';');

        foreach (QString LineText, List)
        {
            tempLineNumber = LineText.section(':',0,-2).trimmed().toInt();
            if (ID == Extraction::GetPropertyValueAtLine(Extraction::ReturnOnlyProperties(LineText),Property::ID))
            {
                   List.removeAt(tempLineNumber);
                   break;
            }
        }
        FullText = List.join(";");
        if (resetLineNumbers)
        {
            return ResetLineNumbers(FullText);
        }
        return FullText;
    }
    static QString DeleteInfoByID(QString ID , QFile &file , bool resetLineNumbers = true)
    {
        file.close();
        file.open(QFile::ReadOnly);
        QTextStream in(&file);
        QString FullText = in.readAll();
        file.flush();
        file.close();

        QString NewText = DeleteInfoByID(ID,FullText,resetLineNumbers);


        file.open(QFile::Text|QFile::Truncate|QFile::WriteOnly);
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out << NewText;
        file.flush();
        file.close();
        return "";
    }
    static QString GenerateProperty(Property PropertyName , QString value)
    {
        return ( PropertyString(PropertyName) + "='" + value + "'" );
    }
}

namespace Security 
{
    static QString getHashPassWord(QString password)
    {
        QVariant pass(password.toUtf8());
        QByteArray ba = pass.toByteArray();
        QCryptographicHash hash(QCryptographicHash::Sha3_512);
        hash.addData(ba);
        QVariant result(hash.result().toHex());
        return result.toString();
    }

}

static QString SortDataByProperty(QString &FullText , Property SortBase)
{
    QStringList list = FullText.split(';');
    bool Continue = false;
    for (int i = list.length()-2; i > -1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            QString Previous = Extraction::GetPropertyValueAtLine(Extraction::ReturnOnlyProperties(list[j]),SortBase).toLower();
            QString After = Extraction::GetPropertyValueAtLine(Extraction::ReturnOnlyProperties(list[j+1]),SortBase).toLower();
            if (Previous.compare(After) >= 1)
            {
                list.swap(j+1,j);
                Continue = true;
            }

        }
        if (!Continue) { break; }
    }
    FullText = list.join(';');
    return FullText;
}


#endif // DBCOREFUNCTIONS_H
