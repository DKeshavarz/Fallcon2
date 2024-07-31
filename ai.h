#include <vector>

#include "obstacle.h"
#include "point.h"

#ifndef AI_H
#define AI_H

class AI {
    public:
        AI();
        void setMap(int,int);
        const std::vector<std::vector<int>>& getMap()const;

        char suggest(std::vector<std::vector<bool>> , std::vector<std::vector<Obstacle*>>,Point);

        void printMap();

        void update(Point);
        int  check (Point);

    private:
        std::vector<std::vector<int>> map;
};

#endif // AI_H