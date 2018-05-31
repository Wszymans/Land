#include "continentwindow.h"
#include "ui_continentwindow.h"

ContinentWindow::ContinentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinentWindow)
{
    ui->setupUi(this);
}

ContinentWindow::~ContinentWindow()
{
    delete ui;
}
