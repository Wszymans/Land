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
    void receiveContinent(Continent continent);

private slots:
    void Sexit();
    void SaddContinent();
    void SshowWindow();

private:
    Ui::Land *ui;
    QVector<Continent> continents;

    //Dialog Windows
    ContinentWindow continentWindow;
    QDialog showWindow;


};

#endif // LAND_H
