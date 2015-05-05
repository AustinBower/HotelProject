#ifndef ALTERROOMFORM_H
#define ALTERROOMFORM_H

#include <QDialog>
#include "room.h"
#include <QTextStream>
#include <vector>

namespace Ui {
class alterRoomForm;
}

class alterRoomForm : public QDialog
{
    Q_OBJECT

public:
    explicit alterRoomForm(QWidget *parent = 0);
    ~alterRoomForm();
    void storeRoom(Room&,QTextStream&);
    std::vector <Room> rooms;
private slots:
    void on_comboBox_activated(int index);

    void on_roomNumsBox_currentIndexChanged(int index);

    void on_okButton_clicked();

private:
    Ui::alterRoomForm *ui;
};

#endif // ALTERROOMFORM_H
