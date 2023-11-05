#include <iostream>
#include "pilot.hpp"

namespace Aviation{
    // CONSTRUCTOR
    Pilot::Pilot(std::string name){
        this->name = name;
    }

    // DESTRUCTOR
    Pilot::~Pilot(){
        std::cout << "Pilot " << this->name << " destroyed" << std::endl;
    }

    void Pilot::performDuties() {
        std::cout << this->getName() << " is performing duties as a pilot." << std::endl;
    }

    // GETTERS AND SETTERS
    std::string Pilot::getName(){
        return this->name;
    }

    void Pilot::setName(std::string name){
        this->name = name;
    }
}