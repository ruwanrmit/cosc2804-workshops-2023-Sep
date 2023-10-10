#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include "Utils.h"
#include <stdexcept>

/*
The code below has some issues.
We will be fixing along the way. Do not assume correctness.
*/
int main(void){

    //Read the height and width
    int envHeight = 0;
    int envWidth = 0;

    bool retVal = false;
    try{
        // ReadEnvSize(envHeight, envWidth);

        while (!retVal)
        {
            retVal = ReadEnvSize(envHeight, envWidth);
            std::cout << "height and width inputs not correct" << std::endl;
            if(!retVal){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
        
        

        // Create instance of Env class
        Env env(envHeight, envWidth);
        // std::cout << "Height: " << env.getHeight() << ", Width: " 
        //                                 << env.getWidth() << std::endl;

        // Read the structure of the environment
        char** envStructure;
        envStructure = new char*[envHeight];
        for(int i =0; i < envHeight; i++){
            envStructure[i] = new char[envWidth];
        }
        readEnvStdin(envStructure, envHeight, envWidth);

        env.setEnvStructure(envStructure);

        // for (int row = 0; row < env.getHeight(); row++){
        //     for (int col = 0; col < env.getWidth(); col++){
        //         std::cout << env.getEnvStructure()[row][col];
        //     }
        //     std::cout << std::endl;
        // }

        
        // Read the start coordinate
        mcpp::Coordinate* start = nullptr;
        ReadEnvStart(&start);
        // std::cout << start->x << "," << start->y << "," << start->z << std::endl;

        env.setStart(start);

        //Construct the environment
        BuildEnvironment(&env);
        

        //delete memory
        for(int i =0; i < envHeight; i++){
            delete[] envStructure[i];
            envStructure[i] = nullptr;
        }
        delete[] envStructure;
        envStructure = nullptr;

        delete start;
        start = nullptr;

    }catch(std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
