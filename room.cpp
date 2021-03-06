#include "room.h"

Room::Room()
{
    this->roomNum = "0";
    this->roomStyle = 0;
    this->roomCost = 0.0;
}

Room::Room(QString rNumber, int rStyle, float rCost)
{
    this->roomNum = rNumber;
    this->roomStyle = rStyle;
    this->roomCost = rCost;
}

Room::~Room()
{
}

QString Room::getNum()
{
    return this->roomNum;
}

int Room::getStyle()
{
    return this->roomStyle;
}

float Room::getCost()
{
    return this->roomCost;
}

void Room::setNum(QString newNum)
{
    this->roomNum = newNum;
}

void Room::setStyle(int newStyle)
{
    this->roomStyle = newStyle;
}

void Room::setCost(float newCost)
{
    this->roomCost = newCost;
}

QString Room::outputString()
{
    QString allInfo = "Number: ";
    allInfo.append(this->roomNum += ", ");
    allInfo.append("Style: ");
    allInfo.append(QString::number(this->roomStyle) += ", ");
    allInfo.append("Cost: ");
    allInfo.append(QString::number(this->roomCost));
    return allInfo;
}





















