#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->label->setText(date.toString());
    QFile file("//home//harold//employeeschedules//schedules.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        ui->textEdit->clear();
        QTextStream in(&file);
        ui->textEdit->setAlignment(Qt::AlignCenter);
        ui->textEdit->append("Selected Date: ");
        ui->textEdit->append(ui->calendarWidget->selectedDate().toString());
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QString date = line.section(',',0,0);
            QString name = line.section(',',1,1);
            QString schedule = line.section(',',2,2);

            if ((ui->calendarWidget->selectedDate().toString("MMddyyyy")) == date)
            {

                ui->textEdit->append("Employee Name: ");
                ui->textEdit->append(name);
                ui->textEdit->append("Scheduled Hours: ");
                ui->textEdit->append(schedule);
            }
        }

        file.close();
    }
}
