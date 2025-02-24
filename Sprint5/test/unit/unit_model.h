#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/modelImpl.h"
#include "../../src/flowImpl.h"
#include "../../src/systemImpl.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class unit_model
{
public:
    void unit_model_constructor(void);
    void unit_model_destructor(void);
    void unit_model_add(void);
    void unit_model_run(void);
    void unit_model_remove(void);
    void unit_model_iterator_flow(void);
    void unit_model_iterator_system(void);
    void run_unit_test_model(void);
};

#endif