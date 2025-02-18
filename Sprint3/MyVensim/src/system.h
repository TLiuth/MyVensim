#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>

using namespace std;

/**
 * @file system.h
 * @brief Declaration the system class
 * @date 2025-01-27
 * @version 1.1
 * @author Thiago Ayolphi Liuth e Yasmin Altino Araújo
 */

/**
 * @class System
 * @brief Class representing a system.
 */
class System
{
private:
    float value; ///< Value of the System
    string name; ///< Name of the System

    System(const System &system);
    System &operator=(const System &other);

public:
    /**
     * @brief Constructor of the System class.
     * @param name Name of the system.
     * @param value Initial value of the system.
     */
    System(const string &name, float value);

    /**
     * @brief Destructor of the System class.
     */
    virtual ~System();

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
};

#endif