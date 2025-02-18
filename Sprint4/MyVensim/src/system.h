#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>

using namespace std;

/**
 * @file system.h
 * @brief Interface of the System class
 * @date 2025-02-05
 * @version 1.2
 * @author Thiago Ayolphi Liuth e Yasmin Altino Araújo
 */

/**
 * @class System
 * @brief Interface of the class representing a System.
 */
class System
{
public:
    virtual ~System(void) {}
    virtual string getName(void) = 0;
    virtual float getValue(void) = 0;
    virtual void setValue(float) = 0;
};

#endif