#include "point.h"

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

class Spacecraft{
    public:
        Spacecraft();

        Point getPoint();
        void move(char);
        void moveTo(Point);
    private:
        Point location;

};

#endif //SPACECRAFT_H