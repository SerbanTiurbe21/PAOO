#include "plane.hpp"

namespace Aviation {
    class MilitaryPlane : public Plane {
        public:
            // Constructor
            MilitaryPlane(std::string model, 
                        int capacity,
                        double maxSpeed,
                        double fuelCapacity, 
                        double maxAltitude, 
                        std::string pilotName,
                        bool hasBombs, 
                        bool hasMissiles);

            // Destructor
            ~MilitaryPlane();

            // Other member functions
            void dropBombs();
            void fireMissiles();

        private:
            bool hasBombs;
            bool hasMissiles;
        };    
}