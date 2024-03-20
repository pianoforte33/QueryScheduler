#include "queryscheduler.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QueryScheduler w;
    w.show();
    return a.exec();
}
