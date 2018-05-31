#ifndef COUNTRY_H
#define COUNTRY_H

#include <QString>

using namespace std;

enum Administration {
  democracy,
  republic
};

class country {

      friend class continent;
      static unsigned int NumberOfCountries;

      QString name;
      double area;
      Administration administration;
      unsigned int Country_id;

public:
    country(QString name, double area, Administration administration);

    void showCountry();

    friend std::ostream & operator<< (std::ostream &back, const country &country);

    bool operator> (const country & country);

    country& operator+=(const country& country);
    QString getName();


};

#endif // COUNTRY_H
