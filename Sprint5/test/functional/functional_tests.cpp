#include "functional_tests.h"

using namespace std;

// ! Como resolver a necessidade de incluir o FlowImpl (Exponencial e Logistic) para a criação de um Flow?

void exponentialFuncionalTest()
{
    Model& model = Model::createModel();

    System &pop1 = model.createSystem("pop1", 100);
    System &pop2 = model.createSystem("pop2", 0);

    model.createFlow<Exponencial>("exponencialFlow", &pop1, &pop2);

    model.run(100);

    assert(round((pop1.getValue() - 36.6032) * 10000) == 0);
    assert(round((pop2.getValue() - 63.3968) * 10000) == 0);

    delete &model;
}

void logisticalFuncionalTest()
{
    Model& model = Model::createModel();

    System &p1 = model.createSystem("p1", 100.0);
    System &p2 = model.createSystem("p2", 10.0);

    model.createFlow<Logistic>("Logistic Flow", &p1, &p2, 70);

    model.run(100);

    assert(round((p1.getValue() - 88.2167) * 10000) == 0);
    assert(round((p2.getValue() - 21.7834) * 10000) == 0);

    delete &model;
}

void complexFuncionalTest()
{
    Model& model = Model::createModel();
    
    System &Q1 = model.createSystem("Q1", 100.0);
    System &Q2 = model.createSystem("Q2", 0.0);
    System &Q3 = model.createSystem("Q3", 100.0);
    System &Q4 = model.createSystem("Q4", 0.0);
    System &Q5 = model.createSystem("Q5", 0.0);
    
    model.createFlow<Exponencial>("f", &Q1, &Q2);
    model.createFlow<Exponencial>("g", &Q1, &Q3);
    model.createFlow<Exponencial>("r", &Q2, &Q5);
    model.createFlow<Exponencial>("t", &Q2, &Q3);
    model.createFlow<Exponencial>("u", &Q3, &Q4);
    model.createFlow<Exponencial>("v", &Q4, &Q1);

    model.run(100);

    assert(round((Q1.getValue() - 31.8513) * 10000) == 0);
    assert(round((Q2.getValue() - 18.4003) * 10000) == 0);
    assert(round((Q3.getValue() - 77.1143) * 10000) == 0);
    assert(round((Q4.getValue() - 56.1728) * 10000) == 0);
    assert(round((Q5.getValue() - 16.4612) * 10000) == 0);

    delete &model;
}