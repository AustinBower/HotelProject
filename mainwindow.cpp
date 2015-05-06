#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room.h"
#include "alterroomform.h"
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
    ui->textDisplay->setReadOnly(true);
    this->showMaximized();

    //if possible, open up the file which stores the room information (i.e. room numbers, styles, and costs)
    QString fileName = ":/storedInfo/RoomInfo.txt";
    QFile mFile(fileName);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        ui->textDisplay->insertPlainText("*FILE -ROOM INFO- NOT FOUND/OPERABLE ERROR*");
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
    QString dateSelected = date.toString();
    ui->displayLabel->setText(dateSelected);
    ui->textDisplay->setPlainText("STUFF FOR:\n");
    ui->textDisplay->append(dateSelected);
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
