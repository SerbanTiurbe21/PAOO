#include "plane.hpp"
#include <iostream>
#include "pilot.hpp"
#include <string>

// DEFAULT CONSTRUCTOR
Plane::Plane(){
    this->model = "";
    this->capacity = 0;
    this->maxSpeed = 0;
    this->fuelCapacity = 0;
    this->maxAltitute = 0;
    pilot = new Pilot("");
}

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
    in our copy constructor we use deep copy because we specifically create a new Pilot object on the heap and we copy the content from the source Plane object's Pilot into it.
    if we would have used shallow copy, we would have copied the address of the source Plane object's Pilot into the destination Plane object's Pilot.
    shallow copy is applied only if we have no dynamic memory allocation in the class 

    shallow copy: we copy the address of the pilot object from plane to plane2 -> we use shallow copy when we want to have 2 planes with the same address 
    deep copy: we copy the pilot object from plane to plane2 -> in here we use deep copy because we want to have 2 different planes with different addresses
*/
/*
    In a shallow copy, the data members of one object are copied into the data members of another object without duplicating heap-allocated memory.
    So if we change the data members of one object, the data members of the other object will also change.

    In a deep copy, the data members of one object are copied into the data members of another object along with duplicating heap-allocated memory.
    So if we change the data members of one object, the data members of the other object will not change.  
*/
Plane::Plane(const Plane &plane){
    this->model = plane.model;
    this->capacity = plane.capacity;
    this->maxSpeed = plane.maxSpeed;
    this->fuelCapacity = plane.fuelCapacity;
    this->maxAltitute = plane.maxAltitute;
    this->pilot = new Pilot(*(plane.pilot));
}

// MOVE CONSTRUCTOR
/*
    used when we want to move an object
    for example: Plane plane2(std::move(plane)); where plane already is an existing object -> this will call the move constructor
    we use std::move to move the object
    we use it to avoid copying the object and be more efficient
    we use it when we want to move the object to another object and we don't need the object anymore
    we use it when we want to add the object to a collection 
*/
Plane::Plane(Plane &&plane){
    // here we use std::move beacause the model is a string and we want to move it
    this->model = std::move(plane.model);
    this->capacity = plane.capacity;
    this->maxSpeed = plane.maxSpeed;
    this->fuelCapacity = plane.fuelCapacity;
    this->maxAltitute = plane.maxAltitute;
    this->pilot = plane.pilot;
    plane.pilot = nullptr;

    std::cout << "Move constructor called for plane: " << this->model << std::endl;
}
// ASSIGNMENT OPERATOR
/*
    used when we want to assign an object to another
    for example: plane2 = plane; where plane and plane2 already are existing objects -> this will call the assignment operator
    we use & to get the address of the object
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

void Plane::setPilot(Pilot *pilot){
    this->pilot = pilot;
}