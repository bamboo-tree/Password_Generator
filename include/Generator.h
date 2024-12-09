#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>


#ifndef GENERATOR_H
#define GENERATOR_H
#pragma ONCE

class Generator{
    private:
        std::string path;           // path to file in which passwords will be stored
        int length;                 // length of generated password
        std::string character_set;  // characters used to generate password


        std::string buffer;
        int buffer_max_size = 1000;

        std::ofstream file;
        void recursive_generation(std::string before);

    public:
        Generator(std::string _path, std::string _character_set, int _length);
        void status();
        std::string get_file_size();

        void start();
};
#endif // GENERATOR_H