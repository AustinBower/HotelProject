#include "checkinsdialog.h"
#include "ui_checkinsdialog.h"
#include <nightcharts.h>

CheckInsDialog::CheckInsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckInsDialog)
{
    ui->setupUi(this);
}

CheckInsDialog::~CheckInsDialog()
{
    delete ui;
}

void CheckInsDialog::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter;
    QFont font;
    painter.begin(this);
    Nightcharts Histogram;
    Histogram.setType(Nightcharts::Histogramm);//{Histogramm,Pie,DPie};
    Histogram.setLegendType(Nightcharts::);//{Round,Vertical}
    Histogram.setCords(20, 20, this->width()/1.7,this->height()/1.2);
    Histogram.addPiece("February",QColor(200,10,50), 34);
    Histogram.addPiece("March",Qt::green, 27);
    Histogram.addPiece("April",Qt::cyan, 14);
    Histogram.addPiece("May",Qt::yellow, 7);
    Histogram.addPiece("June",Qt::blue, 4);
    Histogram.draw(&painter);
    Histogram.drawLegend(&painter);

}

