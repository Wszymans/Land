#ifndef TERRITORY_H
#define TERRITORY_H

#include <QVector>
#include "animal.h"

class Territory {

public:
    virtual void addAnimal(Animal animal) = 0;

protected:
    QString name;
    double area;
    QVector<Animal> animals;
};

#endif // TERRITORY_H
