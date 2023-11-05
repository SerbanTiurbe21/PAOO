#include "militaryPlane.hpp"
#include <iostream>

namespace Aviation{
    // Constructor
    MilitaryPlane::MilitaryPlane(std::string model, 
                                int capacity,
                                double maxSpeed,
                                double fuelCapacity, 
                                double maxAltitude, 
                                std::string pilotName,
                                bool hasBombs, 
                                bool hasMissiles) : Plane(model, capacity, maxSpeed, fuelCapacity, maxAltitude, pilotName){this->hasBombs = hasBombs; this->hasMissiles = hasMissiles;}

    // Destructor
    MilitaryPlane::~MilitaryPlane() {
        std::cout << "Military plane " << this->getModel() << " destroyed" << std::endl;
    }

    // Other member functions
    void MilitaryPlane::dropBombs() {
        if (hasBombs) {
            std::cout << "Dropping bombs...\n";
        } else {
            std::cout << "No bombs to drop.\n";
        }
    }

    void MilitaryPlane::fireMissiles() {
        if (hasMissiles) {
            std::cout << "Firing missiles...\n";
        } else {
            std::cout << "No missiles to fire.\n";
        }
    }
}