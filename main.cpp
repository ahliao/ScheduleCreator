#include <QCoreApplication>
//#include <iostream>

#include "fdb_object.h"

//using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FDB_Object FDB;
    FDB.readFromCSV("Test.csv");

    FDB.printSchedule();

    return a.exec();
}
