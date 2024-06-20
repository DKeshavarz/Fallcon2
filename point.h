#ifndef POINT_H
#define POINT_H
//todo : inline small function
class Point{
    public:
        Point(int=0,int=0);

        int getX();
        int getY();

        void setY(int);
        void setX(int);

        Point operator+(const Point&)const;
    private:
        int x;
        int y;
};

#endif