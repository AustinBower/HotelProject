#ifndef ROOM_H
#define ROOM_H
#include "QString"


class Room
{
public:
    Room();
    Room(QString,int,float);
    ~Room();
    QString getNum();
    int getStyle();
    float getCost();
    void setNum(QString);
    void setStyle(int);
    void setCost(float);
    QString outputString();
private:
    QString roomNum;
    int roomStyle;
    float roomCost;
};

#endif // ROOM_H
