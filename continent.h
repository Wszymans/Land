#ifndef CONTINENT_H
#define CONTINENT_H

#include <QString>
#include <QVector>
#include <QPixmap>
#include "territory.h"
#include "country.h"

class Continent : public Territory
{
public:
    Continent(QString name = "Default", double area = 100);
    Continent(const Continent &continent);

    QString getName() const;
    double getArea() const;
    QVector<Country> getCountries() const;
    QPixmap getImage() const;
    void addCountry(Country country);
    void setImage(QPixmap image);
    void setName(QString name);
    void setArea(double area);

    static QString defaultImagePath;
    QVector<Country> countries;
private:

    double area;
    QString name;
    QPixmap image;
};




#endif // CONTINENT_H
