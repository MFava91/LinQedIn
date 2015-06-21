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
    QGridLayout* laureaLayout;
    QLabel* laureaLabel;
    QLineEdit* laurea;

    QPushButton* modifyButtonLaurea;
    QPushButton* cancelButtonLaurea;
    QPushButton* updateButtonLaurea;
    QPushButton* deleteButtonLaurea;
signals:
    void signalDeleteLaurea(LaureaWindow*);
public slots:
    void enableEditLaurea();
    void disableEditLaurea();
    void deleteLaurea();
};

#endif // LAUREAWINDOW_H
