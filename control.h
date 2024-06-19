#ifndef CONTROL_H
#define CONTROL_H

#include "space.h"
#include "io.h"

class Control{
    public:
        Control();

    private:
        Space space;
        Io ioHandeler;
};

#endif //CONTROL_H