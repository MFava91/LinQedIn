#ifndef LAVOROWINDOW_H
#define LAVOROWINDOW_H
#include<QPushButton>
#include<QGridLayout>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateEdit>

#include"lavoro.h"


class LavoroWindow: public QWidget{
    Q_OBJECT
public:
    LavoroWindow(const QString&, const QString&, const QString&, const QDate&, const QDate&, QWidget *parent = 0);
    ~LavoroWindow();
    Lavoro temp;
    QGridLayout* lavoroLayout;
    QGridLayout* buttonsLayout;
    QLabel* aziendaLabel;
    QLabel* titoloLabel;
    QLabel* cittaLabel;
    QLabel* inizioLabel;
    QLabel* fineLabel;

    QLineEdit* azienda;
    QLineEdit* titolo;
    QLineEdit* citta;
    QDateEdit* inizio;
    QDateEdit* fine;

    QPushButton* modifyButtonLavoro;
    QPushButton* cancelButtonLavoro;
    QPushButton* updateButtonLavoro;
    QPushButton* deleteButtonLavoro;
signals:
    void signalDeleteLavoro(LavoroWindow*);
    void signalUpdateLavoro(const Lavoro&, const Lavoro&);

public slots:
    void displayButton();
    void enableEditLavoro();
    void disableEditLavoro();
    void deleteLavoro();
    void updateLavoro();
};

#endif // LAVOROWINDOW_H
