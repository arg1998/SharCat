#ifndef BACKUP_H
#define BACKUP_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include "sharcatconsole.h"
#include "CoreEngine/corefunctions.h"



namespace Ui {
class BackUp;
}

class BackUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit BackUp(QWidget *parent = 0);
    ~BackUp();
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }

private slots:

    void on_pushButton_Close_clicked();
    void on_radioButton_Seperate_file_backup_toggled(bool checked);
    void on_pushButton_Select_path_clicked();
    void on_radioButton_all_file_restore_toggled(bool checked);
    void on_checkBox_Student_restore_toggled(bool checked);
    void on_checkBox_Teacher_restore_toggled(bool checked);
    void on_checkBox_staff_restore_toggled(bool checked);
    void on_pushButton_Select_path_restore_Student_clicked();
    void on_pushButton_Select_path_restore_Te_clicked();
    void on_pushButton_Select_path_restore_staff_clicked();
    void on_pushButton_Select_path_restore_All_clicked();
    void on_radioButton_Seperate_file_restore_toggled(bool checked);

    void on_pushButton_backup_clicked();

    void on_pushButton_restore_clicked();

private:
    Ui::BackUp *ui;
    int Xbefore;
    int Ybefore;
    SharCatConsole *console;
};

#endif // BACKUP_H
