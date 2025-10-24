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
std::vector <std::string> outputs ;
std::string dataType ;
int startCodonPos ;

//MAIN PROGRAM//

int main()
{
  std::cout << "Enter file name : " << std::endl;
  std::cin>>filename;

  dataType = chooseDataType();

  if(dataType == "DNA")
    {
      DNAtoRNA(filename);
    }
  
  inputs = ReadInputsFromFile(filename);

  startCodonPos = findStartCodon(inputs);

  outputs = RNAtoAminoAcids(inputs, startCodonPos);

  writeAminoAcidsInFile(outputs);
  
  return 0;

}