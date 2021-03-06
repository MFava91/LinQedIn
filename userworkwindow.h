#ifndef USERWORKWINDOW_H
#define USERWORKWINDOW_H
#include<QRadioButton>
#include<QPushButton>
#include<QGridLayout>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>
#include<QDialog>
#include<QScrollArea>

#include"usercontroller.h"
#include"lavorowindow.h"

class UserWorkWindow : public QWidget{
    Q_OBJECT
public:
    UserWorkWindow();
    UserWorkWindow(QWidget *parent, userController*);
    QGridLayout* workLayout;
    QGridLayout* lavoriLayout;
    QPushButton* addButtonLavoro;
    QLabel* titolo;
    QLabel* noLavori;
    QScrollArea* scrollArea;
    QWidget* widget;
    QGridLayout* mainLayout;

    //DIALOG
    QDialog* boxAddLavoro;
    QGridLayout* addLavoroLayout;
    QGridLayout* buttonLayout;
    QLabel* addAziendaLabel;
    QLabel* addTitoloLabel;
    QLabel* addCittaLabel;
    QLabel* addInizioLabel;
    QLabel* addFineLabel;
    QLineEdit* addAzienda;
    QLineEdit* addTitolo;
    QLineEdit* addCitta;
    QDateEdit* addInizio;
    QDateEdit* addFine;
    QPushButton* addButtonNewLavoro;
    QPushButton* cancelButtonNewLavoro;

    userController* clientCtrl;
    ~UserWorkWindow();

public slots:
    void fetchLavoro();
    void dialogAddLavoro();
    void addLavoro();
    void removeLavoro(LavoroWindow*);
    void modificaLavoro(const Lavoro&, const Lavoro&);

};

#endif // USERWORKWINDOW_H
