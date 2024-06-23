#include "obstacle.h"
#include "point.h"

#include <vector>
#include <string>

#ifndef SPACECURRENT_H
#define SPACECURRENT_H

class SpaceCurrent : public Obstacle{
    public:
        void addEntry(Point);
        bool isEntry(Point);

        void addLine(Point);
        bool isLine(Point);

        std::string showCell(Point);

    private:
        std::vector<Point> entries;
        std::vector<Point> line;
};

#endif //SPACECURRENT_H