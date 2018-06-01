#ifndef CONTINENT_H
#define CONTINENT_H

#include <QString>
#include "territory.h"
#include "country.h"

class Continent : public Territory
{
public:
    Continent(QString name = "Default", double area = 100);
    Continent(const Continent &continent);

    QString getName() const;
    double getArea() const;

private:
    QVector<Country> countries;
    double area;
    QString name;
};




#endif // CONTINENT_H
