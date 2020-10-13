#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include "CoreEngine/corefunctions.h"


namespace Ui {
class AboutUs;
}

class AboutUs : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutUs(QWidget *parent = 0);
    ~AboutUs();
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void LoadTheme()
    {
        this->setStyleSheet(Extraction::GetCurrentThemeStyleSheet());
    }

private slots:
    void on_pushButton_Close_clicked();

private:
    Ui::AboutUs *ui;
    int Xbefore;
    int Ybefore;
};

#endif // ABOUTUS_H
