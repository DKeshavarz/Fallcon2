#include "io.h"

#include <iostream>
#include <string>

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