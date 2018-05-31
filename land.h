#ifndef LAND_H
#define LAND_H

#include <QMainWindow>
#include "continentwindow.h"
#include "marinewindow.h"
#include "continent.h"
#include "marine.h"
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
    void receiveMarine(Marine marine);

private slots:
    void Sexit();
    void SaddContinent();
    void SshowWindow();
    void SaddMarine();

private:
    Ui::Land *ui;
    QVector<Continent> continents;
    QVector<Marine> marines;

    //Dialog Windows
    ContinentWindow continentWindow;
    MarineWindow marineWindow;
    QDialog showWindow;


};

#endif // LAND_H
