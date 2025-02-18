#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include "system.h"

using namespace std;

/**
 * @author Thiago Ayolphi Liuth e Yasmin Altino Araújo
 * @file flow.h
 * @brief Interface of the Flow class
 * @date 2025-02-05
 * @version 1.2
 */

/**
 * @class Flow
 * @brief Interface of the class representing a Flow
 */
class Flow
{
public:
    virtual ~Flow(void) {}
    virtual string getName(void) = 0;
    virtual void setSource(System *source) = 0;
    virtual void setTarget(System *target) = 0;
    virtual System *getSource() = 0;
    virtual System *getTarget() = 0;
    virtual void connect(System *source, System *target) = 0;
    virtual void disconnect() = 0;
    virtual float execute() = 0;
};

#endif
