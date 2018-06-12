#include "continenteditwindow.h"
#include "ui_continenteditwindow.h"
ContinentEditWindow::ContinentEditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinentEditWindow)
{
    ui->setupUi(this);
    currentIndex = 0;
    QPixmap pix(":/resource/images/templateIcon.png");
    ui->ContinentImage->setPixmap(pix.scaled(200,150,Qt::KeepAspectRatio));

    QDirIterator it(":/resource/images", QDirIterator::Subdirectories);
    int fastIndex = 0;
    while(it.hasNext()) {
        it.next();
        imageMap.insert(fastIndex++, it.filePath());
        ui->continentImageComboBox->addItem(it.fileName());
    }

    connect(ui->continentImageComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SchangeImage(int)));
    connect(ui->ContinentCombBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SchangedComboBox(int)));
    connect(ui->AddNewCountryButton, SIGNAL(clicked()), this, SLOT(SaddCountryWindow()));
    connect(&addCountryWindow, SIGNAL(sendCountry(Country)), this, SLOT(SreceiveCountry(Country)));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(SsendContinents()));
}


void ContinentEditWindow::SchangeImage(int index) {
    QString imagePath = imageMap.value(index);
    QPixmap pix(imagePath);
    ui->ContinentImage->setPixmap(pix.scaled(200,150,Qt::KeepAspectRatio));
    continents[currentIndex].setImage(pix);
}

ContinentEditWindow::~ContinentEditWindow()
{
    delete ui;
}

void ContinentEditWindow::SsendContinents() {

    continents[currentIndex].setName(ui->NewContinentName->text());
    continents[currentIndex].setArea((ui->NewContinentArea->text()).toDouble());

    emit returnContinents(continents);
    this->close();

}

void ContinentEditWindow::receiveContinents(QVector<Continent> receiveContinents) {

//continents.clear(); //za kazdym razem usuwam wszystko co bylo wczesniej w kontynentach

ui->ContinentCombBox->clear();

continents = receiveContinents;

for(Continent continent : continents) {

    ui->ContinentCombBox->addItem(continent.getName());

}

int currentIndex = ui->ContinentCombBox->currentIndex();
editValues(currentIndex);

}

void ContinentEditWindow::SreceiveCountry(Country country) {

    continents[currentIndex].addCountry(country);

    emit sendCountry(country);

}

void ContinentEditWindow::editValues(int index) {

    Continent continent = continents[index];

    ui->NewContinentName->setText(continent.getName());
    ui->NewContinentArea->setText(QString::number(continent.getArea()));

}

void ContinentEditWindow::SchangedComboBox(int index) {

    currentIndex = index;
    editValues(currentIndex);

}

void ContinentEditWindow::SaddCountryWindow() {
    addCountryWindow.exec();
}
