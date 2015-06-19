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

class UserWindow : public QWidget{
    Q_OBJECT
public:
    UserWindow(QWidget *parent, userController*);
    ~UserWindow();
    QGridLayout* datiLayout;
    QLineEdit* username;
    QLabel* nome;
    QLineEdit* cognome;
    QLineEdit* email;
//    QDateTimeEdit* dataNascita;
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
#endif // USERWINDOW_H
