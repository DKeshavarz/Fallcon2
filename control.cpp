#include "control.h"

#include <iostream>

using namespace std;

Control::Control(){

}
int Control::run(){
    
    char ch;

    do{
        ch = this->io.input();

    }while(ch != 'q');

    return 0;
}