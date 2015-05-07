#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room.h"
#include "alterroomform.h"
#include "reports.h"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //set up the ui, change the text display to read only, and maximize the screen by default
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    this->showMaximized();

    //if possible, open up the file which stores the room information (i.e. room numbers, styles, and costs)
    QString fileName = ":/storedInfo/RoomInfo.txt";
    QFile mFile(fileName);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        ui->textEdit->insertPlainText("*FILE -ROOM INFO- NOT FOUND/OPERABLE ERROR*");
        return;
    }

    //open a text stream on the file, create an object for each room, and store info into the objects from the file
    QTextStream in(&mFile);
    Room roomOne;
    storeRoom(roomOne,in);
    allRooms.push_back(roomOne);
    Room roomTwo;
    storeRoom(roomTwo,in);
    allRooms.push_back(roomTwo);
    Room roomThree;
    storeRoom(roomThree,in);
    allRooms.push_back(roomThree);
    Room roomFour;
    storeRoom(roomFour,in);
    allRooms.push_back(roomFour);
    Room roomFive;
    storeRoom(roomFive,in);
    allRooms.push_back(roomFive);
    Room roomSix;
    storeRoom(roomSix,in);
    allRooms.push_back(roomSix);

    mFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->label->setText(date.toString()); //This sets the date from the calendar into a string
    QFile file(":/storedInfo/schedules.txt");
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


void MainWindow::storeRoom(Room& currentRoom, QTextStream& in)
{
    /* a nearly identical function is also used in loginscreen and alterroomform.
     * read in information and break it by its comma delimitation and then store the data into room objects
     */
    QString line = in.readLine();
    QStringList list = line.split(",");
    for (int i = 0; i < list.size(); i++)
    {
        QString value = list.at(i);
        if (i == 0)
        {
            QString roomNumber = value;
            currentRoom.setNum(roomNumber);
        }
        else if (i == 1)
        {
            int roomStyle = value.toInt();
            currentRoom.setStyle(roomStyle);
        }
        else
        {
            float roomCost = value.toFloat();
            currentRoom.setCost(roomCost);
        }
    }
}

void MainWindow::on_actionAlter_Room_Info_triggered()
{
    //when the user selects the form, create the form and display it
    alterRoomForm *newForm = new alterRoomForm;
    newForm->show();
}

void MainWindow::on_actionReports_triggered()
{
    Reports *reportDialog = new Reports();
    reportDialog->show();
}
