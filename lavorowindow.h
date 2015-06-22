#ifndef LAVOROWINDOW_H
#define LAVOROWINDOW_H
#include<QPushButton>
#include<QGridLayout>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QDateTimeEdit>


class LavoroWindow: public QWidget{
    Q_OBJECT
public:
    LavoroWindow(const QString&, const QString&, const QString&, const QDate&, const QDate&, QWidget *parent = 0);
    QGridLayout* lavoroLayout;
    QLabel* aziendaLabel;
    QLabel* titoloLabel;
    QLabel* cittaLabel;
    QLabel* inizioLabel;
    QLabel* fineLabel;

    QLineEdit* azienda;
    QLineEdit* titolo;
    QLineEdit* citta;
    QDateTimeEdit* inizio;
    QDateTimeEdit* fine;

    QPushButton* modifyButtonLavoro;
    QPushButton* cancelButtonLavoro;
    QPushButton* updateButtonLavoro;
    QPushButton* deleteButtonLavoro;
signals:
    void signalDeleteLavoro(LavoroWindow*);
public slots:
    void enableEditLavoro();
    void disableEditLavoro();
    void deleteLavoro();
};

#endif // LAVOROWINDOW_H
