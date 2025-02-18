#ifndef FUNCTIONAL_TESTS_H
#define FUNCTIONAL_TESTS_H
#include <iostream>
#include <cassert>
#include <cmath>
#include "../../src/flow.h"
#include "../../src/model.h"
#include "../../src/system.h"

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

#endif // FUNCTIONAL_TESTS_H