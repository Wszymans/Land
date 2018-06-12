#include "addcountrywindow.h"
#include "ui_addcountrywindow.h"

AddCountryWindow::AddCountryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCountryWindow)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(addCountry()));
}

AddCountryWindow::~AddCountryWindow()
{
    delete ui;
}

void AddCountryWindow::addCountry() {

    QString name = ui->CountryNameButton->text();
    double area = ui->CountryAreaButton->text().toDouble();
    Administration administration = democracy;

    if(ui->RepublicButton->isChecked()) {

        administration = republic;

    } else if (ui->DemocracyButton->isChecked()) {

        administration = democracy;

    } else {

        administration = democracy;
        //TODO: THROW ERROR

    }

    Country myCountry = Country(name, area, administration);

    emit sendCountry(myCountry);

}
