#include "Env.h"

Env::Env(int width, int length){
    this->width = width;
    this->length = length;
}

Env::~Env(){

}

int Env::getLength(){
    return this->length;
}
int Env::getWidth(){
    return this->width;
}