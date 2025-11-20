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
/*  std::cout << "Enter file name : " << std::endl;
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

  writeAminoAcidsInFile(outputs);*////
  
/*  sqlite3* database = nullptr;
  int result = sqlite3_open("elements.db", &database);  // Opens the file

  if (result != SQLITE_OK) 
  {
    std::cerr << "Error opening database: " << sqlite3_errmsg(database) << std::endl;
    return 1;  // or throw std::runtime_error if you prefer
  }

std::cout << "Database opened successfully!" << std::endl;
  
  atom oxygenAtom;
  oxygenAtom.infos = getElementInfoFromDB( database ,"O");

  std::cout << "Atom selected : " <<oxygenAtom.infos.elementName<< " ("<<oxygenAtom.infos.elementSymbol<<") "<<std::endl;*/

  sqlite3* database = openSQLDataBase("molecules.db");
  molecule molecule1 ;
  molecule1.infos=getMoleculeFromDB(database, "Serine");

  molecule molecule2 = buildMolecule();
  outputMolecule(molecule2);

  
  
  return 0;

}