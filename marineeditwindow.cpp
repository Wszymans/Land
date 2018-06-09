#include "marineeditwindow.h"
#include "ui_marineeditwindow.h"

MarineEditWindow::MarineEditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarineEditWindow)
{
    ui->setupUi(this);
}

MarineEditWindow::~MarineEditWindow()
{
    delete ui;
}
