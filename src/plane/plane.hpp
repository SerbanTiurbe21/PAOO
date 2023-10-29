#include <string>
#include "pilot.hpp"

class Plane {
    public:
        // constructor
        Plane(std::string model, int capacity, double maxSpeed, double fuelCapacity, double maxAltitute, std::string pilotName);

        // copy constructor
        Plane(const Plane &plane);

        // destructor
        ~Plane();

        // getters
        std::string getModel();
        int getCapacity();
        double getMaxSpeed();
        double getFuelCapacity();
        double getMaxAltitute();
        Pilot* getPilot();
        
        // setters
        void setModel(std::string model);
        void setCapacity(int capacity);
        void setMaxSpeed(double maxSpeed);
        void setFuelCapacity(double fuelCapacity);
        void setMaxAltitute(double maxAltitute);

    private:
        std::string model;
        int capacity;
        double maxSpeed;
        double fuelCapacity;
        double maxAltitute;
        Pilot *pilot;
};