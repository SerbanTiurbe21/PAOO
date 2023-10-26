#include <iostream>
#include "pilot.hpp"

Pilot::Pilot(std::string name){
    this->name = name;
}

Pilot::~Pilot(){
    std::cout << "Pilot " << this->name << " destroyed" << std::endl;
}

std::string Pilot::getName(){
    return this->name;
}

void Pilot::setName(std::string name){
    this->name = name;
}