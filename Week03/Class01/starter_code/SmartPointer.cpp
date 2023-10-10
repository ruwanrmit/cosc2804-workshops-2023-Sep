#include <iostream>
#include "Date.h"
#include <memory>

std::unique_ptr<Date> getDate(){ 
    std::unique_ptr<Date> retDate = std::make_unique<Date>(2021, 5, 20); 
    return retDate; 
} 

int main(void){
    { 
        //identify the error in this block
        // Date* x = new Date(2023, 5, 10);
        // Date* y = new Date(2022, 7, 11);

        // std::unique_ptr<Date> x = std::make_unique<Date>(2023, 5, 20); 
        // std::unique_ptr<Date> y = std::make_unique<Date>(2022, 7, 25); 

        std::shared_ptr<Date> x = std::make_shared<Date>(2023, 5, 01); 
        std::shared_ptr<Date> y = std::make_shared<Date>(2022, 7, 05); 

        x = y;

        std::cout << "Address of x: " << x << std::endl;
        std::cout << "Address of y: " << y << std::endl;

        std::cout << "x: " << x->day << "/" 
                            << x->month << "/" 
                            << x->year << std::endl;

        std::cout << "y: " << y->day << "/" 
                            << y->month << "/" 
                            << y->year << std::endl;

        std::cout << "Remove pointing by X" << std::endl;
        x = nullptr;
        std::cout << "Remove pointing by Y" << std::endl;
        y = nullptr;
        

        std::unique_ptr<Date> z = getDate();            
        std::cout << "z: " << z->day << "/"  
                            << z->month << "/"  
                            << z->year << std::endl;  

        // delete x;
        // delete y;

    }


    return EXIT_SUCCESS;
}