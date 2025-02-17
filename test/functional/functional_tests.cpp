#include "functional_tests.h"

using namespace std;

void exponentialFuncionalTest()
{
    System *pop1 = new SystemImpl("pop1", 100.0);
    System *pop2 = new SystemImpl("pop2", 0.0);

    Flow *exponencial = new Exponencial("Exponencial Flow");

    exponencial->connect(pop1, pop2);

    Model *model = new ModelImpl;
    model->add(pop1);
    model->add(pop2);
    model->add(exponencial);

    model->run(100);

    assert(round((pop1->getValue() - 36.6032) * 10000) == 0);
    assert(round((pop2->getValue() - 63.3968) * 10000) == 0);

    delete pop1;
    delete pop2;
    delete exponencial;
}

void logisticalFuncionalTest()
{
    System *p1 = new SystemImpl("p1", 100.0);
    System *p2 = new SystemImpl("p2", 10.0);

    Logistic *logistic = new Logistic("Logistic Flow", 70);

    logistic->connect(p1, p2);

    Model *model = new ModelImpl();
    model->add(p1);
    model->add(p2);
    model->add(logistic);

    model->run(100);

    assert(round((p1->getValue() - 88.2167) * 10000) == 0);
    assert(round((p2->getValue() - 21.7834) * 10000) == 0);

    delete p1;
    delete p2;
    delete logistic;
}

void complexFuncionalTest()
{
    System *Q1 = new SystemImpl("Q1", 100.0);
    System *Q2 = new SystemImpl("Q2", 0.0);
    System *Q3 = new SystemImpl("Q3", 100.0);
    System *Q4 = new SystemImpl("Q4", 0.0);
    System *Q5 = new SystemImpl("Q5", 0.0);

    Flow *f = new Exponencial("f");
    Flow *g = new Exponencial("g");
    Flow *r = new Exponencial("r");
    Flow *t = new Exponencial("t");
    Flow *u = new Exponencial("u");
    Flow *v = new Exponencial("v");

    f->connect(Q1, Q2);
    t->connect(Q2, Q3);
    u->connect(Q3, Q4);
    v->connect(Q4, Q1);
    g->connect(Q1, Q3);
    r->connect(Q2, Q5);

    Model *model = new ModelImpl;
    model->add(Q1);
    model->add(Q2);
    model->add(Q3);
    model->add(Q4);
    model->add(Q5);
    model->add(f);
    model->add(g);
    model->add(r);
    model->add(t);
    model->add(u);
    model->add(v);

    model->run(100);

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