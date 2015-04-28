#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "room.h"
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void storeRoom(Room&,QTextStream&);

private slots:
    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
