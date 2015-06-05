#ifndef USERWINDOW_H
#define USERWINDOW_H
#include<QWidget>
#include<QRadioButton>
#include<QPushButton>
#include<QGridLayout>

class UserWindow : public QWidget{
    Q_OBJECT
public:
    QRadioButton* prova;
    QPushButton* test;
    UserWindow(QWidget *parent = 0);
    ~UserWindow();
    QGridLayout* out;
};
#endif // USERWINDOW_H
