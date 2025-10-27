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
#include "molecules.h"

//VARIABLES//

std::string filename = " ";
std::vector <char> inputs;
std::vector <std::string> outputs ;
std::string dataType ;
int startCodonPos ;

//MAIN PROGRAM//

int main()
{

//DNA to amino acids////
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

  writeAminoAcidsInFile(outputs);

  
//Creating a molecule(test)
  molecule water;
  water.atoms.push_back(atom1);
  water.atoms.push_back(atom2);
  water.atoms.push_back(atom3);

  water.moleculeName = "Water";

/*struct atom
{
  int atomicNumber;
  int protonsNumber;
  int electronsNumber;
  int lonePairsNumber;
  int sharedPairsNumber;
  int totalPairsNumber;

  double electronegativity;
  double atomicMass;
  double atomicRadius;

  std::string elementName;

  std::vector <electronicBond> electronicBondsList;
};*/
  
  
  return 0;

}