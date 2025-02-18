#include "model.h"

Model::Model() {}

Model::~Model() {}

void Model::add(System *system)
{
    systems.push_back(system);
}

void Model::add(Flow *flow)
{
    this->flows.push_back(flow);
}

void Model::run(int iterations)
{
    for (int i = 0; i < iterations; i++)
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

Model::Model(const Model &model)
{
    this->systems = model.systems;
    this->flows = model.flows;
}

Model Model::operator=(const Model &other)
{
    if (this != &other)
    {
        systems = other.systems;
        flows = other.flows;
    }
    return *this;
}

void Model::remove(System *system)
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

void Model::remove(Flow *flow)
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

decltype(Model::systems.begin()) Model::systemsBegin()
{
    return systems.begin();
}

decltype(Model::systems.end()) Model::systemsEnd()
{
    return systems.end();
}

decltype(Model::flows.begin()) Model::flowsBegin()
{
    return flows.begin();
}

decltype(Model::flows.end()) Model::flowsEnd()
{
    return flows.end();
}