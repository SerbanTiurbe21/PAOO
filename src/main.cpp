#include <iostream>
#include "plane.hpp"
#include "pilot.hpp"
#include "copilot.hpp"
#include "militaryPlane.hpp"
#include <vector>
#include <list>

using namespace Aviation;

// THE MENU FUNCTION FOR THE USER INTERFACE
void menu(){
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Please insert an option from the keyboard: " << std::endl;
    std::cout << "1. Add a new plane" << std::endl;
    std::cout << "2. Add a new pilot" << std::endl;
    std::cout << "3. Get all the planes from the hangar" << std::endl;
    std::cout << "4. Get all the pilots from the hangar" << std::endl; 
    std::cout << "5. Copy one plane to another using overloaded assignment operator" << std::endl;
    std::cout << "6. Create a new plane based on an existing one using copy constructor" << std::endl;
    std::cout << "7. Add a new military plane" << std::endl;
    std::cout << "8. Transfer a plane to a new owner (demonstrate move constructor)" << std::endl;
    std::cout << "9. Add a new copilot in a list (insertion is more easy - using push_front)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
}

// FUNCTION TO GENERATE A PLANE
Plane generatePlane(std::string model, int capacity, int speed, int fuel, int price, std::string pilotName){
    Plane plane(model, capacity, speed, fuel, price, pilotName);
    return plane;
}

int main(int, char**){
    int option;

    // Vector of planes (basically the hangar)
    std::vector<Plane> planes;
    std::vector<Plane> secondHangar;

    // Association of pilots
    std::vector<Pilot> pilots;
    std::list<Copilot> copilots;

    do{
        menu();
        std::cin >> option;
        switch(option){
            case 1:{
                std::cout << "Add a new plane" << std::endl;
                std::string model, pilotName;
                int capacity, speed, fuel, maxAltitude;
                std::cout << "Model: "<< std::endl;
                std::cin >> model;
                std::cout << "Capacity: "<< std::endl;
                std::cin >> capacity;
                std::cout << "Speed: "<< std::endl;
                std::cin >> speed;
                std::cout << "Fuel: "<< std::endl;
                std::cin >> fuel;
                std::cout << "Max altitude: "<< std::endl;
                std::cin >> maxAltitude;
                std::cout << "Pilot name: "<< std::endl;
                std::cin >> pilotName;
                Plane plane = generatePlane(model, capacity, speed, fuel, maxAltitude, pilotName);
                Pilot pilot = *plane.getPilot();
                planes.push_back(std::move(plane));
                pilots.push_back(pilot);
            }
            break;
            case 2:{
                std::cout << "Add a new pilot" << std::endl;
                std::string name;
                std::cin >> name;
                Pilot pilot(name);
                pilot.performDuties();
                pilots.push_back(pilot);
            }
            break;
            case 3:{
                std::cout << "Get all the planes from the hangar" << std::endl;
                for(int i = 0; i < planes.size(); i++){
                    std::cout << "Plane " << i << ": " << planes[i].getModel() << " " << planes[i].getPilot()->getName() << std::endl;
                }
            }
            break;
            case 4:{
                std::cout << "Get all the pilots from the hangar" << std::endl;
                for(int i = 0; i < pilots.size(); i++){
                    std::cout << "Pilot " << i << ": " << pilots[i].getName() << std::endl;
                }
            }
            break;
            case 5:{
                if(planes.empty()){
                    std::cout << "There are no planes in the hangar." << std::endl;
                    break;
                }

                std::cout << "Copy one plane to another" << std::endl;
                std::cout << "Enter the index of the source plane: ";
                int sourceIndex;
                std::cin >> sourceIndex;
                std::cout << "Enter the index of the destination plane: ";
                int destIndex;
                std::cin >> destIndex;

                if (sourceIndex < 0 || sourceIndex >= planes.size() || destIndex < 0 || destIndex >= planes.size()) {
                    std::cout << "Invalid indices." << std::endl;
                } else {
                    // I want to remove the destination plane from the vector
                    Pilot *pilot = planes[destIndex].getPilot();
                    planes[destIndex] = planes[sourceIndex];
                    std::cout << "Successfully copied the plane." << std::endl;
                }
            }
            break;
            case 6:{
                if(planes.empty()){
                    std::cout << "There are no planes in the hangar." << std::endl;
                    break;
                }

                std::cout << "Create a new plane based on an existing one" << std::endl;
                std::cout << "Enter the index of the source plane: ";
                int sourceIndex;
                std::cin >> sourceIndex;

                if (sourceIndex < 0 || sourceIndex >= planes.size()) {
                    std::cout << "Invalid indices." << std::endl;
                } else {
                    Plane plane = Plane(planes[sourceIndex]);
                    planes.push_back(plane);
                    std::cout << "Successfully copied the plane." << std::endl;
                }
            }
            break;
            case 7:{
                std::cout << "Add a new plane" << std::endl;
                std::string model, pilotName;
                int capacity, speed, fuel, maxAltitude;
                std::cout << "Model: "<< std::endl;
                std::cin >> model;
                std::cout << "Capacity: "<< std::endl;
                std::cin >> capacity;
                std::cout << "Speed: "<< std::endl;
                std::cin >> speed;
                std::cout << "Fuel: "<< std::endl;
                std::cin >> fuel;
                std::cout << "Max altitude: "<< std::endl;
                std::cin >> maxAltitude;
                std::cout << "Pilot name: "<< std::endl;
                std::cin >> pilotName;
                std::cout << "Has bombs? (1/0)" << std::endl;
                bool hasBombs;
                std::cin >> hasBombs;
                std::cout << "Has missiles? (1/0)" << std::endl;
                bool hasMissiles;
                std::cin >> hasMissiles;
                MilitaryPlane plane(model, capacity, speed, fuel, maxAltitude, pilotName, hasBombs, hasMissiles);
                planes.push_back(std::move(plane));
            }
            break;
            case 8:{
                if(planes.empty()){
                    std::cout << "There are no planes in the hangar." << std::endl;
                    break;
                }

                std::cout << "Transfer a plane to another hangar" << std::endl;
                std::cout << "Enter the index of the source plane: ";
                int sourceIndex;
                std::cin >> sourceIndex;

                if (sourceIndex < 0 || sourceIndex >= planes.size()) {
                    std::cout << "Invalid indices." << std::endl;
                } else {
                    secondHangar.push_back(std::move(planes[sourceIndex]));
                    planes.pop_back();
                    std::cout << "Successfully moved the plane." << std::endl;
                    for (int i = 0; i < secondHangar.size(); i++) {
                        std::cout << "Plane " << i << ": " << secondHangar[i].getModel() << " " << secondHangar[i].getPilot()->getName() << std::endl;
                    }
                }
            }
            break;
            case 9:{
                std::cout << "Add a new copilot" << std::endl;
                std::string name, type, status;
                int id;
                std::cout << "Name: "<< std::endl;
                std::cin >> name;
                std::cout << "Id: "<< std::endl;
                std::cin >> id;
                std::cout << "Type: "<< std::endl;
                std::cin >> type;
                std::cout << "Status: "<< std::endl;
                std::cin >> status;
                Copilot copilot(name, id, type, status);
                copilot.performDuties();
                copilots.push_front(copilot);
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