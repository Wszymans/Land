#ifndef CONTINENT_H
#define CONTINENT_H

#include <QString>

class Continent
{
public:
    Continent(QString name = "Default", double area = 100);
    Continent(const Continent &continent);

    QString getName() const;
    double getArea() const;

private:
    double area;
    QString name;
};




#endif // CONTINENT_H
