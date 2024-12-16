#include <mySim.h>
#ifndef MYSIM_CPP
#define MYSIM_CPP


Flow::Flow(){
    this->id = "";
    this->value = 0;
    this->source = nullptr;
    this->target = nullptr;
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

void Flow::associateVariable(System* system){
    this->variables.push_back(system);
}

void Flow::disassociateVariable(System* system){
    for(int i = 0; i < this->variables.size(); i++){
        if(this->variables[i] == system){
            this->variables.erase(this->variables.begin() + i);
            break;
        }
    }
}

void Flow::setValue(double value){
    this->value = value;
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
    for(int i = 0; i < this->totalSteps; i++){
        for(int j = 0; j < this->flows.size(); j++){
            this->flows[j]->getTarget()->setValue(this->flows[j]->getTarget()->getValue() + this->flows[j]->getValue());
            this->flows[j]->getSource()->setValue(this->flows[j]->getSource()->getValue() - this->flows[j]->getValue());
        }
    }
}







#endif