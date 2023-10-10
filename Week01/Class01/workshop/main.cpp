#include <iostream>

#include <mcpp/mcpp.h>
#include "Env.h"

void readEnvSize(int& envLength, int& envWidth);

int main(void){

    /*
        Reading inputs
    */
    int envLength = 0;
    int envWidth = 0;

    readEnvSize( envLength,  envWidth);
    Env temp_env(envLength, envWidth);

    std::cout << "Enter the structurer of the environment (H W):" << std::endl;
    char envStructure[temp_env.getLength()][temp_env.getWidth()];
    char readChar;
    for(int row = 0; row < envLength; row++){
        for(int col = 0; col < envWidth; col++){
            std::cin >> readChar;
            envStructure[row][col] = readChar;
        }
    }

    int build_x = 0;
    int build_y = 0;
    int build_z = 0;

    std::cout << "Enter the build coordinate of the environment (X Y Z):" << std::endl;

    std::cin >> build_x;
    std::cin >> build_y;
    std::cin >> build_z;
    
    /*
        Printing
    */
    std::cout << "Length: " << envLength << ", Width: " << envWidth << std::endl;
    std::cout << "Build X: " << build_x << ", Y: " 
                        << build_y << ", Z: " << build_z  << std::endl;
    for(int row = 0; row < envLength; row++){
        for(int col = 0; col < envWidth; col++){
            std::cout << envStructure[row][col];
        }
        std::cout << std::endl;
    }

    /*
        Building
    */

//    mcpp::MinecraftConnection mc;
//    mc.doCommand("time set day");
//    mc.postToChat("Hello from COSC2804");

//     mcpp::Coordinate buildStart(build_x, build_y, build_z);

//     for(int row = 0; row < envLength; row++){
//         for(int col = 0; col < envWidth; col++){
//             if(envStructure[row][col] == 'x'){
//                 mc.setBlock(buildStart 
//                         + mcpp::Coordinate(row, 0, col) , 
//                                 mcpp::Blocks::BRICKS);
//             }else{
//                 mc.setBlock(buildStart 
//                         + mcpp::Coordinate(row, 0, col) , 
//                                 mcpp::Blocks::AIR);
//             }
//         }
//     }

    return EXIT_SUCCESS;
}

void readEnvSize(int& envLength, int& envWidth){
    std::cout << "Enter the size of the environment (H W):" << std::endl;
    std::cin >> envLength;
    std::cin >> envWidth;
}