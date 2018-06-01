#ifndef CONTINENTEDITWINDOW_H
#define CONTINENTEDITWINDOW_H

#include <QDialog>

namespace Ui {
class ContinentEditWindow;
}

class ContinentEditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ContinentEditWindow(QWidget *parent = 0);
    ~ContinentEditWindow();

private:
    Ui::ContinentEditWindow *ui;
};

#endif // CONTINENTEDITWINDOW_H
