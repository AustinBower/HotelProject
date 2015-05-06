#include "employee.h"
#include "mainwindow.h"
#include "ui_employee.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

Employee::Employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Employee)
{
    ui->setupUi(this);
    fillComboBox();
}

Employee::~Employee()
{
    delete ui;
}

void Employee::on_pushButton_clicked()
{
    close();
}

void Employee::fillComboBox()
{
    QFile file("//home//harold//employeeschedules//contact.txt");
    QTextStream in(&file);
    //QStringList nameList;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QString name = line.section(',',0,0);
        ui->comboBox->addItem(name);

    }


}

void Employee::fillLineEdits()
{
    QFile file("//home//harold//employeeschedules//contact.txt");
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QString name = line.section(',',0,0);
        ui->lineEdit->setText(name);
    }
}
