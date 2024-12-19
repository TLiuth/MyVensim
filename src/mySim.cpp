#include "mySim.h"
#ifndef MYSIM_CPP
#define MYSIM_CPP

// ! Class Flow 

Flow::Flow(){
    this->id = "";
    this->value = 0;
    this->source = nullptr;
    this->target = nullptr;
    this->equation = nullptr;
}

Flow::Flow(const Flow &other){
    this->id = other.id;
    this->value = other.value;
    this->source = other.source;
    this->target = other.target;
}

void Flow::setTarget(System* target){
    this->target = target;
}

void Flow::setSource(System* source){
    this->source = source;
}


void Flow::setValue(double value){
    this->value = value;
} 

void Flow::setEquation(function<double(double, double)> equation){
    this->equation = equation;
}


double Flow::getValue(){
    return this->value;
}

string Flow::getId(){
    return this->id;
}

System* Flow::getSource(){
    return this->source;
}

System* Flow::getTarget(){
    return this->target;
}


void Flow::execute(){
    if(this->equation != nullptr){
        cout << "Source: " << this->source->getValue() << "    Target: " << this->target->getValue() << endl;
        double result = this->equation(this->source->getValue(), this->target->getValue());
        this->target->setValue(this->target->getValue() + result);
        this->source->setValue(this->source->getValue() - result);
    }else{
        this->target->setValue(this->target->getValue() + this->value);
        this->source->setValue(this->source->getValue() - this->value);
    }
}

Flow& Flow::operator=(const Flow &other){

    if(this == &other){
        return *this;
    }

    this->id = other.id;
    this->value = other.value;
    this->source = other.source;
    this->target = other.target;
    return *this;
}

// ! Class System

System::System(){
    this->name = "";
    this->value = 0;
}

System::System(const System &other){
    this->name = other.name;
    this->value = other.value;
}

void System::setName(string name){
    this->name = name;
}

void System::setValue(double value){
    this->value = value;
}

double System::getValue(){
    return this->value;
}

string System::getName(){
    return this->name;
}

System& System::operator=(const System &other){
    if(this == &other){
        return *this;
    }

    this->name = other.name;
    this->value = other.value;
    return *this;
}


// ! Class Simulation

Simulation::Simulation(){
    this->totalSteps = 0;
    this->currentStep = 0;
}

Simulation::Simulation(const Simulation &other){
    this->totalSteps = other.totalSteps;
    this->currentStep = other.currentStep;
    this->flows = other.flows;
    this->systems = other.systems;
}

void Simulation::setSteps(int steps){
    this->totalSteps = steps;
}

int Simulation::getSteps(){
    return this->totalSteps;
}

int Simulation::getCurrentStep(){
    return this->currentStep;
}

void Simulation::addFlow(Flow* flow){
    this->flows.push_back(flow);
}

void Simulation::addSystem(System* system){
    this->systems.push_back(system);
}

vector<Flow*> Simulation::getFlows(){
    return this->flows;
}

vector<System*> Simulation::getSystems(){
    return this->systems;
}

void Simulation::run(){
    cout << "Running simulation" << endl;
    for(int i = 0; i < this->totalSteps; i++){
        cout << "Running Flow " << i << endl;
        for(auto flow : flows){
            flow->execute();
        }
    }
    cout << "Simulation finished" << endl << endl;
}






#endif