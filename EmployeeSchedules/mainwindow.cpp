#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "employee.h"

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
    ui->label->setText(date.toString()); //This sets the date from the calendar into a string
    QFile file("//home//harold//employeeschedules//schedules.txt");
    if (file.open(QIODevice::ReadOnly)) // Open the file as read-only
    {
        ui->textEdit->clear();
        QTextStream in(&file);
        ui->textEdit->setAlignment(Qt::AlignCenter); //Align the text to the center of the textEdit box
        //The lines below just format the text into the proper format by a line-by-line basis
        ui->textEdit->setFontPointSize(20);
        ui->textEdit->setFontUnderline(true);
        ui->textEdit->append("Selected Date");
        ui->textEdit->setFontPointSize(12);
        ui->textEdit->setFontUnderline(false);
        ui->textEdit->setFontPointSize(20);
        ui->textEdit->append((ui->calendarWidget->selectedDate().toString()) + "\n");
        ui->textEdit->setFontPointSize(12);
        while (!in.atEnd())
        {
            QString line = in.readLine(); //Reads the file line-by-line
            QString date = line.section(',',0,0); //Splits the CSV file into the appropriate strings for use below
            QString name = line.section(',',1,1);
            QString schedule = line.section(',',2,2);

            if ((ui->calendarWidget->selectedDate().toString("MMddyyyy")) == date) //Compares the selected date to the date in the file
            {
                //Basically more formatting stuff below here
                ui->textEdit->setFontUnderline(true);
                ui->textEdit->append("Employee Name");
                ui->textEdit->setFontUnderline(false);
                ui->textEdit->setFontWeight(QFont::Bold);
                ui->textEdit->append(name);
                ui->textEdit->setFontWeight(QFont::Normal);
                ui->textEdit->setFontUnderline(true);
                ui->textEdit->append("Scheduled Hours");
                ui->textEdit->setFontUnderline(false);
                ui->textEdit->setFontWeight(QFont::Bold);
                ui->textEdit->append(schedule + "\n");
                ui->textEdit->setFontWeight(QFont::Normal);
            }
        }

        file.close();
    }
}

void MainWindow::on_actionContact_Information_triggered() //This is activated when the drop-down menu option "Contact Information" is clicked
{
    Employee employee(this);
    employee.fillComboBox();
    //employee.setModal(true);
    employee.exec();
    //employee = new Employee(this);
    //employee->fillComboBox();
    //employee->show();
}

void MainWindow::on_pushButton_clicked()
{
    close();
}
