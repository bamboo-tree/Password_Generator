#include <iostream>
#include <string>

#include "Generator.h"


/*
    TODO:
    - add better validation for user input
    - try different buffer sizes
    - add error handling
    - make it more 'bash friendly'
    - improve perforamnce???
*/


int main(){
    std::string path = "";
    while(path.size() < 1){
        std::cout << "Create filname -> ";
        std::cin >> path;
        if(path.size() > 4 && path.substr(path.size()-4, path.size()-1) == ".txt"){
            // no need to add .txt
        }
        else{
            path += ".txt";
        }
    }

    std::string character_set = "";
    while(character_set.size() < 1){
        std::cout << "Enter symbols to generate password -> ";
        std::cin >> character_set;
    }

    int length = 0;
    while(length < 1 || length > 10){
        std::cout << "Enter length of password -> ";
        std::cin >> length;
    }

    Generator user_generator = Generator(path, character_set, length);
    user_generator.start();
    user_generator.status();

    return 0;
}