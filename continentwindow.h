#ifndef CONTINENTWINDOW_H
#define CONTINENTWINDOW_H

#include <QDialog>

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

private slots:

private:
    Ui::ContinentWindow *ui;
};

#endif // CONTINENTWINDOW_H
