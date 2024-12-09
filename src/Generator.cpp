#include "Generator.h"

Generator::Generator(std::string _path, std::string _character_set, int _length){
    path =  _path;
    character_set = _character_set;
    length = _length;

    if(!std::filesystem::exists(path)){
        std::cout << "Creating a file '" << path << "'\n";
        std::ofstream new_file(path);
        new_file.close(); 
    }
}

std::string Generator::get_file_size(){
    int index = 0;
    std::string units[] = {"B", "kB", "MB", "GB", "TB"};
    float output = float(std::filesystem::file_size(path));
    while(output>= 1024){
        output /= 1024;
        index++;
    }
    return std::to_string(output) + units[index];
}

void Generator::status(){
    std::cout   
        << std::setw(16) << "FILE NAME : " << path << '\n' 
        << std::setw(16) << "FILE SIZE : " << get_file_size() << '\n'
        << std::setw(16) << "CHARACTER SET : " << character_set << '\n' 
        << std::setw(16) << "LENGTH : " << length << '\n';
}

void Generator::recursive_generation(std::string before){
    if(before.size() == length){
        buffer += '\n' + before; // append buffer
        if(buffer.size() >= buffer_max_size){ // save buffer to file and clear it
            file.open(path, std::ios_base::app);
            file << buffer;
            file.close();
            buffer = "";
        }
    }
    else{
        for(char symbol : character_set){
            std::string new_string = before + symbol;
            recursive_generation(new_string);
        }
    }
}

void Generator::start(){
    std::cout << "Generating...\n";
    recursive_generation("");
    file.open(path, std::ios_base::app);
    file << buffer;
    file.close();
    buffer = "";
}