#include "flight-log.hpp"

namespace Aviation{
    void FlightLog::addEntry(const std::string& entry){
        logEntries.push_back(entry);
    }
}