#include <vector>
#include <string>

#include "obstacle.h"
#include "spacecraft.h"

#ifndef SPACE_H
#define SPACE_H

class Space{
    public:
        explicit Space(int,int);
        ~Space();

        std::string showMap();
        void moveSpacecraft(char);

    private:
        std::vector<std::vector<Obstacle*>> map;

        std::vector<Spacecraft> spacecrafts;
        int spacecraftIndex {};

};

#endif //SPACE_H