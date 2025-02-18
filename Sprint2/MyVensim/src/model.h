#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>
#include "system.h"
#include "flow.h"

using namespace std;

class Model
{
private:
    vector<System *> systems;
    vector<Flow *> flows;

    Model(const Model &model);
    Model operator=(const Model &other);

public:
    Model();
    virtual ~Model();
    void add(System *system);
    void add(Flow *flow);
    void run(int iterations);
    void remove(System *system);
    void remove(Flow *flow);
    decltype(systems.begin()) systemsBegin();
    decltype(systems.end()) systemsEnd();
    decltype(flows.begin()) flowsBegin();
    decltype(flows.end()) flowsEnd();
};

#endif
