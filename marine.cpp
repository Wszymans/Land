#include "marine.h"

Marine::Marine(QString name, double area) {

    this->name = name;
    this->area = area;

}

Marine::Marine(const Marine &marine) {

    name = marine.name;
    area = marine.area;
}

QString Marine::getName() const {
    return name;
}

double Marine::getArea() const {
    return area;
}
