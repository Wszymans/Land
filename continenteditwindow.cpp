#include "continenteditwindow.h"
#include "ui_continenteditwindow.h"

ContinentEditWindow::ContinentEditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinentEditWindow)
{
    ui->setupUi(this);

    connect(ui->ContinentcombBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SChangedComboBox(int)));
}

void ContinentEditWindow::reciveContinents(QVector<Continent> recivedContinents) {
    continents.clear();
    ui->ContinentcombBox->clear();
    continents = recivedContinents;
    for(Continent continent : continents) {
        ui->ContinentcombBox->addItem(continent.getName());
    }

    int index = ui->ContinentcombBox->currentIndex();

    editValues(index);


}

void ContinentEditWindow::SChangedComboBox(int index) {
    editValues(index);
}

ContinentEditWindow::~ContinentEditWindow()
{
    delete ui;
    continents.clear();
    ui->ContinentcombBox->clear();
}


//Helper functions:

void ContinentEditWindow::editValues(int index) {
    Continent continent = continents[index];

    ui->NewContinentName->setText(continent.getName());
    ui->NewContinentArea->setText(QString::number(continent.getArea()));
}
