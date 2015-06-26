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
#include"resultwindow.h"

class AdminWindow : public QWidget{
    Q_OBJECT
private:
    AdminController* adminCtrl;
public:
    AdminWindow(QWidget *, AdminController*);
    ~AdminWindow();
    Utente* utenteTrovato;
    QGridLayout* mainLayout;
    QGridLayout* editLayout;
    QGridLayout* findLayout;
    QGridLayout* findForUsernameLayout;
    QGridLayout* findForNameLayout;
    QGridLayout* resultLayout;
    QGroupBox* editBox;
    QGroupBox* findBox;
    QGroupBox* findForUsernameBox;
    QGroupBox* findForNameBox;
    QGroupBox* resultBox;

    QPushButton* newUserButton;
    QPushButton* deleteUserButton;
    QPushButton* modifyUserButton;
    QPushButton* findUsernameButton;
    QPushButton* findNameButton;

    //RICERCA
    QLabel* findUsernameLabel;
    QLabel* findNameLabel;
    QLabel* findSurnameLabel;
    QLineEdit* findUsername;
    QLineEdit* findName;
    QLineEdit* findSurname;

    //RISULTATI
    QLabel* nessunaRicerca;
    QLabel* nessunUtenteTrovato;


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
    void searchUsername();
    void updateWindow();
    void searchName();
};


#endif // ADMINWINDOW_H
