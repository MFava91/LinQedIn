#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGroupBox>
#include<QTextEdit>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include"adminwindow.h"

/*
namespace Ui {
class MainWindow;
}
*/

/*
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
public:
    explicit MainWindow(QWidget *parent = 0);
    main_widget mw;
    ~MainWindow();
};
*/

class MainWindow : public QWidget{
    Q_OBJECT
public:
    MainWindow(QWidget *parent =0);
public slots:
    void change_stack();
};


#endif // MAINWINDOW_H
