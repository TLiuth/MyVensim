#include "flowImpl.h"

FlowImpl::FlowImpl(const string &name)
{
    this->name = name;
}

FlowImpl::~FlowImpl() {}

string FlowImpl::getName()
{
    return this->name;
}

void FlowImpl::setSource(System *source)
{
    this->source = source;
}

void FlowImpl::setTarget(System *target)
{
    this->target = target;
}

System *FlowImpl::getSource()
{
    return this->source;
}

System *FlowImpl::getTarget()
{
    return this->target;
}

float FlowImpl::execute()
{
    return 0.0;
}

void FlowImpl::connect(System *source, System *target)
{
    this->source = source;
    this->target = target;
}

void FlowImpl::disconnect()
{
    this->source = nullptr;
    this->target = nullptr;
}

FlowImpl::FlowImpl(const FlowImpl &FlowImpl)
{
    this->name = FlowImpl.name;
    this->source = FlowImpl.source;
    this->target = FlowImpl.target;
}

FlowImpl FlowImpl::operator=(const FlowImpl &other)
{
    if (this != &other)
    {
        name = other.name;
        source = other.source;
        target = other.target;
    }
    return *this;
}

// Classe Exponential

Exponencial::Exponencial(const string &name) : FlowImpl(name)
{
}

float Exponencial::execute()
{
    if (getTarget() != nullptr && getSource() != nullptr)
    {
        return 0.01 * getSource()->getValue();
    }

    return 0.0;
}

// Classe Logistic

Logistic::Logistic(const string &name, int pmax) : FlowImpl(name)
{
    this->pmax = pmax;
}

float Logistic::execute()
{
    if (getTarget() != nullptr && getSource() != nullptr)
    {
        return 0.01 * this->getTarget()->getValue() * (1 - this->getTarget()->getValue() / pmax);
    }

    return 0.0;
}
