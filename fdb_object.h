#ifndef FDB_OBJECT_H
#define FDB_OBJECT_H

//#include <QVector>
#include <QFile>
#include <QStringList>
#include <QDebug>
#include "ioobject.h"

class FDB_Object
{
public:
    FDB_Object();

    bool readFromCSV(QString filename);

    void printSchedule();

private:
    QString m_name;
    QVector<IOObject> m_FDB_IOObjects;
    //QVector<QString> m_FDBInputs;      // All inputs going into the FDB
    //QVector<QString> m_FDBOutputs;     // ALl outputs going out of the FDB
};

#endif // FDB_OBJECT_H
