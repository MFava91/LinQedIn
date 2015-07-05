#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H
#include<QPushButton>
#include<QGridLayout>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>
#include<typeinfo>

#include"usercontroller.h"

class UserInfoWindow : public QWidget{
    Q_OBJECT
public:
    UserInfoWindow(QWidget *parent, userController*);
    QGroupBox* accountBox;
    QGroupBox* datiBox;
    QGridLayout* profiloLayout;
    QGridLayout* datiLayout;
    QGridLayout* accountLayout;
    QGridLayout* buttonLayout;
    QLineEdit* username;
    QLineEdit* tipo;
    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* email;
    QDateTimeEdit* dataNascita;
    QLineEdit* luogoNascita;
    QLineEdit* residenza;

    QLabel* usernameLabel;
    QLabel* tipoLabel;
    QLabel* nomeLabel;
    QLabel* cognomeLabel;
    QLabel* emailLabel;
    QLabel* dataLabel;
    QLabel* luogoLabel;
    QLabel* residenzaLabel;

    QPushButton* modifyButton;
    QPushButton* updateButton;
    QPushButton* deleteButton;

    userController* clientCtrl;
    ~UserInfoWindow();
signals:
    void signalSave();
public slots:
    void fetchDati();
    void enableEdit();
    void disableEdit();
    void updateInfo();

};

#endif // USERINFOWINDOW_H
