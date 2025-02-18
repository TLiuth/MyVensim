#include "../../src/system.h"
#include "unit_system.h"

#define EPSILON 0.0001

void unit_system_constructor(void)
{
    System sys1("System1", 100);
    System sys2("System2", 120.56);

    assert(sys1.getName() == "System1");
    assert(sys1.getValue() == 100);

    assert(sys2.getName() == "System2");
    assert(fabs(sys2.getValue() - 120.56) < EPSILON);
}

void unit_system_destructor(void)
{
}

void unit_system_getName(void)
{
    System sys1("System 1 /", 0.0);

    assert(sys1.getName() == "System 1 /");
}

void unit_system_getValue(void)
{
    System sys1("System1", -5);
    System sys2("System2", 0.0);
    System sys3("System3", -8.3);

    assert(sys1.getValue() == -5);
    assert(fabs(sys2.getValue() - 0.0) < EPSILON);
    assert(fabs(sys3.getValue() - (-8.3)) < EPSILON);
}

void unit_system_setValue(void)
{
    System sys1("System1", 0);
    System sys2("System2", 0);
    System sys3("System3", 0);

    sys1.setValue(-5);
    sys2.setValue(0.0);
    sys3.setValue(-8.3);

    assert(sys1.getValue() == -5);
    assert(fabs(sys2.getValue() - 0.0) < EPSILON);
    assert(fabs(sys3.getValue() - (-8.3)) < EPSILON);
}

void run_unit_test_system()
{
    unit_system_constructor();
    unit_system_destructor();
    unit_system_getName();
    unit_system_getValue();
    unit_system_setValue();
}
