#include "obstacle.h"
#include "point.h"

#include <vector>
#include <string>

#ifndef WORMHOLE_H
#define WORMHOLE_H

class WormHole : public Obstacle{
    public:
        WormHole();
        virtual ~WormHole();
        void addEntry(Point);
        bool isEntry(Point);

        std::string showCell(Point);

        virtual const std::vector<Point> creatFromMap (Point,std::vector<std::vector<int>>);
        virtual const std::vector<Point> specialEffect();
    private:
        std::vector<Point> entries;
};

#endif //WORMHOLE_H