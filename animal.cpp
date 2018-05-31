#include "animal.h"


Animal::Animal() {

    species = "brak informacji";
    voice = "brak dzwieku";
    diet = omnivorous;

}

Animal::Animal(QString species) {

    this->species = species;
    voice = "brak dzwieku";
    diet = omnivorous;
}

Animal::Animal(QString species, QString voice, Diet diet) {

this->species = species;
this->voice = voice;
this->diet = diet;

}

Animal::Animal(const Animal &animal) {

species = animal.species;
voice = animal.voice;
diet = animal.diet;

}

