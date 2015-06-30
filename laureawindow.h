#ifndef LAUREAWINDOW_H
#define LAUREAWINDOW_H
#include<QRadioButton>
#include<QPushButton>
#include<QGridLayout>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>

class LaureaWindow : public QWidget{
    Q_OBJECT
public:
    LaureaWindow(const QString&, QWidget *parent = 0);
    ~LaureaWindow();
    QString temp;
    QGridLayout* laureaLayout;
    QGridLayout* buttonsLayout;
    QLabel* laureaLabel;
    QLineEdit* laurea;

    QPushButton* modifyButtonLaurea;
    QPushButton* cancelButtonLaurea;
    QPushButton* updateButtonLaurea;
    QPushButton* deleteButtonLaurea;
signals:
    void signalDeleteLaurea(LaureaWindow*);
    void signalUpdateLaurea(const QString&, const QString&);
public slots:
    void displayButton();
    void enableEditLaurea();
    void disableEditLaurea();
    void deleteLaurea();
    void modifyLaurea();
};

#endif // LAUREAWINDOW_H
