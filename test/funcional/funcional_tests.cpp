#include "funcional_tests.h"
#include <cassert>
#include <cmath>
#include "../../src/mySim.h"


void exponentialFuncionalTest(){
    System s1;
    s1.setName("pop1");
    s1.setValue(100);
    System s2;
    s2.setName("pop2");
    s2.setValue(0);

    Flow f1;
    f1.setSource(&s1);
    f1.setTarget(&s2);

    Simulation sim;
    sim.setSteps(100);

    sim.addFlow(&f1);
    sim.addSystem(&s1);
    sim.addSystem(&s2);

    f1.setEquation([](double pop1, double y){
        return pop1 * 0.01;
    });

    sim.run(); 

    assert(fabs(s1.getValue() == 36.6032) < EPSILON);
    assert(fabs(s2.getValue() == 63.3968) < EPSILON);

}

void logisticFuncionalTest(){
    Simulation sim;
    sim.setSteps(100);

    System s1;
    s1.setName("p1");
    s1.setValue(100);
    System s2;
    s2.setName("p2");
    s2.setValue(10);

    Flow f1;
    f1.setSource(&s1);
    f1.setTarget(&s2);
    f1.setEquation([](double p1, double p2){
        return 0.01*p2*(1-p2/70);
    });


    sim.addFlow(&f1);
    sim.addSystem(&s1);
    sim.addSystem(&s2);

    sim.run();

    assert(fabs(s1.getValue() - 88.2167) < EPSILON);
    assert(fabs(s2.getValue() - 21.7833) < EPSILON);


}


void complexFuncionalTest(){
    Simulation sim;
    sim.setSteps(100);

    System q1, q2, q3, q4, q5;
    q1.setName("q1");
    q1.setValue(100);
    q2.setName("q2");
    q2.setValue(0);
    q3.setName("q3");
    q3.setValue(100);
    q4.setName("q4");
    q4.setValue(0);
    q5.setName("q5");
    q5.setValue(0);

    Flow f, g, r, t, u, v;

    f.setSource(&q1);
    f.setTarget(&q2);

    g.setSource(&q1);
    g.setTarget(&q3);

    r.setSource(&q2);
    r.setTarget(&q5);

    t.setSource(&q2);
    t.setTarget(&q3);

    u.setSource(&q3);
    u.setTarget(&q4);

    v.setSource(&q4);
    v.setTarget(&q1);

    f.setEquation([](double source, double target){
        return 0.01*source;
    });
    g.setEquation([](double source, double target){
        return 0.01*source;
    });
    r.setEquation([](double source, double target){
        return 0.01*source;
    });
    t.setEquation([](double source, double target){
        return 0.01*source;
    });
    u.setEquation([](double source, double target){
        return 0.01*source;
    });
    v.setEquation([](double source, double target){
        return 0.01*source;
    });

    sim.addFlow(&f);
    sim.addFlow(&g);
    sim.addFlow(&r);
    sim.addFlow(&t);
    sim.addFlow(&u);
    sim.addFlow(&v);
    
    sim.addSystem(&q1);
    sim.addSystem(&q2);
    sim.addSystem(&q3);
    sim.addSystem(&q4);
    sim.addSystem(&q5);

    sim.run();

    assert(fabs(q1.getValue() - 31.8513) < EPSILON);
    assert(fabs(q2.getValue() - 18.4003) < EPSILON);
    assert(fabs(q3.getValue() - 77.1143) < EPSILON);
    assert(fabs(q4.getValue() - 56.1728) < EPSILON);
    assert(fabs(q5.getValue() - 16.4612) < EPSILON);


}