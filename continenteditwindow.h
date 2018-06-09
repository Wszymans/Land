#ifndef CONTINENTEDITWINDOW_H
#define CONTINENTEDITWINDOW_H

#include <QDialog>
#include <QVector>
#include "continent.h"
#include "addcountrywindow.h"

namespace Ui {
class ContinentEditWindow;
}

class ContinentEditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ContinentEditWindow(QWidget *parent = 0);
    ~ContinentEditWindow();
    void receiveContinents(QVector<Continent> receiveContinents);

public slots:
    void SreceiveCountry(Country country);

private slots:
    void SchangedComboBox(int index);
    void SaddCountryWindow();

private:
    Ui::ContinentEditWindow *ui;
    QVector<Continent> continents;
    void editValues(int index);

    AddCountryWindow addCountryWindow;

};

#endif // CONTINENTEDITWINDOW_H
