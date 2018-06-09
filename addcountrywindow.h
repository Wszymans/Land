#ifndef ADDCOUNTRYWINDOW_H
#define ADDCOUNTRYWINDOW_H

#include <QDialog>
#include "country.h"

namespace Ui {
class AddCountryWindow;
}

class AddCountryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddCountryWindow(QWidget *parent = 0);
    ~AddCountryWindow();

signals:
    void sendCountry(Country country);

private slots:
    void addCountry();

private:
    Ui::AddCountryWindow *ui;
};

#endif // ADDCOUNTRYWINDOW_H
