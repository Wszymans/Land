#ifndef MARINE_H
#define MARINE_H

#include <QString>

class Marine {

public:
    Marine(QString name = "Default", double area = 200);
    Marine(const Marine &Marine);

    QString getName() const;
    double getArea() const;

private:
    double area;
    QString name;
};

#endif // MARINE_H
