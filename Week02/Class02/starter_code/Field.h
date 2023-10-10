#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <mcpp/mcpp.h>

#define WALL_HEIGHT 5

class Field
{
public:
    // Constructs a field by building concrete walls in a Minecraft world at a 
    //     given basepoint with sides equal to xLength and zLength. 
    // Sets the treasure (Gold) at a random location within the field. 
    //Contract:
    //  Expect the field to be on land 
    //  and to be larger than 4 blocks in width and height
    Field(mcpp::Coordinate basePoint, unsigned int xLength, unsigned int zLength);
    
    // Delete the walls and the treasure from Minecraft world.
    ~Field();

    // Delete the existing walls and treasure and rebuild
    void resetField(void);

    // Provide a random location within the field
    mcpp::Coordinate getStartLocation(void) const;
    
    // Create an osstream with the parameters of a given Field
    friend std::ostream& operator<<(std::ostream& os, const Field& f);

private:

    // Data
    mcpp::Coordinate basePoint;
    unsigned int xLength;
    unsigned int zLength;
    mcpp::Coordinate treasureLoc;

    //private methods
    void BuildFence(mcpp::MinecraftConnection& mc);
    void eraseField();
    void SetupField(void);
};

#endif //FIELD_H