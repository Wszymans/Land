#ifndef PLANT_H
#define PLANT_H

#include <QString>



class Plant {

    enum Diet {
    carnivorous,
    parasite,
    photosynthesis
    };

public:
    Plant();
    Plant(QString species, bool edibility, Diet diet);
    Plant(QString species);
    Plant(const Plant &plant);

private:
        QString species;
        bool edibility;
        Diet diet;
};

#endif // PLANT_H
