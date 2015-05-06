#ifndef REPORTS_H
#define REPORTS_H

#include <QDialog>
#include <QGroupBox>
#include "statsdialog.h"
#include "viewreportdialog.h"

namespace Ui {
class Reports;
}

class Reports : public QDialog
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = 0);
    ~Reports();

    void setItemValues();
    void addItemsToList();
    void setReservationsToday(int num);
    void setReservationsMonth(int num);
    void setReservationsYear(int num);
    void setCapacityNow(int num);
    void setYearlyCapacity(int num);
    void setRoomsOccupied(int num);
    void setRoomsAvailable(int num);
    int getReservationsToday();
    int getReservationsMonth();
    int getReservationsYear();
    int getCapacityNow();
    int getYearlyCapacity();
    int getRoomsOccupied();
    int getRoomsAvailable();

private slots:
    void on_st_CheckInsButton_clicked();

    void on_st_checkOutButton_clicked();

    void on_st_roomAccom_clicked();

    void on_st_reservationButton_clicked();

    void on_re_ResReport_clicked();

private:
    Ui::Reports *ui;
    StatsDialog *ci_dialog;
    StatsDialog *co_dialog;
    StatsDialog *re_dialog;
    StatsDialog *ro_dialog;
    ViewReportDialog *resrep;
    int reservationsToday;
    int reservationsMonth;
    int reservationsYear;
    int capacityNow;
    int yearlyCapacity;
    int roomsOccupied;
    int roomsAvailable;
};

#endif // REPORTS_H
