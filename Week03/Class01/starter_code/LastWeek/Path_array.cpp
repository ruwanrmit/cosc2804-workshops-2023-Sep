#include "Path.h"

Path::Path(int maxLength)
{
    savePath = new mcpp::Coordinate*[maxLength];
    for(int i=0; i<maxLength; i++){
        savePath[i] = nullptr;
    }
    length = 0;
    this->maxLength = maxLength;
}

Path::~Path()
{
    for(int i = 0; i<length; i++){
        delete savePath[i];
    }
    delete[] savePath;
}


void Path::pushCoordinate(mcpp::Coordinate loc){
    if (length < maxLength){
        savePath[length] = new mcpp::Coordinate(loc.x, loc.y, loc.z);
        length++;
    }
}

mcpp::Coordinate Path::popCoordinate(void){
    mcpp::Coordinate retCoord(0,0,0);
    if(length > 0){
        retCoord.x = savePath[length-1]->x;
        retCoord.y = savePath[length-1]->y;
        retCoord.z = savePath[length-1]->z;

        delete savePath[length-1];
        savePath[length-1] = nullptr;
        length--;
    }

    return retCoord;
}

int Path::getLength(void){
    return this->length;
}


std::ostream& operator<<(std::ostream& os, const Path& p){
    os << "Path has " << p.length << " nodes." << std::endl;
    for(int i = 0; i < p.length; i++){
        os << "[" << i << "] \t :" << *(p.savePath[i]) << std::endl; 
    }

    return os;
}