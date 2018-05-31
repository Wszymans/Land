#include "land.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Land w;
    w.show();

    return a.exec();
}
