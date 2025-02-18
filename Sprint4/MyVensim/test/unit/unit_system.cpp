#include "unit_system.h"

#define EPSILON 0.0001

void unit_system::unit_system_constructor(void)
{
    SystemImpl sys1("System1", 100);
    SystemImpl sys2("System2", 120.56);

    assert(sys1.name == "System1");
    assert(sys1.value == 100);

    assert(sys2.name == "System2");
    assert(fabs(sys2.value - 120.56) < EPSILON);
}

void unit_system::unit_system_destructor(void)
{
}

void unit_system::unit_system_getName(void)
{
    SystemImpl sys("", 0.0);

    sys.name = "System 1 /";

    assert(sys.getName() == "System 1 /");
}

void unit_system::unit_system_getValue(void)
{

    SystemImpl sys1("System", 0);
    SystemImpl sys2("System", 0);
    SystemImpl sys3("System", 0);

    sys1.value = -5;
    sys2.value = 0.0;
    sys3.value = -8.3;

    assert(sys1.getValue() == -5);
    assert(fabs(sys2.getValue() - 0.0) < EPSILON);
    assert(fabs(sys3.getValue() - (-8.3)) < EPSILON);
}

void unit_system::unit_system_setValue(void)
{
    SystemImpl sys1("System", 0);
    SystemImpl sys2("System", 0);
    SystemImpl sys3("System", 0);

    sys1.setValue(-5);
    sys2.setValue(0.0);
    sys3.setValue(-8.3);

    assert(sys1.value == -5);
    assert(fabs(sys2.value - 0.0) < EPSILON);
    assert(fabs(sys3.value - (-8.3)) < EPSILON);
}

void unit_system::run_unit_test_system()
{
    unit_system_constructor();
    unit_system_destructor();
    unit_system_getName();
    unit_system_getValue();
    unit_system_setValue();
}