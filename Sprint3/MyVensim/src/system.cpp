#include "system.h"

System::System(const string &name, float value)
{
    this->name = name;
    this->value = value;
}

System::~System() {}

string System::getName()
{
    return this->name;
}

float System::getValue()
{
    return this->value;
}

void System::setValue(float value)
{
    this->value = value;
}

System::System(const System &system)
{
    this->name = system.name;
    this->value = system.value;
}

System &System::operator=(const System &other)
{
    if (this != &other)
    {
        name = other.name;
        value = other.value;
    }
    return *this;
}