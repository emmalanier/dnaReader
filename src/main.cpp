/////////////////////
//DNA READER - MAIN//
/////////////////////

//INCLUDES//
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

//LINKS//
#include "reader.h"

//VARIABLES//

std::string filename = " ";
std::vector <char> inputs;

//MAIN PROGRAM//

int main()
{
  std::cout << "Enter file name : " << std::endl;
  std::cin>>filename;

  inputs = ReadInputsFromFile(filename);
  
  return 0;

}