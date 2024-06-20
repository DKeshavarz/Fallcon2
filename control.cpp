#include "control.h"

#include <iostream>

using namespace std;

Control::Control():space(5,10){

}
int Control::run(){
    
    char ch;

    do{
        this->io.output(this->space.showMap());
        ch = this->io.input();
        this->io.clear();
        space.moveSpacecraft(ch);
        

    }while(ch != 'q');

    return 0;
}