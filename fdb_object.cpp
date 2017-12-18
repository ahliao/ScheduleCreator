#include "fdb_object.h"

FDB_Object::FDB_Object()
{

}

void FDB_Object::printSchedule()
{
    qDebug() << m_name;
    for (IOObject i : m_FDB_IOObjects) {
        qDebug() << i.getType() << "\t" << i.getLocation();
    }
}

bool FDB_Object::readFromCSV(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    // Read the FDB Name
    QString line;
    line = file.readLine();
    m_name = line.split(',').first();

    // Read the column headers
    QStringList colHeaders;
    line = file.readLine();
    line.remove(QRegExp("[\\n\\t\\r]"));
    colHeaders = line.split(',');

    // Read each line
    QStringList colStrings;
    while (!file.atEnd()) {
        IOObject ioobject;
        line = file.readLine();
        //line.remove(QRegExp("[\\n\\t\\r]"));
        colStrings = line.split(',');

        for (int i = 0; i < colHeaders.size(); ++i) {

            if (!colHeaders.at(i).compare("Sensor Type")) {
                ioobject.setType(colStrings[i]);
                //qDebug() << "Added: " << colStrings[i];
                //qDebug() << "Added: " << colHeaders[i];
            } else if (!colHeaders.at(i).compare("Location")) {
                ioobject.setLocation(colStrings[i]);
            } else if (!colHeaders.at(i).compare("Location Detail")) {
                ioobject.setLocationDetail(colStrings[i]);
            } else if (!colHeaders.at(i).compare("Input")) {
                if (!colStrings.at(i).isEmpty())
                    ioobject.addInput(colStrings.at(i));
            } else if (!colHeaders.at(i).compare("Output")) {
                if (!colStrings.at(i).isEmpty())
                    ioobject.addOutput(colStrings[i]);
            }
        }

        // Add the IOObject to the FDB
        m_FDB_IOObjects.append(ioobject);
    }

    return true;
}
