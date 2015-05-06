#include "reports.h"
#include "ui_reports.h"
#include "statsdialog.h"
#include "viewreportdialog.h"
#include <QPushButton>

Reports::Reports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reports)
{

    ui->setupUi(this);
    setItemValues();
    addItemsToList();

}

Reports::~Reports()
{
    delete ui;
}
/*
 * Creates a list of useful information that can be seen immediately by the user.
*/
void Reports::addItemsToList()
{
    ui->reportsListWidget->addItem("Number of Reservations Today: "
                                   + QString::number(getReservationsToday()));
    ui->reportsListWidget->addItem("Number of Reservations This Month: "
                                   + QString::number(getReservationsMonth()));
    ui->reportsListWidget->addItem("Capacity Now: "
                                   + QString::number(getCapacityNow()));
    ui->reportsListWidget->addItem("Yearly Capacity: "
                                   + QString::number(getYearlyCapacity()));
    ui->reportsListWidget->addItem("Total Amount of Reservations: "
                                   + QString::number(getReservationsYear()));
}
/*
 * Initialzes all of the the list values
 * */
void Reports::setItemValues()
{
    setReservationsToday(5);
    setReservationsMonth(0);
    setReservationsYear(0);
    setCapacityNow(0);
    setYearlyCapacity(0);
    setRoomsOccupied(0);
    setRoomsAvailable(0);
}

/*
 * When the "Check Ins" button is clicked, show its corresponding dialog.
 * */
void Reports::on_st_CheckInsButton_clicked()
{
    ci_dialog = new StatsDialog(1, this);
    ci_dialog->show();
}

/*
 * When the "Check Outs" button is clicked, show its corresponding dialog.
 * */
void Reports::on_st_checkOutButton_clicked()
{
    co_dialog = new StatsDialog(2, this);
    co_dialog->show();
}

/*
 * When the "Reservations" button is clicked, show its corresponding dialog.
 * */
void Reports::on_st_reservationButton_clicked()
{
    re_dialog = new StatsDialog(3, this);
    re_dialog->show();
}

/*
 * When the "Room Accomodations" button is clicked, show its corresponding dialog.
 * */
void Reports::on_st_roomAccom_clicked()
{
    ro_dialog = new StatsDialog(4, this);
    ro_dialog->show();
}

void Reports::on_re_ResReport_clicked()
{
    resrep = new ViewReportDialog();
    resrep->show();
}

/*
 * Accessor and mutator methods
 * */
void Reports::setReservationsToday(int num) { reservationsToday = num; }
void Reports::setReservationsMonth(int num) { reservationsMonth = num; }
void Reports::setReservationsYear(int num) { reservationsYear = num; }
void Reports::setCapacityNow(int num) { capacityNow = num; }
void Reports::setYearlyCapacity(int num) { yearlyCapacity = num; }
void Reports::setRoomsOccupied(int num) { roomsOccupied = num; }
void Reports::setRoomsAvailable(int num) { roomsAvailable = num; }
int Reports::getReservationsToday() { return reservationsToday; }
int Reports::getReservationsMonth() { return reservationsMonth; }
int Reports::getReservationsYear() { return reservationsYear; }
int Reports::getCapacityNow() { return capacityNow; }
int Reports::getYearlyCapacity() { return yearlyCapacity; }
int Reports::getRoomsOccupied() { return roomsOccupied; }
int Reports::getRoomsAvailable() { return roomsAvailable; }
