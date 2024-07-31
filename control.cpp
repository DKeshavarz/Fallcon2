#include "control.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

const int holdTime = 1500;

Control::Control(){

}
Control::~Control(){
    
}
int Control::run(){
    
    //ch = 'q' - 3;
    char ch;
    try {
        do{
            this->io.output(this->space.showMap());
            std::this_thread::sleep_for(std::chrono::milliseconds(holdTime));
            this->space.moveSpacecraftAI();
            
            //this->io.clear();
            cout << '\n';
            
            
            // try{
            //     if(ch == ' '){
            //         space.specialMoveSpacecraft();
            //     }else{
            //         space.moveSpacecraft(ch);
            //     }
            // }catch(invalid_argument& err){
            //     this->io.output(err.what() + string(1,'\n'));
            // }
            // ch++;
            
        }while(ch != 'q');
    } catch(...){

    }
    
    return 0;
}