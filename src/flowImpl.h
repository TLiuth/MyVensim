#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include <iostream>
#include "system.h"
#include "flow.h"

using namespace std;

/**
 * @author Thiago Ayolphi Liuth e Yasmin Altino Araújo
 * @file flowImpl.h
 * @brief Flow, Exponencial and Logistic Classes Implementation
 * @date 2025-01-27
 * @version 1.1
 */

/**
 * @class FlowImpl
 * @brief Class representing a Flow
 */
class FlowImpl : public Flow
{
private:
    string name;    ///< Identification name of the flow
    System *source; ///< Points to a source system
    System *target; ///< Points to a target system

    FlowImpl(const FlowImpl &flow);
    FlowImpl operator=(const FlowImpl &other);

public:
    /**
     * @brief Flow class constructor
     * @param name Flow name
     */
    FlowImpl(const string &name);
    /**
     * @brief Flow class destructor
     */
    virtual ~FlowImpl();
    /**
     * @brief Return the name of the flow.
     * @return a string containing the flow name.
     */
    string getName(void);

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
    System *getSource(void);

    /**
     * @brief Returns the flow target system.
     * @return System* The flow target system.
     */
    System *getTarget(void);

    /**
     * @brief Connects the flow to two systems.
     * @param source The source system of the flow.
     * @param target The target system of the flow.
     */
    void connect(System *source, System *target);

    /**
     * @brief Disconnects the flow of both a source and a target
     */
    void disconnect(void);

    /**
     * @brief Executes the flow.
     * @return float: The flow result value.
     */
    virtual float execute(void);

    friend class unit_flow;
};

/**
 * @class Exponencial
 * @brief Class that represents an exponential Flow.
 */

class Exponencial : public FlowImpl
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
 * @brief Class that represents a logistic Flow.
 */
class Logistic : public FlowImpl
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

    friend class unit_flow;
};

#endif