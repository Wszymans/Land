#ifndef MARINEEDITWINDOW_H
#define MARINEEDITWINDOW_H

#include <QDialog>

namespace Ui {
class MarineEditWindow;
}

class MarineEditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MarineEditWindow(QWidget *parent = 0);
    ~MarineEditWindow();

private:
    Ui::MarineEditWindow *ui;
};

#endif // MARINEEDITWINDOW_H
