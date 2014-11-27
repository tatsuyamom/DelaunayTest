//
//  Defines.cpp
//  Delaunay2
//
//  Created by t_hiroi on 2014/03/13.
//
//

#include "Defines.h"

void Defines::init(){
    std::cout << "init" << std::endl;
    _MODE = 0;
}
void Defines::reset(){
    _MODE = 0;
}
void Defines::setMode(int n){
    _MODE = n;
}
int Defines::getMode(){
    return _MODE;
}

int Defines::_MODE = 0;
bool Defines::_IS_PLAYING = false;
