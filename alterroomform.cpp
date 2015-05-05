#include "alterroomform.h"
#include "ui_alterroomform.h"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <vector>


alterRoomForm::alterRoomForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alterRoomForm)
{
    ui->setupUi(this);
    //if possible, open up the file which stores the room information (i.e. room numbers, styles, and costs)
    QString fileName = ":/storedInfo/RoomInfo.txt";
    QFile mFile(fileName);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        ui->errorLabel->setText("*FILE -ROOM INFO- NOT FOUND/OPERABLE ERROR*");
        return;
    }

    //open a text stream on the file, create an object for each room, and store info into the objects from the file
    QTextStream in(&mFile);
    Room roomOne;
    storeRoom(roomOne,in);
    rooms.push_back(roomOne);
    Room roomTwo;
    storeRoom(roomTwo,in);
    rooms.push_back(roomTwo);
    Room roomThree;
    storeRoom(roomThree,in);
    rooms.push_back(roomThree);
    Room roomFour;
    storeRoom(roomFour,in);
    rooms.push_back(roomFour);
    Room roomFive;
    storeRoom(roomFive,in);
    rooms.push_back(roomFive);
    Room roomSix;
    storeRoom(roomSix,in);
    rooms.push_back(roomSix);
    mFile.close();

    for (unsigned int i=0; i < rooms.size(); i++)
    {
        Room alterRoom = rooms.at(i);
        ui->roomNumsBox->addItem(alterRoom.getNum());
    }
}

alterRoomForm::~alterRoomForm()
{
    delete ui;
}

void alterRoomForm::storeRoom(Room& currentRoom, QTextStream& in)
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

void alterRoomForm::on_roomNumsBox_currentIndexChanged(int index)
{
    ui->errorLabel->clear();
    Room alterRoom;
    QString roomStuff;
    switch (index)
    {
    case 0:
        alterRoom = rooms.at(0);
        ui->numberDisplay->setText(alterRoom.getNum());
        roomStuff = QString::number(alterRoom.getCost());
        ui->costDisplay->setText(roomStuff);
        roomStuff = QString::number(alterRoom.getStyle());
        ui->styleDisplay->setText(roomStuff);
        break;
    case 1:
        alterRoom = rooms.at(1);
        ui->numberDisplay->setText(alterRoom.getNum());
        roomStuff = QString::number(alterRoom.getCost());
        ui->costDisplay->setText(roomStuff);
        roomStuff = QString::number(alterRoom.getStyle());
        ui->styleDisplay->setText(roomStuff);
        break;
    case 2:
        alterRoom = rooms.at(2);
        ui->numberDisplay->setText(alterRoom.getNum());
        roomStuff = QString::number(alterRoom.getCost());
        ui->costDisplay->setText(roomStuff);
        roomStuff = QString::number(alterRoom.getStyle());
        ui->styleDisplay->setText(roomStuff);
        break;
    case 3:
        alterRoom = rooms.at(3);
        ui->numberDisplay->setText(alterRoom.getNum());
        roomStuff = QString::number(alterRoom.getCost());
        ui->costDisplay->setText(roomStuff);
        roomStuff = QString::number(alterRoom.getStyle());
        ui->styleDisplay->setText(roomStuff);
        break;
    case 4:
        alterRoom = rooms.at(4);
        ui->numberDisplay->setText(alterRoom.getNum());
        roomStuff = QString::number(alterRoom.getCost());
        ui->costDisplay->setText(roomStuff);
        roomStuff = QString::number(alterRoom.getStyle());
        ui->styleDisplay->setText(roomStuff);
        break;
    case 5:
        alterRoom = rooms.at(5);
        ui->numberDisplay->setText(alterRoom.getNum());
        roomStuff = QString::number(alterRoom.getCost());
        ui->costDisplay->setText(roomStuff);
        roomStuff = QString::number(alterRoom.getStyle());
        ui->styleDisplay->setText(roomStuff);
        break;
    default:
        alterRoom = rooms.at(0);
        ui->numberDisplay->setText(alterRoom.getNum());
        roomStuff = QString::number(alterRoom.getCost());
        ui->costDisplay->setText(roomStuff);
        roomStuff = QString::number(alterRoom.getStyle());
        ui->styleDisplay->setText(roomStuff);
        break;

    }
}

void alterRoomForm::on_okButton_clicked()
{
    if (ui->newNumberLine->hasAcceptableInput())
    {
        if (ui->newNumberLine->text().size() == 3)
        {
            if (ui->newStyleLine->hasAcceptableInput())
            {
                if (ui->newStyleLine->text().size() == 1)
                {
                    if (ui->newCostLine->hasAcceptableInput())
                    {
                        if (ui->newCostLine->text().size() == 5)
                        {
                            Room replacer;
                            QString roomStuff;
                            replacer.setNum(ui->newNumberLine->text());
                            replacer.setStyle(ui->newStyleLine->text().toInt());
                            replacer.setCost(ui->newCostLine->text().toFloat());
                            rooms.at(ui->roomNumsBox->currentIndex()) = replacer;
                            ui->roomNumsBox->setItemText(ui->roomNumsBox->currentIndex(), replacer.getNum());
                            ui->numberDisplay->setText(replacer.getNum());
                            roomStuff = QString::number(replacer.getCost());
                            ui->costDisplay->setText(roomStuff);
                            roomStuff = QString::number(replacer.getStyle());
                            ui->styleDisplay->setText(roomStuff);
                            ui->errorLabel->setText("Currently selected room information successfully changed!");
                        }
                        else
                        {
                            ui->errorLabel->setText("NEW COST INSUFFICIENTLY FILLED");
                        }
                    }
                    else
                    {
                        ui->errorLabel->setText("UNACCEPTABLE NEW COST");
                    }
                }
                else
                {
                    ui->errorLabel->setText("NEW STYLE INSUFFICIENTLY FILLED");
                }
            }
            else
            {
                ui->errorLabel->setText("UNACCEPTABLE NEW STYLE");
            }
        }
        else
        {
            ui->errorLabel->setText("NEW NUMBER INSUFFICIENTLY FILLED");
        }
    }
    else
    {
        ui->errorLabel->setText("UNACCEPTABLE NEW NUMBER");
    }
}
