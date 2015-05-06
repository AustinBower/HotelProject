#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>

namespace Ui {
class Employee;
}

class Employee : public QDialog
{
    Q_OBJECT

public:
    explicit Employee(QWidget *parent = 0);
    void fillComboBox();
    void fillLineEdits();
    ~Employee();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Employee *ui;
};

#endif // EMPLOYEE_H
