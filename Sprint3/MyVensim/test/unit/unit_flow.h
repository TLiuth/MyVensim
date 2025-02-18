#ifndef UNIT_FLOW
#define UNIT_FLOW

#include <vector>
#include <iostream>
#include <assert.h>

void unit_flow_constructor(void);
void unit_flow_destructor(void);
void unit_flow_getName(void);
void unit_flow_setSource(void);
void unit_flow_setTarget(void);
void unit_flow_getSource(void);
void unit_flow_getTarget(void);
void unit_flow_connect(void);
void unit_flow_disconnect(void);
void unit_flow_execute(void);

void unit_flow_exponencial_constructor(void);
void unit_flow_exponencial_execute(void);

void unit_flow_logistic_constructor(void);
void unit_flow_logistic_execute(void);

#endif