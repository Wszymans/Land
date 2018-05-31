#include "plant.h"

plant::plant() {

    species = "brak informacji";
    edibility = true;
    diet = photosynthesis;
}

plant::plant(QString species) {

this->species = species;
edibility = true;
diet = photosynthesis;

}

plant::plant(QString species, bool edibility, Diet diet) {

this->species = species;
this->edibility = edibility;
this->diet = diet;

}

plant::plant(const plant &plant) {

species = plant.species;
edibility = plant.edibility;
diet = plant.diet;

}
