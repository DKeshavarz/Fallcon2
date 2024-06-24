#ifndef CONTROL_H
#define CONTROL_H

#include "space.h"
#include "io.h"

class Control{
    public:
        Control();
        ~Control();

        int run(); //main function 

    private:
        Space space;
        Io io;
};

#endif //CONTROL_H