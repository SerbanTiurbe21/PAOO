#include "copilot.hpp"
#include <iostream>

namespace Aviation{

    Copilot::Copilot(){
        this->name = "";
        this->id = 0;
        this->type = "";
        this->status = "";
    }

    Copilot::Copilot(std::string name, int id, std::string type, std::string status){
        this->name = name;
        this->id = id;
        this->type = type;
        this->status = status;
    }
    
    Copilot::~Copilot(){}

    void Copilot::performDuties(){
        std::cout << this->getName() << " is performing copilot duties" << std::endl;
    }

    // GETTERS AND SETTERS
    std::string Copilot::getName(){
        return this->name;
    }

    void Copilot::setName(std::string name){
        this->name = name;
    }

    int Copilot::getId(){
        return this->id;
    }

    void Copilot::setId(int id){
        this->id = id;
    }

    std::string Copilot::getType(){
        return this->type;
    }

    void Copilot::setType(std::string type){
        this->type = type;
    }

    std::string Copilot::getStatus(){
        return this->status;
    }

    void Copilot::setStatus(std::string status){
        this->status = status;
    }
}