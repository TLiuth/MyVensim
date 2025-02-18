#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>
#include "system.h"
#include "flow.h"

using namespace std;

/**
 * @file model.h
 * @brief Declaration of the Model class.
 * @date 2025-01-27
 * @version 1.1
 * @author Thiago Ayolphi Liuth and Yasmin Altino Araújo
 */

/**
 * @class Model
 * @brief Represents a Model that contais systems and flows.
 */
class Model
{
private:
    vector<System *> systems; ///< Vector of systems in the Model
    vector<Flow *> flows;     ///< Vector of flows in the Model

    Model(const Model &model);
    Model operator=(const Model &other);

public:
    /**
     * @brief Constructor of the Model class.
     */
    Model();

    /**
     * @brief Destructor of the Model class.
     */

    virtual ~Model();

    /**
     * @brief Adds a system to the model.
     * @param system System to be added.
     */
    void add(System *system);

    /**
     * @brief Adds a flow to the model.
     * @param flow Flow to be added.
     */
    void add(Flow *flow);

    /**
     * @brief Runs the model for a number of iterations.
     * @param iterations Number of iterations.
     */
    void run(int iterations);

    /**
     * @brief Removes a system from the model.
     * @param system System to be removed.
     */
    void remove(System *system);

    /**
     * @brief Removes a flow from the model.
     * @param flow Flow to be removed.
     */
    void remove(Flow *flow);

    /**
     * @brief Returns an iterator to the beginning of the systems.
     * @return Iterator to the beginning of the systems.
     */
    decltype(systems.begin()) systemsBegin();

    /**
     * @brief Returns an iterator to the end of the systems.
     * @return Iterator to the end of the systems.
     */
    decltype(systems.end()) systemsEnd();

    /**
     * @brief Returns an iterator to the beginning of the flows.
     * @return Iterator to the beginning of the flows.
     */
    decltype(flows.begin()) flowsBegin();

    /**
     * @brief Returns an iterator to the end of the flows.
     * @return Iterator to the end of the flows.
     */
    decltype(flows.end()) flowsEnd();
};

#endif