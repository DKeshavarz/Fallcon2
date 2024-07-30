#include "control.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

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
                Event event;
        while (window.pollEvent(event))
        {
           if (event.type == Event::Closed)
              window.close();

           if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
              window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprites
        for (const auto& sprite : sprites)
        {
           window.draw(sprite);
        }

        // Update the window
        window.display();
        
    }while(ch != 'q' && window.isOpen());
    
    return 0;
}
