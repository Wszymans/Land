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


    connect(ui->showButton, SIGNAL(clicked()), this, SLOT(SshowWindow()));

    //Reciving Data:
    connect(&continentWindow, SIGNAL(sendContinent(Continent)), this, SLOT(reciveContinent(Continent)));

}


void Land::reciveContinent(Continent continent) {
    continents.push_back(continent);
}


void Land::SaddContinent() {
    continentWindow.exec();
}

void Land::SshowWindow() {

    QVBoxLayout *continentLayout = new QVBoxLayout;
    QLabel *continentTitle = new QLabel("Kontynenty:");
    continentTitle->setStyleSheet("margin-bottom: 50");

    continentLayout->addWidget(continentTitle);

    for(Continent continent : continents) {
        QLabel *continentName = new QLabel(continent.getName());
        QLabel *continentArea = new QLabel(QString::number(continent.getArea()));
        continentName->setStyleSheet("font-weight: 500");
        continentArea->setStyleSheet("margin-bottom: 25");

        continentLayout->addWidget(continentName);
        continentLayout->addWidget(continentArea);

    }

    QVBoxLayout *marineLayout = new QVBoxLayout;


    QVBoxLayout *layout = new QVBoxLayout;

    layout->addLayout(continentLayout);
    layout->addLayout(marineLayout);

    showWindow.setLayout(layout);
    showWindow.exec();



//    QVBoxLayout *layout = new QVBoxLayout;
//    QPushButton *btn = new QPushButton();
//    layout->addWidget(btn);
//    showWindow.setLayout(layout);
//    showWindow.exec();
}

void Land::Sexit() {
    qApp->quit();
}



Land::~Land()
{
    delete ui;
}
