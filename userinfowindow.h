#ifndef USERINFOWINDOW_H
#define USERINFOWINDOW_H
#include<QPushButton>
#include<QGridLayout>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>

#include"usercontroller.h"

class UserInfoWindow : public QWidget{
    Q_OBJECT
public:
    UserInfoWindow();
    UserInfoWindow(QWidget *parent, userController*);
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
