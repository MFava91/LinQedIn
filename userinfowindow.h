#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H
#include<QRadioButton>
#include<QPushButton>
#include<QGridLayout>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>

#include"usercontroller.h"

class UserInfoWindow : public QWidget{
public:
    UserInfoWindow();
    UserInfoWindow(QWidget *parent, userController*);
    ~UserInfoWindow();
    QGridLayout* datiLayout;
    QLineEdit* username;
    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* email;
    QDateTimeEdit* dataNascita;
    QLineEdit* luogoNascita;
    QLineEdit* residenza;

    QLabel* usernameLabel;
    QLabel* nomeLabel;
    QLabel* cognomeLabel;
    QLabel* emailLabel;
    QLabel* dataLabel;
    QLabel* luogoLabel;
    QLabel* residenzaLabel;
};

#endif // USERINFOWINDOW_H
