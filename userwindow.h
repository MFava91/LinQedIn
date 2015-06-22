#ifndef USERWINDOW_H
#define USERWINDOW_H
#include<QWidget>
#include<QRadioButton>
#include<QPushButton>
#include<QGridLayout>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>

#include"usercontroller.h"
#include"userinfowindow.h"
#include"userschoolwindow.h"
#include"userworkwindow.h"

class UserWindow : public QWidget{
    Q_OBJECT
private:
    userController* clientCtrl;
public:
    UserWindow(QWidget *parent, userController*);
    ~UserWindow();
    QGridLayout* mainLayout;
    QGridLayout* menuLayout;
    QGridLayout* selectLayout;

    QWidget* userInfo;
    QWidget* userSchool;
    QWidget* userWork;

    QPushButton* info;
    QPushButton* school;
    QPushButton* work;


public slots:
    void loadUserInfo();
    void loadUserSchool();
    void loadUserWork();
};
#endif // USERWINDOW_H
