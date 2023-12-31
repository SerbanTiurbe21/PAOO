// Include guard
#ifndef PLANE_HPP
#define PLANE_HPP

#include <string>
#include "pilot.hpp"
#include "flight-log.hpp"
#include <memory>

namespace Aviation{
    class Plane {
        public:
            // no-args constructor
            Plane();

            // constructor
            Plane(std::string model, int capacity, double maxSpeed, double fuelCapacity, double maxAltitute, std::string pilotName);

            // copy constructor
            Plane(const Plane &plane);

            // move constructor
            Plane(Plane &&plane);

            // assignment operator
            Plane& operator=(const Plane& other);

            // destructor
            ~Plane();

            // getters
            std::string getModel();
            int getCapacity();
            double getMaxSpeed();
            double getFuelCapacity();
            double getMaxAltitute();
            Pilot* getPilot();
            std::shared_ptr<FlightLog> getFlightLog();
            
            // setters
            void setModel(std::string model);
            void setCapacity(int capacity);
            void setMaxSpeed(double maxSpeed);
            void setFuelCapacity(double fuelCapacity);
            void setMaxAltitute(double maxAltitute);
            void setPilot(std::string pilotName);
            void setFlightLog(std::shared_ptr<FlightLog> log);
            void addFlightLogEntry(std::string entry);

        private:
            std::string model;
            int capacity;
            double maxSpeed;
            double fuelCapacity;
            double maxAltitute;
            /*
                we use unique_ptr because we want to have only one pilot for each plane
                automatic resource management (destructor is called automatically when the plane object is destroyed)
                ownership semantics -> std::unique_ptr expresses exclusive ownership of the object it points to
                safety -> It prevents issues like double deletion and dangling pointers, which can occur with raw pointers.
            */
            std::unique_ptr<Pilot> pilot;
            /*
                we use shared_ptr because we want to have multiple flight logs for each plane
                Multiple Plane objects might share access to the same FlightLog if they are part of the same flight series or operation. 
                In this case, using a std::shared_ptr<FlightLog> would be appropriate.
            */
            std::shared_ptr<FlightLog> flightLog;
    };
}
#endif