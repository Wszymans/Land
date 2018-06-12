#ifndef CONTINENTEDITWINDOW_H
#define CONTINENTEDITWINDOW_H

#include <QDialog>
#include <QVector>
#include "continent.h"
#include "addcountrywindow.h"
#include <QPixmap>
#include <QDirIterator>
#include <QMap>
#include <QMessageBox>

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

signals:
    void returnContinents(QVector<Continent> myContinents);
    void sendCountry(Country country);
public slots:
    void SreceiveCountry(Country country);

private slots:
    void SchangedComboBox(int index);
    void SaddCountryWindow();
    void SsendContinents();
    void SchangeImage(int index);

private:
    Ui::ContinentEditWindow *ui;
    QVector<Continent> continents;
    void editValues(int index);

    AddCountryWindow addCountryWindow;
    int currentIndex;

    QMap<int, QString> imageMap;

};

#endif // CONTINENTEDITWINDOW_H
