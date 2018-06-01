#ifndef MARINE_H
#define MARINE_H

#include <QString>
#include <QVector>
#include "territory.h"

struct Reef
{
    enum ReefType {
       biotic,
       geologic
    };

    ReefType type = biotic;
    double area = 10;

//    Reef(double area = 10, ReefType type = biotic) : area(area), type(biotic) {
//    }

};

class Marine : public Territory {

public:
    Marine(QString name = "Default", double area = 200);
    Marine(const Marine &Marine);

    QString getName() const;
    double getArea() const;

private:
    QVector<Reef> reefs;
    double area;
    QString name;
};

#endif // MARINE_H
