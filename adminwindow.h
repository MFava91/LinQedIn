#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include<QWidget>
#include<QRadioButton>
#include <QPushButton>
#include <QGridLayout>

class AdminWindow : public QWidget{
    Q_OBJECT
public:
    QRadioButton* prova;
    QPushButton* test;
    AdminWindow(QWidget *parent = 0);
    ~AdminWindow();
    QGridLayout* out;
};


#endif // ADMINWINDOW_H
