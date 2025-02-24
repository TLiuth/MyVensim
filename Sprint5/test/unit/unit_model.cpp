
#include "unit_model.h"

void unit_model::unit_model_constructor(void)
{
    ModelImpl model;

    assert(model.systems.empty());
    assert(model.flows.empty());
}

void unit_model::unit_model_destructor(void)
{
}

void unit_model::unit_model_add(void)
{
    ModelImpl model;
    System *system = new SystemImpl("Test System", 10);
    Flow *flow = new FlowImpl("Test Flow");

    model.add(system);
    model.add(flow);

    assert(model.systems.size() == 1);
    assert(find(model.systems.begin(), model.systems.end(), system) != model.systems.end());
    assert(model.flows.size() == 1);
    assert(find(model.flows.begin(), model.flows.end(), flow) != model.flows.end());
}

// verificar se o relógio de simulação avançou
void unit_model::unit_model_run(void)
{
    ModelImpl model;
    model.run(10);

    assert(model.time == 10);
}

void unit_model::unit_model_remove(void)
{
    ModelImpl model;
    System *system = new SystemImpl("Test System", 10);
    Flow *flow = new FlowImpl("Test Flow");

    model.add(system);
    model.add(flow);

    model.remove(system);
    model.remove(flow);

    assert(model.flows.size() == 0);
    assert(find(model.systems.begin(), model.systems.end(), system) == model.systems.end());

    assert(model.systems.size() == 0);
    assert(find(model.flows.begin(), model.flows.end(), flow) == model.flows.end());
}

void unit_model::unit_model_iterator_flow(void)
{
    ModelImpl model;

    flowIterator itbegin = model.flowsBegin();
    flowIterator itend = model.flowsEnd();

    assert(itbegin != itend);
    assert(itbegin == model.flows.begin());
    assert(itend == model.flows.end());
}

void unit_model::unit_model_iterator_system(void)
{
    ModelImpl model;

    systemIterator itbegin = model.systemsBegin();
    systemIterator itend = model.systemsEnd();

    assert(itbegin != itend);
    assert(itbegin == model.systems.begin());
    assert(itend == model.systems.end());
}

void unit_model::run_unit_test_model(void)
{
    unit_model_constructor();
    unit_model_destructor();
    unit_model_add();
    unit_model_remove();
    unit_model_run();
}