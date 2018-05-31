#ifndef MARINE_H
#define MARINE_H

#include <QString>

class marine {

public:
    marine(QString name = "Default", double area = 200);
    marine(const marine &marine);

    QString getName() const;
    double getArea() const;

private:
    double area;
    QString name;
};

#endif // MARINE_H
