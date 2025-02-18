#include "../../src/model.h"
#include "../../src/flow.h"
#include "../../src/system.h"
#include <algorithm>

#include "unit_model.h"

void unit_model_constructor(void)
{
    Model model;

    assert(model.getSystems().empty());
    assert(model.getFlows().empty());
}

void unit_model_destructor(void)
{
}

void unit_model_getSystems(void)
{
    Model model;
    System system1("Test System 1", 10);
    System system2("Test System 2", 20);

    model.add(&system1);
    model.add(&system2);

    vector<System *> systems = model.getSystems();

    assert(systems.size() == 2);
    assert(systems[0] == &system1);
    assert(systems[1] == &system2);
}

void unit_model_getFlows(void)
{
    Model model;
    Flow flow1("Test Flow 1");
    Flow flow2("Test Flow 2");

    model.add(&flow1);
    model.add(&flow2);

    vector<Flow *> flows = model.getFlows();

    assert(flows.size() == 2);
    assert(flows[0] == &flow1);
    assert(flows[1] == &flow2);
}

void unit_model_add(void)
{
    Model model;
    System system("Test System", 10);
    Flow flow("Test Flow");

    model.add(&system);
    model.add(&flow);

    assert(model.getSystems().size() == 1);
    assert(model.getSystems()[0] == &system);

    assert(model.getFlows().size() == 1);
    assert(model.getFlows()[0] == &flow);
}

void unit_model_run(void)
{
}

void unit_model_remove(void)
{
    Model model;
    System system("Test System", 10);
    Flow flow("Test Flow");

    model.add(&system);
    model.add(&flow);

    model.remove(&system);
    model.remove(&flow);

    assert(model.getFlows().size() == 0);
    assert(find(model.getSystems().begin(), model.getSystems().end(), &system) == model.getSystems().end());

    assert(model.getSystems().size() == 0);
    assert(find(model.getFlows().begin(), model.getFlows().end(), &flow) == model.getFlows().end());
}

void run_unit_test_model(void)
{
    unit_model_constructor();
    unit_model_destructor();
    unit_model_getSystems();
    unit_model_getFlows();
    unit_model_add();
    unit_model_remove();
    unit_model_run();
}