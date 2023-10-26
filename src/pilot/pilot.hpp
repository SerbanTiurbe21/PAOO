#ifndef PILOT_HPP  // Include guard
#define PILOT_HPP

#include <string>

class Pilot{
    public:
        // constructor
        Pilot(std::string name);

        // destructor
        ~Pilot();

        // getters
        std::string getName();

        // setters
        void setName(std::string name);
    private:
        std::string name;
};

#endif