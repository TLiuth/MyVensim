#ifndef UNIT_SYSTEM
#define UNIT_SYSTEM

#include "../../src/systemImpl.h"
#include <vector>
#include <iostream>
#include <assert.h>
#include <cmath>

class unit_system
{
public:
    void unit_system_constructor(void);
    void unit_system_destructor(void);
    void unit_system_getName(void);
    void unit_system_getValue(void);
    void unit_system_setValue(void);
    void run_unit_test_system(void);
};

#endif