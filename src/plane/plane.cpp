#include "plane.hpp"
#include <iostream>
#include "pilot.hpp"
#include <string>

// constructor
Plane::Plane(std::string model, int capacity, double maxSpeed, double fuelCapacity, double maxAltitute, std::string pilotName){
    this->model = model;
    this->capacity = capacity;
    this->maxSpeed = maxSpeed;
    this->fuelCapacity = fuelCapacity;
    this->maxAltitute = maxAltitute;
    pilot = new Pilot(pilotName);
}

// destructor
Plane::~Plane(){
    std::cout << "Plane " << this->model << " destroyed" << std::endl;
    delete pilot;
}

// getters
std::string Plane::getModel(){
    return this->model;
}

int Plane::getCapacity(){
    return this->capacity;
}

double Plane::getMaxSpeed(){
    return this->maxSpeed;
}

double Plane::getFuelCapacity(){
    return this->fuelCapacity;
}

double Plane::getMaxAltitute(){
    return this->maxAltitute;
}

Pilot* Plane::getPilot(){
    return this->pilot;
}

// setters
void Plane::setModel(std::string model){
    this->model = model;
}

void Plane::setCapacity(int capacity){
    this->capacity = capacity;
}

void Plane::setMaxSpeed(double maxSpeed){
    this->maxSpeed = maxSpeed;
}

void Plane::setFuelCapacity(double fuelCapacity){
    this->fuelCapacity = fuelCapacity;
}

void Plane::setMaxAltitute(double maxAltitute){
    this->maxAltitute = maxAltitute;
}