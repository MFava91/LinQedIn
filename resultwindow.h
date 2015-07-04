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
#include<typeinfo>

#include"utente.h"
#include"laureawindow.h"
#include"lavorowindow.h"
#include"controller.h"

class ResultWindow : public QWidget{
    Q_OBJECT
public:
    ResultWindow(Utente*, Controller*, QWidget* = 0);
    ~ResultWindow();
    Utente* user;
    Controller* ctrl;
    QGridLayout* resultLayout;
    QLabel* usernameRicercaLabel;
    QLabel* nameRicercaLabel;
    QLabel* surnameRicercaLabel;
    QLabel* usernameRicerca;
    QLabel* nameRicerca;
    QLabel* surnameRicerca;
    QPushButton* showProfileButton;
    QPushButton* addReteButton;
    QPushButton* removeReteButton;

    //DIALOG SHOWPROFILE
    QDialog* showProfileDialog;
    QGridLayout* showProfileLayout;
    QGridLayout* topLayout;
    QGridLayout* usernameLayout;
    QGridLayout* profileLayout;
    QGridLayout* diplomaLayout;
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

signals:
    void signalFetchResult();

public slots:
    void showProfile();
    void addRete();
    void removeRete();
};

#endif // RESULTWINDOW_H
