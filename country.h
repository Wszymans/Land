#ifndef COUNTRY_H
#define COUNTRY_H

#include <QString>

using namespace std;

enum Administration {
  democracy,
  republic
};

class Country {

      friend class continent;
      static unsigned int NumberOfCountries;

      QString name;
      double area;
      Administration administration;
      unsigned int Country_id;

public:
    Country(QString name, double area, Administration administration);

    void showCountry();   

    bool operator> (const Country & Country);

    Country& operator+=(const Country& Country);
    QString getName();


};

#endif // COUNTRY_H
