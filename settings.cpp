#include "settings.h"
#include "ui_settings.h"

#include <QDebug>


Settings::Settings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    LoadTheme();


    console = new SharCatConsole(this);
    console->setGeometry( this->x() ,0, 300,400);
    console->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    console->setWindowTitle("$harCat Console >> settings");
    if(Extraction::GetSettingValue(Property::SHOW_CONSOLE) == "true")
    {
        console->show();
    }

    QPropertyAnimation *animIn = new QPropertyAnimation(this,"windowOpacity",this);
    animIn->setDuration(500);
    animIn->setStartValue(0.0);
    animIn->setEndValue(1.0);
    animIn->start();

    //hide password frames
    ui->frame_settings_changePass->setVisible(false);
    ui->frame_settings_newPass->setVisible(false);
    newPass = false;
    changPass = false;

    GetThemes();

    //initializing
    Pass = "";
    showConsole = "True";
    theme = "";
    LoadSettings();

    //theme changine and restarting the app
    isThemeChanged = false;
    currentThemeIndex = ui->comboBox_setting_theme->currentIndex();


}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_Close_clicked()
{
    QPropertyAnimation *animOut = new QPropertyAnimation(this,"windowOpacity",this);
    animOut->setDuration(500);
    animOut->setStartValue(1.0);
    animOut->setEndValue(0.0);
    connect(animOut,SIGNAL(finished()),this,SLOT(close()));
    connect(animOut,SIGNAL(finished()),console,SLOT(close()));
    animOut->start();

}
void Settings::mouseMoveEvent(QMouseEvent *event)
{
    this->setGeometry(event->globalX() - Xbefore,event->globalY() - Ybefore,this->width() ,this->height());
}

void Settings::mousePressEvent(QMouseEvent *event)
{
    Xbefore = event->x();
    Ybefore = event->y();
}

void Settings::LoadSettings()
{
    QFile settingFile(PROJECT_PATH+"Local Data/App Settings/settings.txt");
    theme = Extraction::GetPropertyValueByID(settingFile,"1364798520",Property::THEME);
    showConsole = Extraction::GetPropertyValueByID(settingFile,"1364798520",Property::SHOW_CONSOLE);
    Pass = Extraction::GetPropertyValueByID(settingFile,"1364798520",Property::PASSWORD);
   //handle UI
   //handle show concole
   if(showConsole == "true")
   {
       ui->checkBox_setting_console->setChecked(true);
   }
       else
       {
           ui->checkBox_setting_console->setChecked(false);
       }

   //handle show theme
   ui->comboBox_setting_theme->setCurrentText(theme.replace(".css" , ""));

   //handle pass
   if(Pass == "")
   {
       ui->pushButton_settings_newPass->setEnabled(true);
       ui->pushButton_settings_changePass->setEnabled(false);
   }
   else
   {
       ui->pushButton_settings_newPass->setEnabled(false);
       ui->pushButton_settings_changePass->setEnabled(true);
   }

    console->ShowMessage("settings loaded",MessageColor::Green);





}

void Settings::GetThemes()
{
    QDirIterator di(PROJECT_PATH+"Local Data/App Settings/Theme/",QStringList() << "*.css" , QDir::Files);
    while(di.hasNext())
    {
        di.next();
        ui->comboBox_setting_theme->addItem(di.fileName().replace(".css" , ""));
    }

}

void Settings::on_pushButton_settings_newPass_clicked()
{
    ui->frame_settings_changePass->setVisible(false);
    ui->frame_settings_newPass->setVisible(true);
    newPass = true;
    changPass = false;
}

void Settings::on_pushButton_settings_changePass_clicked()
{
    ui->frame_settings_changePass->setVisible(true);
    ui->frame_settings_newPass->setVisible(false);
    newPass = false;
    changPass = true;
}


void Settings::on_pushButton_settings_savechange_clicked()
{
    ui->pushButton_settings_savechange->setDisabled(true);
    bool doreturn = false;


    QFile settingFile(PROJECT_PATH+"Local Data/App Settings/settings.txt");
    if(newPass)
    {
        if(ui->lineEdit_setting_new_newPass->text()== ui->lineEdit_setting_new_repeatPass->text())
        {
            QString tempHash = Security::getHashPassWord(ui->lineEdit_setting_new_newPass->text());
            Insertion::EditPropertyByID("1364798520",Property::PASSWORD,tempHash,settingFile,ReturnType::FullText);
            console->ShowMessage("New Password Saved",MessageColor::Green);
        }
        else
        {
            console->ShowMessage("Confirm Your Password Correctly",MessageColor::Red);
            ui->pushButton_settings_savechange->setDisabled(false);
            doreturn = true;
        }

    }
    else if(changPass)
    {
        if(Security::getHashPassWord(ui->lineEdit_setting_change_oldPass->text()) == Pass)
        {
            if(ui->lineEdit_setting_change_newPass->text() == ui->lineEdit_setting_change_repeatPass->text())
            {
                QString newTemp = Security::getHashPassWord(ui->lineEdit_setting_change_newPass->text());
                Insertion::EditPropertyByID("1364798520" , Property::PASSWORD,newTemp,settingFile,ReturnType::FullText);
                console->ShowMessage("Password Changed" , MessageColor::Green);
            }
            else
            {
                console->ShowMessage("Confirm Your Password Correctly",MessageColor::Red);
                ui->pushButton_settings_savechange->setDisabled(false);
                doreturn = true;
            }
        }
        else
        {
            ui->pushButton_settings_savechange->setEnabled(true);
            console->ShowMessage("Wrong Old Password",MessageColor::Red);
            doreturn = true;
        }
    }

    Insertion::EditPropertyByID("1364798520" , Property::THEME,ui->comboBox_setting_theme->currentText() + ".css" , settingFile,ReturnType::FullText);
    if(ui->checkBox_setting_console->isChecked())
    {
        Insertion::EditPropertyByID("1364798520" , Property::SHOW_CONSOLE,"true", settingFile,ReturnType::FullText);
    }
    else
    {
        Insertion::EditPropertyByID("1364798520" , Property::SHOW_CONSOLE,"false", settingFile,ReturnType::FullText);
    }


     console->ShowMessage("Changes Saved",MessageColor::Green);
    if(doreturn)
    {
        return;
    }

    if(isThemeChanged)
    {
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

    }

    on_pushButton_Close_clicked();
}

void Settings::on_comboBox_setting_theme_currentIndexChanged(int index)
{
    if(index == currentThemeIndex)
    {
        isThemeChanged = false;
    }
    else
    {
        isThemeChanged = true;
    }
}
