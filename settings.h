#ifndef SETTINGS_H
#define SETTINGS_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QDirIterator>
#include <QFile>

#include "CoreEngine/corefunctions.h"
#include "sharcatconsole.h"


namespace Ui {
class Settings;
}

class Settings : public QMainWindow
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void LoadSettings();
    void GetThemes();
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }
    ~Settings();

private slots:
    void on_pushButton_Close_clicked();

    void on_pushButton_settings_newPass_clicked();

    void on_pushButton_settings_changePass_clicked();

    void on_pushButton_settings_savechange_clicked();

    void on_comboBox_setting_theme_currentIndexChanged(int index);

private:
    Ui::Settings *ui;
    SharCatConsole *console;
    int Xbefore;
    int Ybefore;
    bool newPass;
    bool changPass;
    //temp setting
    QString Pass;
    QString showConsole;
    QString theme;

    bool isThemeChanged;
    int currentThemeIndex;
};

#endif // SETTINGS_H
