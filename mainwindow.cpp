#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "room.h"
#include <QFile>
#include <QString>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textDisplay->setReadOnly(true);

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
    Room roomTwo;
    storeRoom(roomTwo,in);
    Room roomThree;
    storeRoom(roomThree,in);
    Room roomFour;
    storeRoom(roomFour,in);
    Room roomFive;
    storeRoom(roomFive,in);
    Room roomSix;
    storeRoom(roomSix,in);
    ui->textDisplay->setPlainText(roomOne.outputString());

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
            int roomNumber = value.toInt();
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















