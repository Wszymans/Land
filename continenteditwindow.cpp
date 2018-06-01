#include "continenteditwindow.h"
#include "ui_continenteditwindow.h"

ContinentEditWindow::ContinentEditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContinentEditWindow)
{
    ui->setupUi(this);
}

ContinentEditWindow::~ContinentEditWindow()
{
    delete ui;
}
