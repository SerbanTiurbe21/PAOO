#include "crewMember.hpp"
#include <string>   

namespace Aviation{
    class Copilot : public CrewMember{
        public:
            Copilot();
            Copilot(std::string name, int id, std::string type, std::string status);
            ~Copilot();
            void performDuties() override;
            
            void setName(std::string name);
            void setId(int id);
            void setType(std::string type);
            void setStatus(std::string status);

            std::string getName();
            int getId();
            std::string getType();
            std::string getStatus();

        private:
            std::string name;
            int id;
            std::string type;
            std::string status;
    };
}