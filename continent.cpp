#include "continent.h"

Continent::Continent(QString name, double area) {

    this->name = name;
    this->area = area;

}

Continent::Continent(const Continent &continent) {

    name = continent.name;
    area = continent.area;

}

QString Continent::getName() const {
    return name;
}

double Continent::getArea() const {
    return area;
}
