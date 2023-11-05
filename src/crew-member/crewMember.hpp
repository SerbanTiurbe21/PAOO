#ifndef CREWMEMBER_HPP
#define CREWMEMBER_HPP

namespace Aviation {

class CrewMember {
    public:
        // destructor
        virtual ~CrewMember() {}

        // A pure virtual method that must be implemented by derived classes
        virtual void performDuties() = 0;
    };
}

#endif // CREWMEMBER_HPP