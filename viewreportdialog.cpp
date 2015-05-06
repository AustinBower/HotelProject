#include "viewreportdialog.h"
#include "ui_viewreportdialog.h"
#include <QStandardItemModel>

ViewReportDialog::ViewReportDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::ViewReportDialog)
{
    ui->setupUi(this);
    setWindowTitle("Reservation Report");
    setUpReservationReport();
}

ViewReportDialog::~ViewReportDialog()
{
    delete ui;
}

void ViewReportDialog::setUpReservationReport()
{
    QStandardItemModel *model = new QStandardItemModel(2,3,this); //2 Rows and 3 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Date")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Room Number")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Check In Date")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Check Out Date")));

    QStandardItem *item = new QStandardItem(QString("Doe, John"));
    model->setItem(0, 0, item);
    item = new QStandardItem(QString("5/1/15"));
    model->setItem(0, 1, item);
    item = new QStandardItem(QString("42"));
    model->setItem(0, 2, item);
    item = new QStandardItem(QString("5/5/15"));
    model->setItem(0, 3, item);
    item = new QStandardItem(QString("5/6/15"));
    model->setItem(0, 4, item);

    ui->tableView->setModel(model);

}
