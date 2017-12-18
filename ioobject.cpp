#include "ioobject.h"

IOObject::IOObject()
{
    m_id = 0;
    m_location = "";
    m_locationDetail = "";
    m_type = "";
}

IOObject::IOObject(const IOObject& io)
{
    m_id = io.getID();
    m_location = io.getLocation();
    m_locationDetail = io.getLocationDetail();
    m_type = io.getType();
    m_inputs = io.getInputs();
    m_outputs = io.getOutputs();
}

// Accessors
void IOObject::setID(int id)
{
    m_id = id;
}

int IOObject::getID() const
{
    return m_id;
}

void IOObject::setLocation(QString location)
{
    m_location = location;
}

QString IOObject::getLocation() const
{
    return m_location;
}

void IOObject::setLocationDetail(QString locationDetail)
{
    m_locationDetail = locationDetail;
}

QString IOObject::getLocationDetail() const
{
    return m_locationDetail;
}

void IOObject::setType(QString type)
{
    m_type = type;
}

QString IOObject::getType() const
{
    return m_type;
}

void IOObject::addInput(QString in)
{
    m_inputs.append(in);
}

QVector<QString> IOObject::getInputs() const
{
    return m_inputs;
}

void IOObject::addOutput(QString out)
{
    m_inputs.append(out);
}

QVector<QString> IOObject::getOutputs() const
{
    return m_outputs;
}
