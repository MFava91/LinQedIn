#ifndef USERRETEWINDOW_H
#define USERRETEWINDOW_H
#include"usercontroller.h"
#include<QWidget>
#include<QPushButton>
#include<QGridLayout>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>
#include<typeinfo>

#include"resultwindow.h"

class UserReteWindow: public QWidget{
    Q_OBJECT
public:
    UserReteWindow();
    UserReteWindow(QWidget *parent, userController*);
    QGroupBox* reteBox;
    QGridLayout* reteLayout;
    QGridLayout* connectLayout;
    ~UserReteWindow();
};

#endif // USERRETEWINDOW_H
