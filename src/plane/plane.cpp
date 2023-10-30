#include "plane.hpp"
#include <iostream>
#include "pilot.hpp"
#include <string>

// CONSTRUCTOR
/*
    used when we want to create a new object
    for example: Plane plane("Boeing 747", 500, 1000, 10000, 100000, "Serban"); -> this will call the constructor
    we dynamically allocate the pilot object because we want to have a pointer to it in the plane object
*/
Plane::Plane(std::string model, int capacity, double maxSpeed, double fuelCapacity, double maxAltitute, std::string pilotName){
    this->model = model;
    this->capacity = capacity;
    this->maxSpeed = maxSpeed;
    this->fuelCapacity = fuelCapacity;
    this->maxAltitute = maxAltitute;
    pilot = new Pilot(pilotName);
}

// COPY CONSTRUCTOR
/*
    used when we want to copy an object
    for example: Plane plane2(plane); where plane already is an existing object -> this will call the copy constructor
*/
Plane::Plane(const Plane &plane){
    this->model = plane.model;
    this->capacity = plane.capacity;
    this->maxSpeed = plane.maxSpeed;
    this->fuelCapacity = plane.fuelCapacity;
    this->maxAltitute = plane.maxAltitute;
    this->pilot = new Pilot(*(plane.pilot));
}

// ASSIGNMENT OPERATOR
/*
    used when we want to assign an object to another
    for example: plane2 = plane; where plane and plane2 already are existing objects -> this will call the assignment operator
*/
Plane& Plane::operator=(const Plane& other) {
    // the case where we assign an object to itself and we want to return the object
    if (this == &other){
        return *this;  
    } 
    // delete the pilot object because it was created with new in the constructor 
    delete this->pilot;
    // here we implement the deep copy logic
    this->pilot = new Pilot(*(other.pilot));
    // here we copy the other fields
    this->model = other.model;
    this->capacity = other.capacity;
    this->maxSpeed = other.maxSpeed;
    this->fuelCapacity = other.fuelCapacity;
    this->maxAltitute = other.maxAltitute;
    // return the object
    return *this;
}

// DESTRUCTOR
/*
    we delete the pilot object because it was created with new in the constructor
    so it is allocated on the heap and not on the stack like the other variables
    and we want to empty the heap memory
    if we don't delete it, we will have a memory leak
*/
Plane::~Plane(){
    std::cout << "Plane " << this->model << " destroyed" << std::endl;
    if(pilot != nullptr){
        delete pilot;
    }
}


// GETTERS
/*
    by using getters and setters we can control the access to the private variables
    so we respect the encapsulation principle
*/
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

// SETTERS
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