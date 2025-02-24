#include "modelImpl.h"
#include "systemImpl.h"

Model *ModelImpl::instance = nullptr;

Model &ModelImpl::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ModelImpl();
    }
    return *instance;
}

ModelImpl::ModelImpl()
{
    time = 0;
}

ModelImpl::~ModelImpl()
{
    for (auto it = systemsBegin(); it != systemsEnd(); it++)
    {
        delete *it;
    }
    for (auto it = flowsBegin(); it != flowsEnd(); it++)
    {
        delete *it;
    }

    systems.clear();
    flows.clear();
}

Model &Model::createModel()
{
    return ModelImpl::createModel();
}

Model &ModelImpl::createModel()
{
    Model *model = new ModelImpl();
    return *model;
}

System &ModelImpl::createSystem(string name, float value)
{
    System *system = new SystemImpl(name, value);
    add(system);
    return *system;
}

void ModelImpl::add(System *system)
{
    systems.push_back(system);
}

void ModelImpl::add(Flow *flow)
{
    this->flows.push_back(flow);
}

void ModelImpl::run(int iterations)
{
    for (this->time = 0; this->time < iterations; this->time++)
    {
        vector<float> values;
        int j = 0;
        for (auto it = flowsBegin(); it != flowsEnd(); ++it)
        {
            values.push_back((*it)->execute());
        }
        for (auto it = flowsBegin(); it != flowsEnd(); ++it, j++)
        {
            (*it)->getTarget()->setValue((*it)->getTarget()->getValue() + values[j]);
            (*it)->getSource()->setValue((*it)->getSource()->getValue() - values[j]);
        }
    }
}

ModelImpl::ModelImpl(const ModelImpl &model)
{
    this->systems = model.systems;
    this->flows = model.flows;
}

ModelImpl ModelImpl::operator=(const ModelImpl &other)
{
    if (this != &other)
    {
        systems = other.systems;
        flows = other.flows;
    }
    return *this;
}

void ModelImpl::remove(System *system)
{
    for (auto it = systemsBegin(); it != systemsEnd(); it++)
    {
        if (*it == system)
        {
            systems.erase(it);
            break;
        }
    }
}

void ModelImpl::remove(Flow *flow)
{
    for (auto it = flowsBegin(); it != flowsEnd(); it++)
    {
        if (*it == flow)
        {
            flows.erase(it);
            break;
        }
    }
}

systemIterator ModelImpl::systemsBegin()
{
    return systems.begin();
}

systemIterator ModelImpl::systemsEnd()
{
    return systems.end();
}

flowIterator ModelImpl::flowsBegin()
{
    return flows.begin();
}

flowIterator ModelImpl::flowsEnd()
{
    return flows.end();
}