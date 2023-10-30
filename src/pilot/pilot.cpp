#include <iostream>
#include "pilot.hpp"

// CONSTRUCTOR
Pilot::Pilot(std::string name){
    this->name = name;
}

// DESTRUCTOR
Pilot::~Pilot(){
    std::cout << "Pilot " << this->name << " destroyed" << std::endl;
}

// GETTERS AND SETTERS
std::string Pilot::getName(){
    return this->name;
}

void Pilot::setName(std::string name){
    this->name = name;
}