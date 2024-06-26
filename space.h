#include <vector>
#include <string>
#include <memory>

#include "obstacle.h"
#include "spacecraft.h"

#ifndef SPACE_H
#define SPACE_H

class Space{
    public:
        explicit Space(int,int);
        Space();
        ~Space();

        std::string showMap()const;
        void moveSpacecraft(char);
        void specialMoveSpacecraft();

        void loadMap();

    private:
        std::vector<std::vector<std::shared_ptr<Obstacle>>> map;

        std::vector<Spacecraft> spacecrafts;
        int spacecraftIndex {};
        const std::string fileName {"input.txt"};

        //function
        void addObstacle(std::vector<std::vector<int>>);
        const Obstacle* const getCell(const Point&);
        bool isOnMap(const Point&);
        bool isOnMap(int,int);


};

#endif //SPACE_H