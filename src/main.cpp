#include <iostream>
#include "plane.hpp"
#include "pilot.hpp"
#include <vector>

void menu(){
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Please insert an option from the keyboard: " << std::endl;
    std::cout << "1. Add a new plane" << std::endl;
    std::cout << "2. Add a new pilot" << std::endl;
    std::cout << "3. Get all the planes from the hangar" << std::endl;
    std::cout << "4. Get all the pilots from the hangar" << std::endl; 
    std::cout << "0. Exit" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

// write a function that generates a new plane
Plane generatePlane(std::string model, int capacity, int speed, int fuel, int price, std::string pilotName){
    Plane plane(model, capacity, speed, fuel, price, pilotName);
    return plane;
}

int main(int, char**){
    int option;
    // Plane plane("Boeing 747", 500, 1000, 10000, 100000, "Serban");
    // std::cout << "Plane " << plane.getModel() << " created" << std::endl;
    // Pilot *pilot = plane.getPilot();
    // std::cout << "Pilot " << pilot->getName() << " created" << std::endl;

    // Plane plane2(plane);
    // std::cout << "Plane2 " << plane2.getModel() << " created" << std::endl;

    // Vector of planes (basically the hangar)
    std::vector<Plane> planes;

    // Association of pilots
    std::vector<Pilot> pilots;

    do{
        menu();
        std::cin >> option;
        switch(option){
            case 1:{
                std::cout << "Add a new plane" << std::endl;
                std::string model, pilotName;
                int capacity, speed, fuel, price;
                std::cout << "Model: "<< std::endl;
                std::cin >> model;
                std::cout << "Capacity: "<< std::endl;
                std::cin >> capacity;
                std::cout << "Speed: "<< std::endl;
                std::cin >> speed;
                std::cout << "Fuel: "<< std::endl;
                std::cin >> fuel;
                std::cout << "Price: "<< std::endl;
                std::cin >> price;
                std::cout << "Pilot name: "<< std::endl;
                std::cin >> pilotName;
                Plane plane = generatePlane(model, capacity, speed, fuel, price, pilotName);
                planes.push_back(plane);
            }
            break;
            case 2:{
                std::cout << "Add a new pilot" << std::endl;
                std::string name;
                std::cin >> name;
                Pilot pilot(name);
                pilots.push_back(pilot);
            }
            break;
            case 3:
                std::cout << "Get all the planes from the hangar" << std::endl;
                for(int i = 0; i < planes.size(); i++){
                    std::cout << "Plane " << i << ": " << planes[i].getModel() << std::endl;
                }
            case 4:
                std::cout << "Get all the pilots from the hangar" << std::endl;
                for(int i = 0; i < pilots.size(); i++){
                    std::cout << "Pilot " << i << ": " << pilots[i].getName() << std::endl;
                }
            break;
            case 0:
                std::cout << "Exit" << std::endl;
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    }while(option != 0);
}