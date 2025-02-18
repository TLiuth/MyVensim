#include "flow.h"

Flow::Flow(const string &name)
{
    this->name = name;
}

Flow::~Flow() {}

string Flow::getName()
{
    return this->name;
}

void Flow::setSource(System *source)
{
    this->source = source;
}

void Flow::setTarget(System *target)
{
    this->target = target;
}

System *Flow::getSource()
{
    return this->source;
}

System *Flow::getTarget()
{
    return this->target;
}

float Flow::execute()
{
    return 0.0;
}

void Flow::connect(System *source, System *target)
{
    this->source = source;
    this->target = target;
}

void Flow::disconnect()
{
    this->source = nullptr;
    this->target = nullptr;
}

Flow::Flow(const Flow &flow)
{
    this->name = flow.name;
    this->source = flow.source;
    this->target = flow.target;
}

Flow Flow::operator=(const Flow &other)
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

Exponencial::Exponencial(const string &name) : Flow(name)
{
}

float Exponencial::execute()
{
    if (getTarget() == nullptr || getSource() == nullptr)
    {
        cerr << "Erro: Target ou Source é nullptr." << endl;
        return 0.0;
    }
    return 0.01 * getSource()->getValue();
}

// Classe Logistic

Logistic::Logistic(const string &name, int pmax) : Flow(name)
{
    this->pmax = pmax;
}

float Logistic::execute()
{
    if (getTarget() == nullptr || getSource() == nullptr)
    {
        cerr << "Erro: Target ou Source é nullptr." << endl;
        return 0.0;
    }
    return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / pmax);
}
