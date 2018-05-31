#ifndef LAND_H
#define LAND_H

#include <QMainWindow>
#include "continentwindow.h"
#include "continent.h"
#include <QVector>

namespace Ui {
class Land;
}

class Land : public QMainWindow
{
    Q_OBJECT

public:
    explicit Land(QWidget *parent = 0);
    ~Land();

private slots:
    void exit();
    void addContinent();

private:
    Ui::Land *ui;
    QVector<Continent> continents;

    //Dialog Windows
    ContinentWindow continentWindow;

};

#endif // LAND_H
