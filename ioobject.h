/*************
 * Class defining what an object going into a security box is
 * All variables can only be set by the constructor
 * ***********/

#ifndef IOOBJECT_H
#define IOOBJECT_H

#include <QVector>

class IOObject
{
public:
    // Constructor
    IOObject();

    // Copy Constructor
    IOObject(const IOObject& io);

    // Accessors
    void setID(int id);
    int getID() const;

    void setLocation(QString location);
    QString getLocation() const;

    void setLocationDetail(QString locationDetail);
    QString getLocationDetail() const;

    void setType(QString type);
    QString getType() const;

    void addInput(QString in);
    QVector<QString> getInputs() const;

    void addOutput(QString out);
    QVector<QString> getOutputs() const;

private:
    int m_id;                      // ID number for this IO object
    QString m_location;                // where this object is located
    QString m_locationDetail;          // detail where this object is located
    QString m_type;                // Type of object (e.g. buried line)
    QVector<QString> m_inputs;     // Inputs that goes into the object (e.g. Power)
    QVector<QString> m_outputs;    // Outputs that would go into a security box (e.g. Alarm)
};

#endif // IOOBJECT_H
