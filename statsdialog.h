#ifndef STATSDIALOG_H
#define STATSDIALOG_H

#include <QDialog>

namespace Ui {
class StatsDialog;
}

class StatsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatsDialog(int statWindow, QWidget *parent = 0);
    void setStatWindow(int statWindow);
    void setStatWindowTitles();
    ~StatsDialog();

private:
    Ui::StatsDialog *ui;
    int statWindow;
    void paintEvent(QPaintEvent *e);
};

#endif // STATSDIALOG_H
