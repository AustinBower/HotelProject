#include "statsdialog.h"
#include "ui_statsdialog.h"
#include <nightcharts.h>

StatsDialog::StatsDialog(int statWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatsDialog)
{
    ui->setupUi(this);
    setStatWindow(statWindow);
    setStatWindowTitles();
}

StatsDialog::~StatsDialog()
{
    delete ui;
}

void StatsDialog::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter;
    QFont font;
    painter.begin(this);
    Nightcharts Histogram;
    Histogram.setType(Nightcharts::Histogramm);
    Histogram.setLegendType(Nightcharts::Vertical);
    if (statWindow == 1)
    {
        Histogram.setCords(20, 20, this->width()/1.7,this->height()/1.2);
        Histogram.addPiece("February", QColor(200,10,50), 45);
        Histogram.addPiece("March", Qt::green, 67);
        Histogram.addPiece("April", Qt::cyan, 85);
        Histogram.addPiece("May", Qt::yellow, 8);
        Histogram.draw(&painter);
        Histogram.drawLegend(&painter);
    }
    else if (statWindow == 2)
    {
        Histogram.setCords(20, 20, this->width()/1.7,this->height()/1.2);
        Histogram.addPiece("February", QColor(200,10,50), 45);
        Histogram.addPiece("March", Qt::green, 65);
        Histogram.addPiece("April", Qt::cyan, 87);
        Histogram.addPiece("May", Qt::yellow, 6);
        Histogram.draw(&painter);
        Histogram.drawLegend(&painter);
    }
    else if (statWindow == 3)
    {
        Histogram.setCords(20, 20, this->width()/1.9,this->height()/1.2);
        Histogram.addPiece("Last Week", QColor(200,10,50), 42);
        Histogram.addPiece("This Week", Qt::green, 29);
        Histogram.draw(&painter);
        Histogram.drawLegend(&painter);
    }
    else if (statWindow == 4)
    {
        Histogram.setCords(20, 20, this->width()/1.9,this->height()/1.2);
        Histogram.addPiece("Refrigerator", QColor(200,10,50), 34);
        Histogram.addPiece("Microwave", Qt::green, 27);
        Histogram.addPiece("Ironing Board", Qt::cyan, 38);
        Histogram.addPiece("Mini-Bar", Qt::yellow, 14);
        Histogram.draw(&painter);
        Histogram.drawLegend(&painter);
    }

}
void StatsDialog::setStatWindowTitles()
{
    if (this->statWindow == 1)
    {
        this->setWindowTitle("Check Ins");
    }
    else if (this->statWindow == 2)
    {
        this->setWindowTitle("Check Outs");
    }
    else if (this->statWindow == 3)
    {
        this->setWindowTitle("Reservations");
    }
    else if (this->statWindow == 4)
    {
        this->setWindowTitle("Room Accomodations");
    }
}
void StatsDialog::setStatWindow(int statWindow)
{
    this->statWindow = statWindow;
}
