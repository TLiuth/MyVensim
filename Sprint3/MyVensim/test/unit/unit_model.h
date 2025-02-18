#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

void unit_model_constructor(void);
void unit_model_destructor(void);
void unit_model_add(void);
void unit_model_run(void);
void unit_model_remove(void);
void unit_model_getSystems(void);
void unit_model_getFlows(void);
void run_unit_test_model(void);

#endif