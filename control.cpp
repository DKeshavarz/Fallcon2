#include "control.h"

#include <iostream>

using namespace std;

Control::Control(){

}
int Control::run(){
    
    this->ioHandeler.output(this->space.showMap());

    return 0;
}