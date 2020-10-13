#ifndef LOCK_H
#define LOCK_H

#include <QMainWindow>
#include "CoreEngine/corefunctions.h"

namespace Ui {
class Lock;
}

class Lock : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lock(QWidget *parent = 0);
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }
    ~Lock();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Lock *ui;
};

#endif // LOCK_H
