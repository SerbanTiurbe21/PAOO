#include <iostream>
#include "plane.hpp"
#include "pilot.hpp"

int main(int, char**){
    Plane plane("Boeing 747", 500, 1000, 10000, 100000, "Serban");
    std::cout << "Plane " << plane.getModel() << " created" << std::endl;
    Pilot *pilot = plane.getPilot();
    std::cout << "Pilot " << pilot->getName() << " created" << std::endl;
}