#include <iostream>
#include <exception>
#include <random>
#include <chrono>
#include <thread>

#include <mcpp/mcpp.h>
#include "CoordinateBlock.h"



int main(void){

    mcpp::CoordinateBlock coordBlock(4848, 71, 4369, mcpp::Blocks::ACACIA_WOOD_PLANK);

    std::cout << coordBlock << std::endl;


    // mcpp::Coordinate* temp;
    // temp = &coordBlock;
    // std::cout << *temp << std::endl;


    // mcpp::BlockType* tempb;
    // tempb = &coordBlock;
    // std::cout << *tempb << std::endl;

    return EXIT_SUCCESS;
}