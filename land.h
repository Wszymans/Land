#ifndef LAND_H
#define LAND_H

#include <QMainWindow>
#include "continentwindow.h"
#include "continent.h"
#include <QVector>
#include <QWidget>

namespace Ui {
class Land;
}

class Land : public QMainWindow
{
    Q_OBJECT

public:
    explicit Land(QWidget *parent = 0);
    ~Land();

public slots:
    void reciveContinent(Continent continent);

private slots:

    void SshowWindow();
    void Sexit();
    void SaddContinent();

private:
    Ui::Land *ui;
    QVector<Continent> continents;

    //Dialog Windows
    QDialog showWindow;
    ContinentWindow continentWindow;

};

#endif // LAND_H
