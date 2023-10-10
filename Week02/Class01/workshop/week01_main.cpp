#include <iostream>
#include "Env.h"
#include <mcpp/mcpp.h>
#include "Utils.h"
#include <exception>
#include <random>

//#define TESTING_ON

/*
The code below has some issues.
We will be fixing along the way. Do not assume correctness.
*/

int main(void){

    //Read the height and width
    unsigned int envHeight = 0;
    unsigned int envWidth = 0;

    try{
        //Read env size
        ReadEnvSize(envHeight, envWidth);

        // Read the structure of the environment
        char** envStructure;
        envStructure = new char*[envHeight];
        for(unsigned int i =0; i < envHeight; i++){
            envStructure[i] = new char[envWidth];
        }
        readEnvStdin(envStructure, envHeight, envWidth);

        // Read the start coordinate
        mcpp::Coordinate* start = nullptr;
        ReadEnvStart(&start);

        // Create instance of Env class
        //ownership of start envStructure passed to env
        Env env(envHeight, envWidth, envStructure, start);
        start = nullptr;
        envStructure = nullptr;

        start = new mcpp::Coordinate(0, 1, 0);
        env.setStart(start);

        //

        int min = 1;
        int max = 10;
        int seed = 100;
        // std::default_random_engine engine(seed);
        std::random_device engine;
        std::uniform_int_distribution<int> uniform_dist(min, max);
        int value = -1;
        for (int i = 0; i != 10; ++i) {
        value = uniform_dist(engine);
        std::cout << "Randomly-chosen value: " << value << std::endl;
        }

        // const mcpp::Coordinate* end = env.getStart();
        // end->x = 0;
        // std::cout << end->x << std::endl;
        // std::cout << env.getStart()->x << std::endl;
    
        //Construct the environment
        BuildEnvironment(&env);

        //Make a copy and build at 4868 71 4349
        Env env2(env);
        start = new mcpp::Coordinate(4868, 71, 4349);
        env2.setStart(start);
        start = nullptr;



        #ifdef TESTING_ON
        //Testing build
        std::cout << std::endl;
        std::cout << "Enter the region to check (startx starty startz height width):" << std::endl;
        int startx, starty, startz; 
        unsigned int hgt, wdt;

        std::cin >> startx;
        std::cin >> starty;
        std::cin >> startz;
        std::cin >> hgt;
        std::cin >> wdt;

        mcpp::MinecraftConnection mc;
        for(unsigned int h = 0; h<hgt; h++){
            for(unsigned int w = 0; w<wdt; w++){
                mcpp::BlockType block1 = mc.getBlock(mcpp::Coordinate(startx + h,starty, startz+w));
                mcpp::BlockType block2 = mc.getBlock(mcpp::Coordinate(startx + h,starty+1, startz+w));
                if( block1 == mcpp::Blocks::BRICKS && block2 == mcpp::Blocks::BRICKS){
                    std::cout << 'b';
                }else if (block1 == mcpp::Blocks::AIR && block2 == mcpp::Blocks::AIR){
                    std::cout << 'a';
                }else{
                    std::cout << 'e';
                }
            }
            std::cout << std::endl;

        }
        #endif


        

        //delete memory
        

    }catch(std::invalid_argument& e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
