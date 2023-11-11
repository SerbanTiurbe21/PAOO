#include "flight-log.hpp"
#include <iostream>

namespace Aviation{
    void FlightLog::addEntry(const std::string& entry){
        logEntries.push_back(entry);
    }

    int FlightLog::getEntryCount(){
        return logEntries.size();
    }

    FlightLog::~FlightLog(){
        std::cout << "FlightLog destructor called" << std::endl;
    }
}