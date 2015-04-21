#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textDisplay->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QString dateSelected = date.toString();
    ui->displayLabel->setText(dateSelected);
    ui->textDisplay->setPlainText("STUFF FOR:\n");
    ui->textDisplay->append(dateSelected);
}
