#include "marine.h"

marine::marine(QString name, double area) {

    this->name = name;
    this->area = area;

}

marine::marine(const marine &marine) {

    name = marine.name;
    area = marine.area;
}

QString marine::getName() const {
    return name;
}

double marine::getArea() const {
    return area;
}
