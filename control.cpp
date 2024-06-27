#include "control.h"

#include <iostream>

using namespace std;

Control::Control(){

}
Control::~Control(){
    
}
int Control::run(){
   
    char ch;
    do{
        this->io.output(this->space.showMap());
        ch = this->io.input();
        this->io.clear();
        
        try{
            if(ch == ' '){
                space.specialMoveSpacecraft();
            }else{
                space.moveSpacecraft(ch);
            }
        }catch(invalid_argument& err){
            this->io.output(err.what() + string(1,'\n'));
        }
        
    }while(ch != 'q');
    
    return 0;
}