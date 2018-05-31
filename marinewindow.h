#ifndef MARINEWINDOW_H
#define MARINEWINDOW_H

#include <QDialog>
#include "marine.h"

namespace Ui {
class MarineWindow;
}

class MarineWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MarineWindow(QWidget *parent = 0);
    ~MarineWindow();

signals:
     void sendMarine(Marine marine);

private slots:
      void SaddMarine();

private:
    Ui::MarineWindow *ui;
};

#endif // MARINEWINDOW_H
