#ifndef ENV
#define ENV

#include <mcpp/mcpp.h>

/*
The implimentation of the class below has some issues. 
We will be fixing along the way. Do not assume correctness.
*/


class Env
{
public:
    //constructors and deconstructors
    Env();

    //Contract:
    // height and width must be integers greater than zero
    Env(int height, int width);
    ~Env();

    //other methods
    int getHeight(void) const;
    int getWidth(void);

    void setHeight(const int& height);
    void setWidth(const int& width);

    void setStart(mcpp::Coordinate* start);
    mcpp::Coordinate* getStart(void);

    void setEnvStructure(char** envStructure);
    char** getEnvStructure(void);



private:
    /* data */
    int height;
    int width;

    mcpp::Coordinate* start;

    char** envStructure;

};

#endif //ENV