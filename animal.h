#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>

enum Diet {

    carnivorous,
    herbivorous,
    omnivorous

};

class Animal
{
public:
    Animal();
    Animal(QString species);
    Animal(QString species, QString voice, Diet diet);
    Animal(const Animal &animal);
private:
    QString species;
    QString voice;
    Diet diet;
};

#endif // ANIMAL_H