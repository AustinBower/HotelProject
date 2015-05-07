#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "room.h"
#include "employee.h"
#include <QTextStream>
#include <vector>

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
    std::vector <Room> allRooms;

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_actionAlter_Room_Info_triggered();

    void on_actionReports_triggered();

    void on_actionContact_Information_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Employee *employee;
};

#endif // MAINWINDOW_H
