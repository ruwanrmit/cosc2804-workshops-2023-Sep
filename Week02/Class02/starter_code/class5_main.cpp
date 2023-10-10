#include <iostream>
#include <exception>
#include <random>
#include <chrono>
#include <thread>

#include <mcpp/mcpp.h>

#include "Utils.h"
#include "Field.h"
#include "Agent.h"
#include "Path.h"

#define MAX_ITER 1000

void someDelay(void);

int main(void){

    

    try{
        //Read the length and width
        unsigned int xLength = 0;
        unsigned int zLength = 0;

        mcpp::Coordinate basePoint(0,0,0);

        //Read the field parameters
        bool retVal = false;
        while (!retVal)
        {
            retVal = ReadFieldParameters(basePoint, xLength, zLength);
            if(!retVal){
                std::cout << "Input Error:  Enter H W X Y Z" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
        
        

        // setup the field
        Field field(basePoint, xLength, zLength);
        std::cout << field << std::endl;

        someDelay();
        //deploy agent
        mcpp::MinecraftConnection mc;
        mcpp::Coordinate startLoc = field.getStartLocation();

        Agent agent1(1, startLoc);
        std::cout << agent1 << std::endl;


        someDelay();
        //searching treasure
        std::cout << "Searching treasure... " << std::endl;

        bool treasureFound = false;
        bool validSteps = true;
        int iterations = MAX_ITER;
        mcpp::Coordinate treasureLoc;
        
        while((!treasureFound) && validSteps && (iterations > 0)){
            treasureFound = agent1.isBlockInNeighborhood(mcpp::Blocks::GOLD_BLOCK, treasureLoc);
            if(!treasureFound){
                validSteps = agent1.randomStep();
            }
            iterations--;
        }

        if(treasureFound){
            std::cout << "Treasure found at: " << treasureLoc << std::endl;
            agent1.printPath();
        }
        someDelay();




    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}

// We will not cover the libraries chrono or thread in this cause.
// simply use them for very few things.
void someDelay(void){
    std::cout << "Waiting ...";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000) );
    std::cout << "Done" << std::endl;
}