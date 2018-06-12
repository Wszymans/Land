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

    ///EDITCONTINENT BUTTON
    connect(ui->EditContinentButton, SIGNAL(clicked()), this, SLOT(SContinentEditWindow()));

    //Receiving Data:
    connect(&continentEditWindow, SIGNAL(sendCountry(Country)), this, SLOT(reciveCountry(Country)));
    connect(&continentWindow, SIGNAL(sendContinent(Continent)), this, SLOT(receiveContinent(Continent)));
    connect(&marineWindow, SIGNAL(sendMarine(Marine)), this, SLOT(receiveMarine(Marine)));
    connect(&continentEditWindow, SIGNAL(returnContinents(QVector<Continent>)), this, SLOT(reciveContinents(QVector<Continent>)));
}

void Land::reciveCountry(Country country) {
  continents[0].addCountry(country);
}

void Land::reciveContinents(QVector<Continent> myContinents) {
    continents = myContinents;
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

void Land::SContinentEditWindow() {


    if(continents.length() == 0) {
        QMessageBox msgBox;
        msgBox.setText("Nie dodano jeszcze, żadnego kontynentu");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
        return;
    }


    continentEditWindow.receiveContinents(this->continents);

    continentEditWindow.exec();
    

}

void Land::SshowWindow() {

    showWindow = new QDialog();

    showWindow->setFixedSize(400, 600);

    QVBoxLayout *continentLayout = new QVBoxLayout;
    QLabel *continentTitle = new QLabel("Kontynenty:");
    continentTitle->setStyleSheet("margin-bottom: 30");
    continentLayout->addWidget(continentTitle);


    for(Continent continent : continents) {

        QLabel *continentName = new QLabel(continent.getName());
        QLabel *continentArea = new QLabel(QString::number(continent.getArea()));
        QLabel *continentImage = new QLabel();
        if (continent.getImage().isNull()) {
            QPixmap pix = QPixmap(Continent::defaultImagePath);
            continentImage->setPixmap(pix);
        } else {
            continentImage->setPixmap(continent.getImage().scaled(200,150,Qt::KeepAspectRatio));
        }

        continentArea->setStyleSheet("margin-bottom: 15");
        continentLayout->addWidget(continentName);
        continentLayout->addWidget(continentArea);
        continentLayout->addWidget(continentImage);

        for(Country country : continent.getCountries()) {

            QLabel *countryName = new QLabel(country.getName());
            continentLayout->addWidget(countryName);
        }

        continentArea->setStyleSheet("margin-bottom: 25");


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
