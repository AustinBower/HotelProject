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

void Employee::fillComboBox() //This function was supposed to fill the comboBox by reading the names in from the
                              //file just like the textEdit, but does not work properly.
{
    QFile file("//home//harold//employeeschedules//contact.txt");
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QString name = line.section(',',0,0);
        ui->comboBox->addItem(name);
    }


}

void Employee::fillLineEdits() //Basically the same as the function above but for the lineEdits
{
    QFile file("//home//harold//employeeschedules//contact.txt");
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QString name = line.section(',',0,0);
        QString email = line.section(',',1,1);
        QString hphone = line.section(',',2,2);
        QString cphone = line.section(',',3,3);
        ui->lineEdit->setText(name);
        ui->lineEdit->setText(email);
        ui->lineEdit->setText(hphone);
        ui->lineEdit->setText(cphone);
    }
}
