// Include guard
#ifndef PILOT_HPP
#define PILOT_HPP

#include <string>
#include "crewMember.hpp"

namespace Aviation{
    class Pilot : public CrewMember{
        public:
            // constructor
            Pilot(std::string name);

            // destructor
            ~Pilot();

            // methods from CrewMember
            void performDuties() override;

            // getters
            std::string getName();

            // setters
            void setName(std::string name);
        private:
            std::string name;
    };    
}

#endif