#ifndef PLANT_H
#define PLANT_H

#include <QString>

enum Diet {
carnivorous,
parasite,
photosynthesis
};

class plant {

public:
    plant();
    plant(QString species, bool edibility, Diet diet);
    plant(QString species);
    plant(const plant &plant);

private:
        QString species;
        bool edibility;
        Diet diet;
};

#endif // PLANT_H
