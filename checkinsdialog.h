#ifndef CHECKINSDIALOG_H
#define CHECKINSDIALOG_H

#include <QDialog>

namespace Ui {
class CheckInsDialog;
}

class CheckInsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckInsDialog(QWidget *parent = 0);
    ~CheckInsDialog();

private:
    Ui::CheckInsDialog *ui;
    void paintEvent(QPaintEvent *e);
};

#endif // CHECKINSDIALOG_H
