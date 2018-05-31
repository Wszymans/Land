#include "continentwindow.h"
#include "ui_continentwindow.h"

ContinentWindow::ContinentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinentWindow)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(SaddContinent()));


}


void ContinentWindow::SaddContinent() {

    QString name = ui->continentName->text();
    double area = ui->continentArea->text().toDouble();

    Continent thisContinent = Continent(name, area);

    emit sendContinent(thisContinent);

}



ContinentWindow::~ContinentWindow()
{
    delete ui;
}
