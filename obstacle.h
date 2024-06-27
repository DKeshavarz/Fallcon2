#include "point.h"

#include <vector>
#include <string>

#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle{
    public:
        Obstacle();
        virtual ~Obstacle();

        void addEntry(Point);
        bool isEntry(Point)const;

        virtual std::string showCell(Point)const=0;
        virtual bool canCollision(const Point&)const = 0;
        virtual const std::vector<Point> specialEffect(Point)const=0;
        virtual const std::vector<Point> creatFromMap (Point,const std::vector<std::vector<int>>&)=0;

    protected:
        std::vector<Point>& getEntries();
        const std::vector<Point>& constGetEntries()const;

    private:
        std::vector<Point> entries;
};

#endif //OBSTACLE_H