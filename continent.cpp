#include "continent.h"

QString Continent::defaultImagePath = ":/resource/images/templateIcon.png";

void Continent::setImage(QPixmap image) {
    this->image = image;
}

QPixmap Continent::getImage() const {
    return image;
}

void Continent::setArea(double area) {
    this->area = area;
}

void Continent::setName(QString name) {
    this->name = name;
}

Continent::Continent(QString name, double area) {

    this->name = name;
    this->area = area;

    image = QPixmap(defaultImagePath);

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

void Continent::addCountry(Country country) {
    countries.push_back(country);
}

QVector<Country> Continent::getCountries() const {
    return countries;
}
