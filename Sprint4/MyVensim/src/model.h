#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include "flow.h"
#include <vector>

typedef vector<System *>::iterator systemIterator;
typedef vector<Flow *>::iterator flowIterator;

/**
 * @file model.h
 * @brief Interface of the Model class
 * @date 2025-02-05
 * @version 1.2
 * @author Thiago Ayolphi Liuth e Yasmin Altino Araújo
 */

/**
 * @class Model
 * @brief Interface of the class representing a Model.
 */

class Model
{
public:
    virtual ~Model() {}
    virtual void add(System *system) = 0;
    virtual void add(Flow *flow) = 0;
    virtual void run(int iterations) = 0;
    virtual void remove(System *system) = 0;
    virtual void remove(Flow *flow) = 0;
    virtual systemIterator systemsBegin() = 0;
    virtual systemIterator systemsEnd() = 0;
    virtual flowIterator flowsBegin() = 0;
    virtual flowIterator flowsEnd() = 0;
};

#endif