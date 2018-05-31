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

    ///SHOWCONTINENT BUTTON
    connect(ui->showButton, SIGNAL(clicked()), this, SLOT(SshowWindow()));

    //Receiving Data:
    connect(&continentWindow, SIGNAL(sendContinent(Continent)), this, SLOT(receiveContinent(Continent)));

}

void Land::receiveContinent(Continent continent) {

    continents.push_back(continent);
}

void Land::Sexit() {
    qApp->quit();
}

void Land::SaddContinent() {
    continentWindow.exec();
}

void Land::SshowWindow() {

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



    }

    //TODO: implement marine showing

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(continentLayout);
    layout->addLayout(marineLayout);

    showWindow.setLayout(layout);
    showWindow.exec();

}

Land::~Land()
{
    delete ui;
}
