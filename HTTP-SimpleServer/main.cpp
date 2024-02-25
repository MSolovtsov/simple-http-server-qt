#include <QCoreApplication>
#include "simpleserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SimpleServer s(nullptr);
    return a.exec();
}
