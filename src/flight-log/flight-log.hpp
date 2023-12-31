#ifndef FLIGHTLOG_HPP
#define FLIGHTLOG_HPP

#include <string>
#include <vector>

namespace Aviation{
    class FlightLog{
        private:
            std::vector<std::string> logEntries;
        public:
            void addEntry(const std::string& entry);
            int getEntryCount();
            ~FlightLog();
    };
}

#endif // FLIGHTLOG_HPP