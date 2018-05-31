#include "country.h"

unsigned int country::NumberOfCountries = 0;

country::country(QString name, double area, Administration administration) {

        this->name = name;
        this->area = area;
        this->administration = administration;
        this->country_id = country::NumberOfCountries;
        country::NumberOfCountries++;

}



bool country::operator> (const country & country) {
     return country.area>this->area;
}

QString country::getName() {
    return name;
  }

country& country::operator+=(const country& country) {
   this->area += country.area;
   return *this;
}
