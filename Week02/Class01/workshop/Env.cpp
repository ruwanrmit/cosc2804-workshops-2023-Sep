#include "Env.h"

Env::Env()
{
    this->height = 0;
    this->width = 0;

    envStructure = nullptr;
    start = nullptr;
}

Env::Env(unsigned int height, 
        unsigned int width, 
        char** envStructure, mcpp::Coordinate* start):
                        height(height),
                        width(width)
{
    this->envStructure = envStructure;
    this->start = start;
}

Env::Env(const Env& other):
            height(other.height),
            width(other.width)
{
    this->envStructure = other.envStructure;
    this->start =  new mcpp::Coordinate(*(other.start));
}

Env::~Env()
{
    if(envStructure != nullptr){
        for(unsigned int i =0; i < height; i++){
            delete[] envStructure[i];
            envStructure[i] = nullptr;
        }
        delete[] envStructure;
        envStructure = nullptr;
    }

    if(start != nullptr){
        delete start;
        start = nullptr;
    }
}


unsigned int Env::getHeight(void) const {
    return this->height;
}

unsigned int Env::getWidth(void) const {
    return this->width;
}

void Env::setHeight(unsigned int height){
    this->height = height;
}

void Env::setWidth(unsigned int width){
    this->width = width;
}

//Identify is there are any issues
void Env::setStart(mcpp::Coordinate* start){
    if(this->start != nullptr){
        delete start;
    }
    this->start = start;
}

const mcpp::Coordinate* Env::getStart(void) const{
    return this->start;
}

//Identify is there are any issues
void Env::setEnvStructure(char** envStructure){
    this->envStructure = envStructure;
}

char** Env::getEnvStructure(void) const{
    return this->envStructure;
}

