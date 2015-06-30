#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H
#include<QWidget>
#include<QGridLayout>
#include<QGroupBox>
#include<QDialog>
#include<QRadioButton>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QScrollArea>

#include"utente.h"
#include"laureawindow.h"
#include"lavorowindow.h"

class ResultWindow : public QWidget{
    Q_OBJECT
public:
    ResultWindow(Utente*, QWidget* = 0);
    ~ResultWindow();
    Utente* user;
    QGridLayout* resultLayout;
    QLabel* usernameRicercaLabel;
    QLabel* nameRicercaLabel;
    QLabel* surnameRicercaLabel;
    QLabel* usernameRicerca;
    QLabel* nameRicerca;
    QLabel* surnameRicerca;
    QPushButton* showProfileButton;

    //DIALOG SHOWPROFILE
    QDialog* showProfileDialog;
    QGridLayout* showProfileLayout;
    QGridLayout* topLayout;
    QGroupBox* infoBox;
    QGroupBox* schoolBox;
    QGridLayout* infoLayout;
    QGridLayout* schoolLayout;
    QGridLayout* workLayout;
    QScrollArea* scrollArea;
    QWidget* widget;

    QLabel  * usernameLabel,
            * nomeLabel,
            * cognomeLabel,
            * emailLabel,
            * dataLabel,
            * luogoLabel,
            * residenzaLabel,
            * diplomaLabel,
            * titoloLavori;

    QLineEdit   * username,
                * nome,
                * cognome,
                * email,
                * dataNascita,
                * luogoNascita,
                * residenza,
                * diploma;


public slots:
    void showProfile();
};

#endif // RESULTWINDOW_H
