#include "systemImpl.h"

SystemImpl::SystemImpl(const string &name, float value)
{
    this->name = name;
    this->value = value;
}

SystemImpl::~SystemImpl() {}

string SystemImpl::getName()
{
    return this->name;
}

float SystemImpl::getValue()
{
    return this->value;
}

void SystemImpl::setValue(float value)
{
    this->value = value;
}

SystemImpl::SystemImpl(const SystemImpl &system)
{
    this->name = system.name;
    this->value = system.value;
}

SystemImpl &SystemImpl::operator=(const SystemImpl &other)
{
    if (this != &other)
    {
        name = other.name;
        value = other.value;
    }
    return *this;
}
