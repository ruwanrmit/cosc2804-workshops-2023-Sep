#ifndef AGENT_H
#define AGENT_H
#include <mcpp/mcpp.h>
#include "Path.h"

class Agent
{

public:
    
    // Initialize an agent with ID at a given location.
    // Will move the agent to the location in Minecraft world
    Agent(unsigned int id, mcpp::Coordinate location);
    ~Agent();

    //Move the agent randomly to one of the reachable adjacent blocks. 
    //An adjacent cell is one within 1 unit in the x and y direction.
    // reachable if the cell is not more that 1 unit high to the current loc.
    // if no reachable locations, then returns false else returns true. 
    bool randomStep(void);

    //Check the immediate neighbourhood for a given type of block
    //If the block is found, then treasureCoord is updated.
    // Contract:
    //    only finds one instance in case there are multiple blocks in the neighbourhood.
    //    no change to treasure coord if block not found.
    bool isBlockInNeighborhood(mcpp::BlockType block, mcpp::Coordinate& treasureCoord);

    void printPath(void);

    // Print agent ID and current location to output stream
    friend std::ostream& operator<<(std::ostream& os, const Agent& f);

private:
    // data
    unsigned int id;
    mcpp::Coordinate location;
    Path* path;

    //private methods
    bool checkMove(mcpp::Coordinate next);
};

#endif //AGENT_H


