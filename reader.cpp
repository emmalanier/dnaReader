///////////////////////////
//DNA READER - READER.CPP//
///////////////////////////

//INCLUDES//
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

//LINKS//
#include "reader.h"

//FUNCTION DEFINITION//

std::vector <std::string> ReadInputsFromFile(const std::string& filename)
{
    std::vector <std::string> results;
    std::ifstream file(filename);
    std::string buffer;

    if(file.is_open())
        {
            while(!file.eof())
                {
                    file >> buffer;
                    results.push_back(buffer);
                }
            file.close();
        }

    else
        {
            std::cerr << "Unable to open file" << filename << std::endl ;
        }
    return results;
}