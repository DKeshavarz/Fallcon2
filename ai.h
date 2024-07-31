#include <vector>

#ifndef AI_H
#define AI_H

class AI {
    public:
        AI();
        void setMap(int,int);
        const std::vector<std::vector<int>>& getMap()const;

        void printMap();

    private:
        std::vector<std::vector<int>> map;
};

#endif // AI_H