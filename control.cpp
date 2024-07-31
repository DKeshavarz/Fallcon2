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
    RenderWindow window(VideoMode::getDesktopMode(), "Tile Map", Style::Fullscreen);

    // Load textures
    Texture inter; // 1
    inter.loadFromFile("inter.png");
    //return -1; // error

    Texture pipe; // 2
    pipe.loadFromFile("pipe.png");
    // return -1; // error

    Texture mars; // 3
    mars.loadFromFile("mars.png");
    // return -1; // error

    Texture portal; // 4
    portal.loadFromFile("portal.png");
    //return -1; // err

    Texture ship; // *
    ship.loadFromFile("ship.png");
    // return -1; // error

    Texture Space; // 0 +
    Space.loadFromFile("space.png");
    //return -1; // error

// Calculate the number of rows and columns in the output
    int rows = 1;
    int cols = 0;
    for (char c : output)
    {
        if (c == '\n')
        {
            rows++;
        }
        else if (rows == 1)
        {
            cols++;
        }
    }

    // Calculate the size of each tile to fit the window
    Vector2u windowSize = window.getSize();
    float tileWidth = static_cast<float>(windowSize.x) / cols;
    float tileHeight = static_cast<float>(windowSize.y) / rows;

    // Vector to hold the sprites
    vector<Sprite> sprites;

    // Parse the map string and create sprites
    int x = 0;
    int y = 0;
    for (char c : output)
    {
        if (c == '\n')
        {
            x = 0;
            y++;
            continue;
        }

        Sprite sprite;
        if (c == '1')
        {
            sprite.setTexture(inter);
        }
        else if (c == '2')
        {
            sprite.setTexture(pipe);
        }
        else if (c == '3')
        {
            sprite.setTexture(mars);
        }
        else if (c == '4')
        {
            sprite.setTexture(portal);
        }
        else if (c == '*')
        {
            sprite.setTexture(ship);
        }
        else
        {
            sprite.setTexture(Space);
        }

        // Set the scale of the sprite to fit the tile size
        sprite.setScale(
            tileWidth / sprite.getTexture()->getSize().x,
            tileHeight / sprite.getTexture()->getSize().y
        );
        sprite.setPosition(x * tileWidth, y * tileHeight);
        sprites.push_back(sprite);

        x++;
    }
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
