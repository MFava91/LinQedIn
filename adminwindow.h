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
#include<QMessageBox>

#include"admincontroller.h"
#include"searchwindow.h"

class AdminWindow : public QWidget{
    Q_OBJECT
private:
    AdminController* adminCtrl;
public:
    AdminWindow(QWidget *, AdminController*);
    ~AdminWindow();
    SearchWindow* ricerca;
    Utente* utenteTrovato;
    QGridLayout* mainLayout;
    QGridLayout* editLayout;
    QGroupBox* editBox;

    QPushButton* newUserButton;
    QPushButton* deleteUserButton;
    QPushButton* modifyUserButton;




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
    QGridLayout* modifyLayout;
    QGroupBox* boxType;
    QGridLayout* typeLayout;
    QLabel* modifyUsernameLabel;
    QLineEdit* modifyUsername;
    QLabel* modifyInfo;
    QRadioButton* basic;
    QRadioButton* business;
    QRadioButton* executive;
    QPushButton* confirmUserButton;
    QPushButton* confirmModifyUserButton;
    QPushButton* cancelModifyUserButton;

public slots:
    void dialogAddNewUser();
    void addNewUser();
    void dialogEraseUser();
    void deleteUser();
    void dialogModifyUser();
    void searchModifyUser();
    void updateAccountType();
};


#endif // ADMINWINDOW_H
