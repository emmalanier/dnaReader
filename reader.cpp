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

vector <string> ReadInputsFromFile(const string& filename)
{
    vector <string> results;
    ifstream file(filename);
    string buffer;

    if(file.is_open())
        {
            while(getline(file, buffer))
                {
                    results.push_back(buffer);
                }
            file.close();
        }

    else
        {
            cerr << "Unable to open file" << filename << endl ;
        }
    return results;
}