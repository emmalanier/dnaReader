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
      inputs = DNAtoRNAbis(filename);
    }
  
  else if(dataType == "RNA")
    {
      inputs = ReadInputsFromFile(filename);
    }


  startCodonPos = findStartCodon(inputs);

  outputs = RNAtoAminoAcids(inputs, startCodonPos);

  for(int i=0; i<outputs.size(); i++)
    {
      std::cout<< outputs[i]<<std::endl;
    }

  writeAminoAcidsInFile(outputs);
  
  return 0;

}