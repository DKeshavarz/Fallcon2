#include "obstacle.h"
#include "point.h"

#include <vector>
#include <string>

#ifndef SPACECURRENT_H
#define SPACECURRENT_H

class SpaceCurrent : public Obstacle{
    public:
        SpaceCurrent();
        ~SpaceCurrent();
        void addEntry(Point);
        bool isEntry(Point)const;

        void addLine(Point);
        bool isLine(Point)const;

        std::string showCell(Point)const;

        virtual bool canCollision(const Point&)const ;
        virtual const std::vector<Point> creatFromMap (Point,const std::vector<std::vector<int>>&);
        virtual const std::vector<Point> specialEffect();

    private:
        std::vector<Point> line;

        void dfs(std::vector<Point>& ,std::vector<std::vector<int>>& ,Point);
};

#endif //SPACECURRENT_H