#include "marinewindow.h"
#include "ui_marinewindow.h"

    marinewindow::marinewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarineWindow) {

    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(SaddMarine()));

    }

    void MarineWindow::SaddMarine() {

    QString name = ui->marineName->text();
    double area = ui->marineArea->text().toDouble();

    Marine thisMarine = Marine(name, area);

    emit sendMarine(thisMarine);
}

    MarineWindow::~MarineWindow()
{
    delete ui;
}
