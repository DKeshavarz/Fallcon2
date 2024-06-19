#ifndef POINT_H
#define POINT_H

class Point{
    public:
        Point(int=0,int=0);

        int getX();
        int getY();

        void setY(int);
        void setX(int);
    private:
        int x;
        int y;
};

#endif