#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include <iostream>
#include <vector>
#include "model.h"
using namespace std;

/**
 * @file modelImpl.h
 * @brief Implementation of the Model class.
 * @date 2025-01-27
 * @version 1.1
 * @author Thiago Ayolphi Liuth and Yasmin Altino Araújo
 */

/**
 * @class ModelImpl
 * @brief Class representing a Model
 */
class ModelImpl : public Model
{
private:
    vector<System *> systems; ///< Vector of systems in the Model
    vector<Flow *> flows;     ///< Vector of flows in the Model
    int time;                 ///< Time of the Model

    ModelImpl(const ModelImpl &model);
    ModelImpl operator=(const ModelImpl &other);

public:
    /**
     * @brief Constructor of the Model class.
     */
    ModelImpl();

    /**
     * @brief Destructor of the Model class.
     */

    virtual ~ModelImpl();

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
    systemIterator systemsBegin();

    /**
     * @brief Returns an iterator to the end of the systems.
     * @return Iterator to the end of the systems.
     */
    systemIterator systemsEnd();

    /**
     * @brief Returns an iterator to the beginning of the flows.
     * @return Iterator to the beginning of the flows.
     */
    flowIterator flowsBegin();

    /**
     * @brief Returns an iterator to the end of the flows.
     * @return Iterator to the end of the flows.
     */
    flowIterator flowsEnd();

    friend class unit_model;
};

#endif