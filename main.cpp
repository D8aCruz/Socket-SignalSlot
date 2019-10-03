#include <QCoreApplication>
#include "socketTest.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    socketTest mTest;
    mTest.Test();
    return a.exec();
}
