#ifndef TERRITORY_H
#define TERRITORY_H

#include <QVector>
#include "animal.h"
#include "plant.h"

class Territory {

public:
    virtual void addAnimal(Animal animal);
    virtual void addPlant(Plant plant);

protected:
    QString name;
    double area;
    QVector<Animal> animals;
    QVector<Plant> plants;
};

#endif // TERRITORY_H
