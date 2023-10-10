#ifndef PATH_H
#define PATH_H

#include <mcpp/mcpp.h>
#include <vector>

class Path
{
public:
    Path();
    ~Path();

    //Adds a node to path
    void pushCoordinate(mcpp::Coordinate loc);

 
    // return the current length of the path
    unsigned int getLength(void);

    /*
    Returns the last coordinate in path and removes it.
    Contract:
            Assume there are nodes in path to pop 
    */
    mcpp::Coordinate popCoordinate(void);

    //Print path
    friend std::ostream& operator<<(std::ostream& os, const Path& p);

private:
    std::vector< mcpp::Coordinate* > savePath;

};

#endif //PATH_H
