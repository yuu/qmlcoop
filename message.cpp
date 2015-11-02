#include "message.h"

void message::setAge(int &age)
{
    m_age = age;
}

int message::Age() const
{
    return m_age;
}

