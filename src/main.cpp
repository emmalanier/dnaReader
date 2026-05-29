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
  
  sqlite3* atom_database = nullptr;
  int result = sqlite3_open("elements.db", & atom_database);  // Opens the file

  if (result != SQLITE_OK) 
  {
    std::cerr << "Error opening database: " << sqlite3_errmsg(atom_database) << std::endl;
    return 1;
  }

std::cout << "Database opened successfully!" << std::endl;
  
  atom oxygenAtom;

  sqlite3* molecule_database = open_sql_data_base("molecules.db");
  molecule molecule1 ;

  
  
  return 0;

}