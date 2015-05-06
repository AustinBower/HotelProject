#ifndef VIEWREPORTDIALOG_H
#define VIEWREPORTDIALOG_H

#include <QDialog>

namespace Ui {
class ViewReportDialog;
}

class ViewReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewReportDialog(QWidget *parent = 0);
    ~ViewReportDialog();

private:
    Ui::ViewReportDialog *ui;
    void setUpReservationReport();
};

#endif // VIEWREPORTDIALOG_H
