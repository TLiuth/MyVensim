#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include <iostream>
#include "system.h"

using namespace std;

/**
 * @file systemImpl.h
 * @brief Implementation of the System class
 * @date 2025-01-27
 * @version 1.1
 * @author Thiago Ayolphi Liuth e Yasmin Altino Araújo
 */

/**
 * @class SystemImpl
 * @brief Class representing a System.
 */
class SystemImpl : public System
{
private:
    float value; ///< Value of the System
    string name; ///< Name of the System

    SystemImpl(const SystemImpl &system);
    SystemImpl &operator=(const SystemImpl &other);

public:
    /**
     * @brief Constructor of the System class.
     * @param name Name of the system.
     * @param value Initial value of the system.
     */
    SystemImpl(const string &name, float value);

    /**
     * @brief Destructor of the System class.
     */
    virtual ~SystemImpl();

    /**
     * @brief Returns the name of the system.
     * @return string Name of the system.
     */
    string getName();

    /**
     * @brief Returns the value of the system.
     * @return float Value of the system.
     */
    float getValue();

    /**
     * @brief Sets the value of the system.
     * @param value Value of the system.
     */
    void setValue(float value);

    friend class unit_system;
};

#endif