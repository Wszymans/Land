#ifndef CONTINENTEDITWINDOW_H
#define CONTINENTEDITWINDOW_H

#include <QDialog>
#include <QVector>
#include <continent.h>

namespace Ui {
class ContinentEditWindow;
}

class ContinentEditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ContinentEditWindow(QWidget *parent = 0);
    void reciveContinents(QVector<Continent> recivedContinents);
    ~ContinentEditWindow();

private:
    Ui::ContinentEditWindow *ui;
    QVector<Continent> continents;
};

#endif // CONTINENTEDITWINDOW_H
