#include "io.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#ifdef _WIN32
    #include <conio.h>
#elif __linux__
    #include <stdio.h>  
#else
    #error "Unsupported operating system"
#endif

using namespace std;

Io::Io(){
    
}
void Io::output(const string& output){
    cout << output ;
     // Create the main window in fullscreen mode
    RenderWindow window(VideoMode::getDesktopMode(), "Tile Map", Style::Fullscreen);

    // Load textures
    Texture inter; // 1
    if (!inter.loadFromFile("inter.png"))
        return -1; // error

    Texture pipe; // 2
    if (!pipe.loadFromFile("pipe.png"))
        return -1; // error

    Texture mars; // 3
    if (!mars.loadFromFile("mars.png"))
        return -1; // error

    Texture portal; // 4
    if (!portal.loadFromFile("portal.png"))
        return -1; // error

    Texture ship; // *
    if (!ship.loadFromFile("ship.png"))
        return -1; // error

    Texture space; // 0 +
    if (!space.loadFromFile("space.png"))
        return -1; // error
    
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
            sprite.setTexture(space);
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
}
char Io::input(){
    char input;

    #ifdef _WIN32
        input = _getch();
    #else
        system("stty raw"); 
        input = getchar(); 
        system("stty cooked"); 
    #endif
        

  
    return input; 
}
void Io::clear(){
    system("CLS || clear");
}
