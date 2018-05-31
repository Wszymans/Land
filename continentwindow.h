#ifndef CONTINENTWINDOW_H
#define CONTINENTWINDOW_H

#include <QDialog>
#include "continent.h"
#include "marine.h"

namespace Ui {
class ContinentWindow;
}

class ContinentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ContinentWindow(QWidget *parent = 0);
    ~ContinentWindow();

signals:
    void sendContinent(Continent continent);

private slots:
    void SaddContinent();

private:
    Ui::ContinentWindow *ui;
};

#endif // CONTINENTWINDOW_H
