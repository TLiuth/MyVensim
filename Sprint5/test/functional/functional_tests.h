#ifndef FUNCTIONAL_TESTS_H
#define FUNCTIONAL_TESTS_H
#include <iostream>
#include <cassert>
#include <cmath>
#include "../../src/model.h"
#include "../../src/flowImpl.h"

/**
 * @file functional_tests.h
 * @brief Declaration of functional test functions.
 * @date 2025-01-27
 * @version 1.1
 * @author Thiago Ayolphi Liuth and Yasmin Altino Araújo
 */

/**
 * @brief Functional test for the exponential flow.
 */
void exponentialFuncionalTest();

/**
 * @brief Functional test for the logistical flow.
 */
void logisticalFuncionalTest();

/**
 * @brief Complex functional test involving multiple systems and flows.
 */
void complexFuncionalTest();

class Exponencial : public FlowImpl
{
public:
    /**
     * @brief Constructor of the Exponencial class.
     * @param name Name of the flow.
     */
    Exponencial(const string &name) : FlowImpl(name) {}

    /**
     * @brief Executes the exponential flow.
     * @return float Value of the exponential flow.
     */
    virtual float execute()
    {
        if (getTarget() != nullptr && getSource() != nullptr)
        {
            return 0.01 * getSource()->getValue();
        }

        return 0.0;
    }
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
    Logistic(const string &name, int pmax) : FlowImpl(name)
    {
        this->pmax = pmax;
    }

    /**
     * @brief Executes the logistical Flow.
     * @return float Value of the logistical Flow.
     */
    virtual float execute()
    {
        if (getTarget() != nullptr && getSource() != nullptr)
        {
            return 0.01 * this->getTarget()->getValue() * (1 - this->getTarget()->getValue() / pmax);
        }

        return 0.0;
    }

    friend class unit_flow;
};

#endif // FUNCTIONAL_TESTS_H