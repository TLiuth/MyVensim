#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include "system.h"

using namespace std;

/**
 * @author Thiago Ayolphi Liuth e Yasmin Altino Araújo
 * @file flow.h
 * @brief Flow, Exponential and Logistic Classes Declaration
 * @date 2025-01-27
 * @version 1.1
 */

/**
 * @class Flow
 * @brief This class represents a flow of mass or energy
 */
class Flow
{
private:
    string name;    ///< Identification name of the flow
    System *source; ///< Points to a source system
    System *target; ///< Points to a target system

    Flow(const Flow &flow);
    Flow operator=(const Flow &other);

public:
    /**
     * @brief Flow class constructor
     * @param name Flow name
     */
    Flow(const string &name);
    /**
     * @brief Flow class destructor
     */
    virtual ~Flow();
    /**
     * @brief Return the name of the flow.
     * @return a string containing the flow name.
     */
    string getName();

    /**
     * @brief Sets the flow source system.
     * @param source Source system.
     */
    void setSource(System *source);

    /**
     * @brief Sets the flow target system.
     * @param target Target system.
     */
    void setTarget(System *target);

    /**
     * @brief Returns the flow source system.
     * @return System* The flow source system.
     */
    System *getSource();

    /**
     * @brief Returns the flow target system.
     * @return System* The flow target system.
     */
    System *getTarget();

    /**
     * @brief Connects the flow to two systems.
     * @param source The source system of the flow.
     * @param target The target system of the flow.
     */
    void connect(System *source, System *target);

    /**
     * @brief Disconnects the flow of both a source and a target
     */
    void disconnect();

    /**
     * @brief Executes the flow.
     * @return float: The flow result value.
     */
    virtual float execute();
};

/**
 * @class Exponencial
 * @brief Class that represents an exponential flow.
 */

class Exponencial : public Flow
{
public:
    /**
     * @brief Constructor of the Exponencial class.
     * @param name Name of the flow.
     */
    Exponencial(const string &name);

    /**
     * @brief Executes the exponential flow.
     * @return float Value of the exponential flow.
     */
    virtual float execute();
};

/**
 * @class Logistic
 * @brief Class that represents a logistic flow.
 */
class Logistic : public Flow
{
private:
    float pmax; ///< Maximal value of the logistical Flow.

public:
    /**
     * @brief Constructor of the Logistical Flow.
     * @param name Name of the Flow.
     * @param pmax Maximal value of the logistical Flow.
     */
    Logistic(const string &name, int pmax);

    /**
     * @brief Execuutes the logistical Flow.
     * @return float Value of the logistical Flow.
     */
    virtual float execute();
};

#endif