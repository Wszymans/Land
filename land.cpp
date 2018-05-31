#include "land.h"
#include "ui_land.h"

Land::Land(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Land)
{
    ui->setupUi(this);

    //Connecting Buttons:

    ///EXIT BUTTON
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exit()));

    ///ADDCONTINENT BUTTON
    connect(ui->addContinentButton, SIGNAL(clicked()), this, SLOT(addContinent()));
}


void Land::exit() {
    qApp->quit();
}

void Land::addContinent() {
    continentWindow.exec();
}

Land::~Land()
{
    delete ui;
}
