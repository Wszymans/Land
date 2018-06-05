#include "continenteditwindow.h"
#include "ui_continenteditwindow.h"

ContinentEditWindow::ContinentEditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinentEditWindow)
{
    ui->setupUi(this);
}

void ContinentEditWindow::reciveContinents(QVector<Continent> recivedContinents) {
    continents.clear();
    ui->ContinentcombBox->clear();
    continents = recivedContinents;
    for(Continent continent : continents) {
        ui->ContinentcombBox->addItem(continent.getName());
    }

    QString test = ui->ContinentcombBox->currentText();

    ui->NewContinentName->setText(test);

}

ContinentEditWindow::~ContinentEditWindow()
{
    delete ui;
    continents.clear();
    ui->ContinentcombBox->clear();
}
