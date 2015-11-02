#include "message.h"

void message::setName(QString &name)
{
    m_name = name;
}

QString message::Name() const
{
    return m_name;
}

