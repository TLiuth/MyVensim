#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>

using namespace std;

class System
{
private:
    float value;
    string name;

    System(const System &system);
    System &operator=(const System &other);

public:
    System(const string &name, float value);
    virtual ~System();
    string getName();
    float getValue();
    void setValue(float value);
};

#endif