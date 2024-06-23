#include "point.h"
#include <vector>
#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle{
    public:
        Obstacle();
        virtual ~Obstacle();

        virtual const std::vector<Point> specialEffect()=0;
            
    private:
};

#endif //OBSTACLE_H