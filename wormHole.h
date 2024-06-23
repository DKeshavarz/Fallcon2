#include "obstacle.h"
#include "point.h"

#include <vector>
#include <string>

#ifndef WORMHOLE_H
#define WORMHOLE_H

class WormHole : public Obstacle{
    public:
        void addEntry(Point);
        bool isEntry(Point);

        std::string showCell(Point);
    private:
        std::vector<Point> entries;
};

#endif //WORMHOLE_H