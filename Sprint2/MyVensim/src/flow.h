#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include "system.h"

using namespace std;

class Flow
{
private:
    string name;
    System *source;
    System *target;

    Flow(const Flow &flow);
    Flow operator=(const Flow &other);

public:
    Flow(const string &name);
    virtual ~Flow();
    string getName();
    void setSource(System *source);
    void setTarget(System *target);
    System *getSource();
    System *getTarget();
    void connect(System *source, System *target);
    void disconnect();
    virtual float execute();
};

class Exponencial : public Flow
{
public:
    Exponencial(const string &name);
    virtual float execute();
};

class Logistic : public Flow
{
private:
    float pmax;

public:
    Logistic(const string &name, int pmax);
    virtual float execute();
};

#endif