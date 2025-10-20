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
#include "stringHeader.h"

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
  std::vector <std::string> aminoAcids ; //Stock résultats
  myString codon();
  int n = aminoAcidsList.size();

  for(int i=0; i<RNAvector.size(); i+=3)
    {
      codon.setMyStringVar(RNAvector[i] + RNAvector[i+1] + RNAvector[i+2]) ;

      for(int j=0; j<n ; j++)
        {
          if(codon.isIn(
        }
    }
      

}
  
//COMP METHODS//

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
  int indexOfStartCodon = 0;
  //Finding first letter (A)
  for(int i=0; i<inputVector.size(); i++)
    {
        if(inputVector[i]=='A' || inputVector[i]=='a')
        {
          if(inputVector[i+1]=='U' || inputVector[i+1]=='u')
          {
              if(inputVector[i+2]=='G' || inputVector[i+2]=='g')
              {
                indexOfStartCodon = i;
                break;
              }
    
              else 
              {
                indexOfStartCodon = -1;
              }
            }
          else 
          {
            indexOfStartCodon = -1;
          }
        }
          
        else 
        {
          indexOfStartCodon = -1;
        }
      }

  if(indexOfStartCodon >= 0)
    return indexOfStartCodon;
  else
    std::cerr << "Not able to find start codon" << std::endl;
            

}


//VECTOR METHODS//
bool isIn(std::string s, std::vector <std::string> vec)
{
  int n = vec.size();
  bool b;

  for(int i=0; i<n; i++)
    {
      if(s==vec[i])
        {
          b=true;
          break;
        }
      else
        b=false;
    }

  return b;
}