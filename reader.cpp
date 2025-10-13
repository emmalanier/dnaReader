///////////////////////////
//DNA READER - READER.CPP//
///////////////////////////

//INCLUDES//
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

//LINKS//
#include "reader.h"

#define codonSize 3
///////////////////////
//FUNCTION DEFINITION//
///////////////////////

//INPUTS//

std::vector <char> ReadInputsFromFile(const std::string& filename)
{
    std::vector <char> results;
    std::ifstream file(filename);
    char buffer;

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

void chooseDataType()
{

}

//???//
void DNAtoRNA()
{

}

std::vector <std::string> RNAtoAminoAcids(std::vector <char> RNAvector)
{
  std::vector <std::string> aminoAcids ;
  std::string codon;

}
  
//CHAR METHODS//

bool sameChar(const char& a, const char& b)
{
  if(a==b)
    return true;

  else
    return false;
}


//SEARCH METHODS//
int findStartCodon(std::vector <char> inputVector)
{
  //Finding first letter (A)
  for(int i=0; i<inputVector.size(); i++)
    {
      if(inputVector[i]=='A' || inputVector[i]=='a')
        {
          if(inputVector[i+1]=='U' || inputVector[i+1]=='u')
            {
              if(inputVector[i+2]=='G' || inputVector[i+2]=='g')
                {
                  return i;
                  break;
                }

              else 
                {
                  std::cerr << "No start Codon found" <<std::endl;
                  return -1;
                }
             }
          }
      }
            

}