#include "continenteditwindow.h"
#include "ui_continenteditwindow.h"

ContinentEditWindow::ContinentEditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinentEditWindow)
{
    ui->setupUi(this);

    connect(ui->ContinentCombBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SchangedComboBox(int)));
    connect(ui->AddNewCountryButton, SIGNAL(clicked()), this, SLOT(SaddCountryWindow()));
    connect(&AddCountryWindow, SIGNAL(sendCountry(Country)), this, SLOT(SreceiveCountry(Country)));
}

ContinentEditWindow::~ContinentEditWindow()
{
    delete ui;
}

void ContinentEditWindow::receiveContinents(QVector<Continent> receiveContinents) {

//continents.clear(); //za kazdym razem usuwam wszystko co bylo wczesniej w kontynentach

ui->ContinentCombBox->clear();

continents = receiveContinents;

for(Continent continent : continents) {

    ui->ContinentCombBox->addItem(continent.getName());

}

int index = ui->ContinentCombBox->currentIndex();

editValues(index);

}

void ContinentEditWindow::SreceiveCountry(Country country) {


}

void ContinentEditWindow::editValues(int index) {

    Continent continent = continents[index];

    ui->NewContinentName->setText(continent.getName());
    ui->NewContinentArea->setText(QString::number(continent.getArea()));

}

void ContinentEditWindow::SchangedComboBox(int index) {

    editValues(index);

}

void ContinentEditWindow::SaddCountryWindow() {

    addCountryWindow.exec();

}
