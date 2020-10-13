#include "backup.h"
#include "ui_backup.h"

BackUp::BackUp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BackUp)
{
    ui->setupUi(this);
    LoadTheme();
    QPropertyAnimation *animIn = new QPropertyAnimation(this,"windowOpacity",this);
    animIn->setDuration(500);
    animIn->setStartValue(0.0);
    animIn->setEndValue(1.0);
    animIn->start();

    ui->frame_Seperate_files->setVisible(false);
    ui->frame__restore_All->setVisible(false);
    ui->frame_Seperate_files_restore->setVisible(false);
    ui->frame__restore_Student->setVisible(false);
    ui->frame_restore_te->setVisible(false);
    ui->frame_restore_Staff->setVisible(false);
    ui->radioButton_all_file_backup->setChecked(false);
    ui->radioButton_all_file_restore->setChecked(false);
    ui->radioButton_Seperate_file_backup->setChecked(false);
    ui->radioButton_Seperate_file_restore->setChecked(false);

    console = new SharCatConsole(this);
    console->setGeometry( this->x() ,0, 300,400);
    console->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    console->setWindowTitle("$harCat Console >> Backup and Restore");
    if(Extraction::GetSettingValue(Property::SHOW_CONSOLE) == "true")
    {
        console->show();
    }
}

BackUp::~BackUp()
{
    delete ui;
}



void BackUp::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}

void BackUp::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}
void BackUp::on_pushButton_Close_clicked()
{
    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    animOut->start();
    console->close();
}

void BackUp::on_radioButton_Seperate_file_backup_toggled(bool checked)
{

    if (checked)
    {
        ui->frame_Seperate_files->setVisible(true);
    }
    else
    {
        ui->frame_Seperate_files->setVisible(false);
    }
}

void BackUp::on_pushButton_Select_path_clicked()
{
    ui->lineEdit_path_backup->setText(QFileDialog::getExistingDirectory(this,"Select Directory","",QFileDialog::ShowDirsOnly));
}

void BackUp::on_radioButton_all_file_restore_toggled(bool checked)
{
    if (checked)
    {
        ui->frame__restore_All->setVisible(true);
        ui->frame_Seperate_files_restore->setVisible(false);
    }
    else
    {
        ui->frame__restore_All->setVisible(false);
        ui->frame_Seperate_files_restore->setVisible(true);
    }
}

void BackUp::on_checkBox_Student_restore_toggled(bool checked)
{
    if (checked)
    {
       ui->frame__restore_Student->setVisible(true);
    }
    else
    {
        ui->frame__restore_Student->setVisible(false);

    }
}

void BackUp::on_checkBox_Teacher_restore_toggled(bool checked)
{
    if (checked)
    {
       ui->frame_restore_te->setVisible(true);
    }
    else
    {
        ui->frame_restore_te->setVisible(false);
    }
}

void BackUp::on_checkBox_staff_restore_toggled(bool checked)
{
    if (checked)
    {
       ui->frame_restore_Staff->setVisible(true);
    }
    else
    {
        ui->frame_restore_Staff->setVisible(false);

    }
}

void BackUp::on_pushButton_Select_path_restore_Student_clicked()
{
    ui->lineEdit_path_restore_Student->setText(QFileDialog::getOpenFileName(this,"Select File to Restore Data","","DataCat Files (STUDENTS_BACKUP.cat)"));
}

void BackUp::on_pushButton_Select_path_restore_Te_clicked()
{
    ui->lineEdit_path_restore_Te->setText(QFileDialog::getOpenFileName(this,"Select File to Restore Data","","DataCat Files (TEACHERS_BACKUP.cat)"));
}

void BackUp::on_pushButton_Select_path_restore_staff_clicked()
{
    ui->lineEdit_path_restore_Staff->setText(QFileDialog::getOpenFileName(this,"Select File to Restore Data","","DataCat Files (STAFF_BACKUP.cat)"));
}

void BackUp::on_pushButton_Select_path_restore_All_clicked()
{
    ui->lineEdit_path_restore_All->setText(QFileDialog::getExistingDirectory(this,"Select Directory","",QFileDialog::ShowDirsOnly));
}

void BackUp::on_radioButton_Seperate_file_restore_toggled(bool checked)
{
    if (checked)
    {
       ui->frame_Seperate_files_restore->setVisible(true);
    }
}




void BackUp::on_pushButton_backup_clicked()
{
    QString pathDir = ui->lineEdit_path_backup->text();
    if (pathDir != "")
    {
        QDir buDir;
        if(!buDir.exists(pathDir+"/SharCat_BACKUP"))
        {
            console->ShowMessage("Creating Base Directory ...",MessageColor::Black);
            buDir.mkpath(pathDir+"/SharCat_BACKUP");
            console->ShowMessage("Base Directory Created",MessageColor::Green);
        }

        QFile stuFile(pathDir+"/SharCat_BACKUP/STUDENTS_BACKUP.cat");
        QFile teaFile(pathDir+"/SharCat_BACKUP/TEACHERS_BACKUP.cat");
        QFile staFile(pathDir+"/SharCat_BACKUP/STAFF_BACKUP.cat");
        if(stuFile.exists()) stuFile.remove();
        if(teaFile.exists()) teaFile.remove();
        if(staFile.exists()) staFile.remove();
        QStringList filesPathes;
        filesPathes <<
        PROJECT_PATH+"Database/Student/Computer ENG/info.txt" <<
        PROJECT_PATH+"Database/Student/Chemistry ENG/info.txt"<<
        PROJECT_PATH+"Database/Student/Industrial ENG/info.txt"<<
        PROJECT_PATH+"Database/Student/Petroleum ENG/info.txt";


        if(ui->radioButton_all_file_backup->isChecked())
        {
            console->ShowMessage("Baking Up Entire Database",MessageColor::Green);
            foreach (QString filepath, filesPathes)
            {
                QFile file(filepath);
                file.open(QFile::ReadOnly | QFile::Text);
                QTextStream in(&file);
                in.setCodec("UTF-8");
                stuFile.open(QFile::WriteOnly | QFile::Text | QFile::Append);
                QTextStream out(&stuFile);
                out.setCodec("UTF-8");
                out << in.readAll() << "%" << "\n";
                file.close();
                stuFile.close();
            }
            QFile::copy(PROJECT_PATH+"Database/Teachers/info.txt" , pathDir+"/SharCat_BACKUP/TEACHERS_BACKUP.cat");
            QFile::copy(PROJECT_PATH+"Database/Staff/info.txt"    , pathDir+"/SharCat_BACKUP/STAFF_BACKUP.cat");

            console->ShowMessage("Entire Database Has Been Backed Up",MessageColor::Green);
        }
        else if(ui->radioButton_Seperate_file_backup->isChecked())
        {
            if(ui->checkBox_Student->isChecked())
            {
                foreach (QString filepath, filesPathes)
                {
                    QFile file(filepath);
                    file.open(QFile::ReadOnly | QFile::Text);
                    QTextStream in(&file);
                    in.setCodec("UTF-8");
                    stuFile.open(QFile::WriteOnly | QFile::Text | QFile::Append);
                    QTextStream out(&stuFile);
                    out.setCodec("UTF-8");
                    out << in.readAll() << "%" << "\n";
                    file.close();
                    stuFile.close();
                }
                console->ShowMessage("Information For Students Has Been Backed Up",MessageColor::Green);
            }
            if(ui->checkBox_Teacher->isChecked())
            {
                QFile::copy(PROJECT_PATH+"Database/Teachers/info.txt" , pathDir+"/SharCat_BACKUP/TEACHERS_BACKUP.cat");
                console->ShowMessage("Information For Staffs Has Been Backed Up",MessageColor::Green);
            }
            if(ui->checkBox_staff->isChecked())
            {
                QFile::copy(PROJECT_PATH+"Database/Staff/info.txt" , pathDir+"/SharCat_BACKUP/STAFF_BACKUP.cat");
                console->ShowMessage("Information For Teachers Has Been Backed Up",MessageColor::Green);
            }
        }

    }
    else
    {
        console->ShowMessage("Select A Proper Directory",MessageColor::Red);
    }
}

void BackUp::on_pushButton_restore_clicked()
{

    DirectoryInteractions::SetUpDirectories();
    console->ShowMessage("Setting Up Directories",MessageColor::Black);

    if(ui->radioButton_all_file_restore->isChecked())
    {
        console->ShowMessage("Restoring Entire Database",MessageColor::Black);
        QString baseDirPath = ui->lineEdit_path_restore_All->text();
        if(baseDirPath == "")
        {
            console->ShowMessage("Select A Dirctory Which Contains Backup Files",MessageColor::Red);
        }
        else
        {
            QFile stuFile(baseDirPath+"/STUDENTS_BACKUP.cat");
            QFile teaFile(baseDirPath+"/TEACHERS_BACKUP.cat");
            QFile staFile(baseDirPath+"/STAFF_BACKUP.cat");


            if(stuFile.exists())
            {
                stuFile.open(QFile::ReadOnly);
                QTextStream in(&stuFile);
                in.setCodec("UTF-8");
                QStringList infos = in.readAll().split('%');
                int i = 0;


                QStringList filesPathes;
                filesPathes <<
                PROJECT_PATH+"Database/Student/Computer ENG/info.txt" <<
                PROJECT_PATH+"Database/Student/Chemistry ENG/info.txt"<<
                PROJECT_PATH+"Database/Student/Industrial ENG/info.txt"<<
                PROJECT_PATH+"Database/Student/Petroleum ENG/info.txt";

                foreach (QString filePath, filesPathes)
                {
                    QFile file(filePath);
                    file.open(QFile::Text | QFile::Truncate | QFile::WriteOnly);
                    QTextStream out(&file);
                    out << infos.at(i);
                    i++;
                    file.close();
                }
                console->ShowMessage("Students Information Has Been Restored",MessageColor::Green);

            }
            if(teaFile.exists())
            {
                QFile::remove(PROJECT_PATH+"Database/Teachers/info.txt");
                teaFile.copy(PROJECT_PATH+"Database/Teachers/info.txt");
                console->ShowMessage("Teachers Information Has Been Restored",MessageColor::Green);
            }
            if(staFile.exists())
            {
                QFile::remove(PROJECT_PATH+"Database/Staff/info.txt");
                staFile.copy(PROJECT_PATH+"Database/Staff/info.txt");
                console->ShowMessage("Staffs Information Has Been Restored",MessageColor::Green);
            }
        }
    }




    else if(ui->radioButton_Seperate_file_restore->isChecked())
    {
        if(ui->checkBox_Student_restore->isChecked())
        {
            if(ui->lineEdit_path_restore_Student->text()=="")
            {
               console->ShowMessage("Couldn't Find The File",MessageColor::Red);
            }

            QFile stuFile(ui->lineEdit_path_restore_Student->text());
            if(stuFile.exists())
            {
                stuFile.open(QFile::ReadOnly);
                QTextStream in(&stuFile);
                in.setCodec("UTF-8");
                QStringList infos = in.readAll().split('%');
                int i = 0;


                QStringList filesPathes;
                filesPathes <<
                PROJECT_PATH+"Database/Student/Computer ENG/info.txt" <<
                PROJECT_PATH+"Database/Student/Chemistry ENG/info.txt"<<
                PROJECT_PATH+"Database/Student/Industrial ENG/info.txt"<<
                PROJECT_PATH+"Database/Student/Petroleum ENG/info.txt";

                foreach (QString filePath, filesPathes)
                {
                    QFile file(filePath);
                    file.open(QFile::Text | QFile::Truncate | QFile::WriteOnly);
                    QTextStream out(&file);
                    out << infos.at(i);
                    i++;
                    file.close();
                }
                console->ShowMessage("Students Information Has Been Restored",MessageColor::Green);
            }
        }


        if(ui->checkBox_Teacher_restore->isChecked())
        {
            if(ui->lineEdit_path_restore_Te->text()=="")
            {
                console->ShowMessage("Couldn't Find The File",MessageColor::Red);
            }
            else
            {
                QFile teaFile(PROJECT_PATH+"Database/Teachers/info.txt");
                teaFile.remove();
                QFile::copy(ui->lineEdit_path_restore_Te->text(),PROJECT_PATH+"Database/Teachers/info.txt");
                console->ShowMessage("Teachers Information Has Been Restored",MessageColor::Green);
            }


        }
        if(ui->checkBox_staff_restore->isChecked())
        {
            if(ui->lineEdit_path_restore_Te->text()=="")
            {
                console->ShowMessage("Couldn't Find The File",MessageColor::Red);
            }
            else
            {
                QFile staFile(PROJECT_PATH+"Database/Staff/info.txt");
                staFile.remove();
                QFile::copy(ui->lineEdit_path_restore_Staff->text(),PROJECT_PATH+"Database/Staff/info.txt");
                console->ShowMessage("Staffs Information Has Been Restored",MessageColor::Green);
            }

        }

}
}
