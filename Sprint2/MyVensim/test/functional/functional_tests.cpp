#include <iostream>
#include <cassert>
#include <cmath>
#include "../../src/flow.h"
#include "../../src/model.h"
#include "../../src/system.h"

using namespace std;

void exponentialFuncionalTest()
{
    System *pop1 = new System("pop1", 100.0);
    System *pop2 = new System("pop2", 0.0);

    Exponencial *exponencial = new Exponencial("Exponencial Flow");

    exponencial->connect(pop1, pop2);

    Model model;
    model.add(pop1);
    model.add(pop2);
    model.add(exponencial);

    model.run(100);

    assert(round((pop1->getValue() - 36.6032) * 10000) == 0);
    assert(round((pop2->getValue() - 63.3968) * 10000) == 0);

    delete pop1;
    delete pop2;
    delete exponencial;
}

void logisticalFuncionalTest()
{
    System *p1 = new System("p1", 100.0);
    System *p2 = new System("p2", 10.0);

    Logistic *logistic = new Logistic("Logistic Flow", 70);

    logistic->connect(p1, p2);

    Model model;
    model.add(p1);
    model.add(p2);
    model.add(logistic);

    model.run(100);

    assert(round((p1->getValue() - 88.2167) * 10000) == 0);
    assert(round((p2->getValue() - 21.7834) * 10000) == 0);

    delete p1;
    delete p2;
    delete logistic;
}

void complexFuncionalTest()
{
    System *Q1 = new System("Q1", 100.0);
    System *Q2 = new System("Q2", 0.0);
    System *Q3 = new System("Q3", 100.0);
    System *Q4 = new System("Q4", 0.0);
    System *Q5 = new System("Q5", 0.0);

    Exponencial *f = new Exponencial("f");
    Exponencial *g = new Exponencial("g");
    Exponencial *r = new Exponencial("r");
    Exponencial *t = new Exponencial("t");
    Exponencial *u = new Exponencial("u");
    Exponencial *v = new Exponencial("v");

    f->connect(Q1, Q2);
    t->connect(Q2, Q3);
    u->connect(Q3, Q4);
    v->connect(Q4, Q1);
    g->connect(Q1, Q3);
    r->connect(Q2, Q5);

    Model model;
    model.add(Q1);
    model.add(Q2);
    model.add(Q3);
    model.add(Q4);
    model.add(Q5);
    model.add(f);
    model.add(g);
    model.add(r);
    model.add(t);
    model.add(u);
    model.add(v);

    model.run(100);

    assert(round((Q1->getValue() - 31.8513) * 10000) == 0);
    assert(round((Q2->getValue() - 18.4003) * 10000) == 0);
    assert(round((Q3->getValue() - 77.1143) * 10000) == 0);
    assert(round((Q4->getValue() - 56.1728) * 10000) == 0);
    assert(round((Q5->getValue() - 16.4612) * 10000) == 0);

    delete Q1;
    delete Q2;
    delete Q3;
    delete Q4;
    delete Q5;
    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;
}
