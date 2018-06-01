#include "plant.h"

Plant::Plant() {

    species = "brak informacji";
    edibility = true;
    diet = photosynthesis;
}

Plant::Plant(QString species) {

this->species = species;
edibility = true;
diet = photosynthesis;

}

Plant::Plant(QString species, bool edibility, Diet diet) {

this->species = species;
this->edibility = edibility;
this->diet = diet;

}

Plant::Plant(const Plant &plant) {

species = plant.species;
edibility = plant.edibility;
diet = plant.diet;

}
