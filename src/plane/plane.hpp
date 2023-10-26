#include <string>

class Plane {
    public:
        Plane(std::string model, int capacity, double maxSpeed, double fuelCapacity, double maxAltitute);
        std::string getModel();
        int getCapacity();
        double getMaxSpeed();
        double getFuelCapacity();
        double getMaxAltitute();
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
};