#include <iostream>
#include <vector>
using namespace std;   

#ifndef MYSIM_H
#define MYSIM_H

class Flow{
    private:
        string id;
        double value;
        System* source;
        System* target;
    public:
        Flow();
        Flow(const Flow &other){};
        void setTarget(System* target);
        void setSource(System* source);
        void associateVariable(System* system);
        void disassociateVariable(System* system);
        void setValue(double value);
        double getValue();
        string getId();
        System* getSource();
        System* getTarget();

        Flow operator=(const Flow &other){
            this->id = other.id;
            this->value = other.value;
            this->source = other.source;
            this->target = other.target;
            return *this;
        }
};

class System{
    private:
        string name;
        double value;
    public:
        System();
        System(const System &other);
        void setName(string name);
        void setValue(double value);
        double getValue();
        string getName();

        System operator=(const System &other){
            this->name = other.name;
            this->value = other.value;
            return *this;
        }
};

class Simulation{
    private:
        int totalSteps;
        int currentStep;
        vector<Flow*> flows;
        vector<System*> systems;
    public:
        Simulation();
        Simulation(const Simulation &other);
        void setSteps(int steps);
        int getSteps();
        int getCurrentStep();
        void addFlow(Flow* flow);
        void addSystem(System* system);
        void getFlows();
        void getSystems();
        void run();

        Simulation operator=(const Simulation &other){
            this->totalSteps = other.totalSteps;
            this->currentStep = other.currentStep;
            this->flows = other.flows;
            this->systems = other.systems;
            return *this;
        }
}






#endif