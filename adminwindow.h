#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include<QWidget>
#include<QGridLayout>
#include<QGroupBox>
#include<QDialog>
#include<QRadioButton>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QToolTip>
#include<QPoint>
#include"admincontroller.h"

class AdminWindow : public QWidget{
    Q_OBJECT
private:
    AdminController* adminCtrl;
public:
    AdminWindow(QWidget *, AdminController*);
    ~AdminWindow();
    QGridLayout* mainLayout;
    QGridLayout* editLayout;
    QGridLayout* findLayout;
    QGroupBox* editBox;
    QPoint* p;

    QPushButton* newUserButton;
    QPushButton* deleteUserButton;
    QPushButton* modifyUserButton;

    QPushButton* findUserButton;

    //DIALOG CREATE USER
    QDialog* boxNewUser;
    QGridLayout* newUserLayout;
    QLabel* usernameNewUserLabel;
    QLabel* nameNewUserLabel;
    QLabel* surnameNewUserLabel;

    QLineEdit* usernameNewUser;
    QLineEdit* nameNewUser;
    QLineEdit* surnameNewUser;

    QPushButton* addNewUserButton;
    QPushButton* cancelNewUserButton;

    //DIALOG DELETE USER
    QDialog* boxEraseUser;
    QGridLayout* eraseUserLayout;
    QLabel* eraseUserLabel;
    QLineEdit* eraseUser;

    QPushButton* eraseUserButton;
    QPushButton* cancelEraseUserButton;

    //DIALOG MODIFY USER
    QDialog* boxModifyUser;

public slots:
    void dialogAddNewUser();
    void addNewUser();
    void dialogEraseUser();
    void deleteUser();
};


#endif // ADMINWINDOW_H
