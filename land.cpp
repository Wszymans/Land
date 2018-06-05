#include "land.h"
#include "ui_land.h"

Land::Land(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Land)
{
    ui->setupUi(this);

    //Connecting Buttons:

    ///EXIT BUTTON
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(Sexit()));

    ///ADDCONTINENT BUTTON
    connect(ui->addContinentButton, SIGNAL(clicked()), this, SLOT(SaddContinent()));

    ///ADDMARINE BUTTON
    connect(ui->addMarineButton, SIGNAL(clicked()), this, SLOT(SaddMarine()));

    ///SHOWTERRITORIES BUTTON
    connect(ui->showButton, SIGNAL(clicked()), this, SLOT(SshowWindow()));

    ///EDITCONTINENT BUTTOn
    connect(ui->editContinentButton, SIGNAL(clicked()), this, SLOT(SeditContinent()));

    //Receiving Data:
    connect(&continentWindow, SIGNAL(sendContinent(Continent)), this, SLOT(receiveContinent(Continent)));
    connect(&marineWindow, SIGNAL(sendMarine(Marine)), this, SLOT(receiveMarine(Marine)));

}

void Land::receiveContinent(Continent continent) {

    continents.push_back(continent);
}

void Land::receiveMarine(Marine marine) {

    marines.push_back(marine);

}

void Land::Sexit() {
    qApp->quit();
}

void Land::SaddContinent() {
    continentWindow.exec();
}

void Land::SaddMarine() {
    marineWindow.exec();
}


void Land::SeditContinent() {
    continentEditWindow.reciveContinents(this->continents);
    continentEditWindow.exec();
}

void Land::SshowWindow() {

    showWindow = new QDialog();

    QVBoxLayout *continentLayout = new QVBoxLayout;
    QLabel *continentTitle = new QLabel("Kontynenty:");
    continentTitle->setStyleSheet("margin-bottom: 30");
    continentLayout->addWidget(continentTitle);

    for(Continent continent : continents) {

        QLabel *continentName = new QLabel(continent.getName());
        QLabel *continentArea = new QLabel(QString::number(continent.getArea()));
        continentArea->setStyleSheet("margin-bottom: 25");

        continentLayout->addWidget(continentName);
        continentLayout->addWidget(continentArea);

    }

    QVBoxLayout *marineLayout = new QVBoxLayout;
    QLabel *marineTitle = new QLabel("Akweny:");
    marineTitle->setStyleSheet("margin-bottom: 30");
    marineLayout->addWidget(marineTitle);

    for(Marine marine : marines) {

        QLabel *marineName = new QLabel(marine.getName());
        QLabel *marineArea = new QLabel(QString::number(marine.getArea()));
        marineArea->setStyleSheet("margin-bottom: 25");

        marineLayout->addWidget(marineName);
        marineLayout->addWidget(marineArea);

    }

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(continentLayout);
    layout->addLayout(marineLayout);

    showWindow->setLayout(layout);
    showWindow->exec();

}

Land::~Land()
{
    delete ui;
}
