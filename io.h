#include <string>

#ifndef IO_H
#define IO_H

class Io {
    public:
        Io();

        void output(const std::string&);
        char input();
        void clear();

    private:

};

#endif