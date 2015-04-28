#ifndef ROOM_H
#define ROOM_H
#include "QString"


class Room
{
public:
    Room();
    Room(int,int,float);
    ~Room();
    int getNum();
    int getStyle();
    float getCost();
    void setNum(int);
    void setStyle(int);
    void setCost(float);
    QString outputString();
private:
    int roomNum;
    int roomStyle;
    float roomCost;
};

#endif // ROOM_H
