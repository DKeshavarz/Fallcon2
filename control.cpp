#include "control.h"

#include <iostream>

using namespace std;

Control::Control(){

}
int Control::run(){
    
    char ch;

    do{
        this->io.output(this->space.showMap());
        ch = this->io.input();
        this->io.clear();
        

    }while(ch != 'q');

    return 0;
}