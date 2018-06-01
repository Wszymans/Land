#include "country.h"

unsigned int Country::NumberOfCountries = 0;

Country::Country(QString name, double area, Administration administration) {

        this->name = name;
        this->area = area;
        this->administration = administration;
        this->Country_id = Country::NumberOfCountries;
        Country::NumberOfCountries++;

}



bool Country::operator> (const Country & country) {
     return country.area>this->area;
}

QString Country::getName() {
    return name;
  }

Country& Country::operator+=(const Country& country) {
   this->area += country.area;
   return *this;
}
