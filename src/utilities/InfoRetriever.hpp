#include <iostream>

namespace Aviation{
    template <typename T>
    double getMetersToInternationalSpaceStation(T plane){
        return (408000 - plane.getMaxAltitute()); 
    }
}