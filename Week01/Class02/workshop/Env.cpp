#include "Env.h"

Env::Env()
{
    this->height = 0;
    this->width = 0;

    envStructure = nullptr;
    start = nullptr;
}

Env::Env(int height, int width):
                        height(height),
                        width(width)
{
    this->envStructure = nullptr;
    this->start = nullptr;
}

Env::~Env()
{
    //TODO
}


int Env::getHeight(void) const{
    //this->height = 10;
    return this->height;
}

int Env::getWidth(void){
    return this->width;
}

void Env::setHeight(const int& height){
    this->height = height;
    //height = 10;
}

void Env::setWidth(const int& width){
    this->width = width;
}


//Identify is there are any issues
void Env::setStart(mcpp::Coordinate* start){
    this->start = start;
}


mcpp::Coordinate* Env::getStart(void){
    return this->start;
}

//Identify is there are any issues
void Env::setEnvStructure(char** envStructure){
    this->envStructure = envStructure;
}

char** Env::getEnvStructure(void){
    return this->envStructure;
}

