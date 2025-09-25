/////////////////////
//DNA READER - MAIN//
/////////////////////

//INCLUDES//
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>

//LINKS//
#include "reader.h"

//VARIABLES//
std::string filename = " ";
std::vector <std::string> inputs;

//MAIN PROGRAM//

int main()
{
  std::cout << "Enter file name : " << std::endl;
  std::cin>>filename;

  inputs = ReadInputsFromFile(filename);

  if(inputs.size() == 1)
    {
      //methode separation
    }
  
  return 0;

}