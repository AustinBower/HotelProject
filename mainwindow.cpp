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
    allRooms.push_back(roomOne);
    storeRoom(roomOne,in);
    Room roomTwo;
    allRooms.push_back(roomTwo);
    storeRoom(roomTwo,in);
    Room roomThree;
    allRooms.push_back(roomThree);
    storeRoom(roomThree,in);
    Room roomFour;
    allRooms.push_back(roomFour);
    storeRoom(roomFour,in);
    Room roomFive;
    allRooms.push_back(roomFive);
    storeRoom(roomFive,in);
    Room roomSix;
    allRooms.push_back(roomSix);
    storeRoom(roomSix,in);


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
    alterRoomForm *newForm = new alterRoomForm;
    newForm->show();
}
