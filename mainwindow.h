#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"adminwindow.h"
#include<QMainWindow>
#include<QStatusBar>
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>

#include"db.h"

class MainWindow: public QMainWindow {
    Q_OBJECT

private:
    QStatusBar *statusBar;
    QWidget *centralWidget;

    QGridLayout* layout;
    QPushButton *userSubmit;
    QPushButton *adminSubmit;
    QLineEdit *userUsername;
    QLineEdit *userPassword;
    QLineEdit *adminUsername;
    QLineEdit *adminPassword;
    DB* dataBase;
    static QString adminPass;
    static QString adminUser;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signalPassword(const QString&,const QString&);

public slots:
    void readCredentialAdmin();
    void loginAdmin(const QString&,const QString&);
};



#endif // MAINWINDOW_H
