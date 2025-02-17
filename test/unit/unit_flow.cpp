#include "unit_flow.h"

void unit_flow::unit_flow_constructor(void)
{
    FlowImpl flow1("Test flow1");
    FlowImpl flow2("Test flow2");

    assert(flow1.name == "Test flow1");
    assert(flow2.name == "Test flow2");
}

void unit_flow::unit_flow_destructor(void)
{
}

void unit_flow::unit_flow_getName(void)
{
    FlowImpl flow("");

    flow.name = "Test flow";

    assert(flow.getName() == "Test flow");
}

void unit_flow::unit_flow_setSource(void)
{
    FlowImpl flow("");
    SystemImpl system("Test system", 0.0);

    flow.name = "Test flow";
    flow.setSource(&system);

    assert(flow.source == &system);
}

void unit_flow::unit_flow_setTarget(void)
{
    FlowImpl flow("");
    SystemImpl system("Test system", 0.0);

    flow.setTarget(&system);

    assert(flow.target == &system);
}

void unit_flow::unit_flow_getTarget(void)
{
    FlowImpl flow("");
    SystemImpl system("Test system", 0.0);

    flow.name = "Test flow";
    flow.target = &system;

    assert(flow.getTarget() == &system);
}

void unit_flow::unit_flow_getSource(void)
{
    FlowImpl flow("");
    SystemImpl system("Test system", 0.0);

    flow.source = &system;

    assert(flow.getSource() == &system);
}

void unit_flow::unit_flow_connect(void)
{
    FlowImpl flow("");
    SystemImpl system1("Test system1", 0.0);
    SystemImpl system2("Test system2", 10.0);

    flow.connect(&system1, &system2);

    assert(flow.source == &system1);
    assert(flow.target == &system2);
}

void unit_flow::unit_flow_disconnect(void)
{

    FlowImpl flow("");
    SystemImpl system1("Test system1", 0.0);
    SystemImpl system2("Test system2", 10.0);

    flow.source = &system1;
    flow.target = &system2;

    flow.disconnect();

    assert(flow.source == nullptr);
    assert(flow.target == nullptr);
}

void unit_flow::unit_flow_execute(void)
{
    FlowImpl flow("Test flow");

    assert(flow.execute() == 0.0);
}

void unit_flow::unit_flow_exponencial_constructor(void)
{
    Exponencial expoFlow("Test expoFlow");

    assert(expoFlow.name == "Test expoFlow");
}

void unit_flow::unit_flow_logistic_constructor(void)
{
    Logistic logFlow("Test logFlow", 70);

    assert(logFlow.name == "Test logFlow");
    assert(logFlow.pmax == 70);
}

void unit_flow::run_unit_test_flow(void)
{
    unit_flow_constructor();
    unit_flow_destructor();
    unit_flow_getName();
    unit_flow_setSource();
    unit_flow_setTarget();
    unit_flow_getSource();
    unit_flow_getTarget();
    unit_flow_connect();
    unit_flow_disconnect();
    unit_flow_execute();

    unit_flow_exponencial_constructor();

    unit_flow_logistic_constructor();
}