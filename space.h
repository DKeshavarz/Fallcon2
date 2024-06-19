#include <vector>
#include <string>

#include "obstacle.h"
#include "spacecraft.h"

#ifndef SPACE_H
#define SPACE_H

class Space{
    public:
        Space();
        ~Space();

        std::string showMap();

    private:
        std::vector<std::vector<Obstacle*>> map;
        std::vector<Spacecraft> spacecrafts;

};

#endif //SPACE_H