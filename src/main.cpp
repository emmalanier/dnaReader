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
  
  sqlite3* atom_database = open_sql_data_base("elements.db");

  std::cout << "Database opened successfully!" << std::endl;
  
  std::string symbol = "C";
  std::vector<std::string> element_infos = get_element_from_DB(atom_database, symbol);

  atom atom1(element_infos);

  std::cout << "Element : " << atom1.get_symbol() << std::endl;
  std::cout << "Name : " << atom1.get_name() << std::endl;
  std::cout << "Atomic number : " << atom1.get_atomic_number() << std::endl;
  std::cout << "Atomic mass : " << atom1.get_atomic_mass() << std::endl;
  std::cout << "Atomic radius : " << atom1.get_atomic_radius() << std::endl;
  std::cout << "Electronegativity : " << atom1.get_electronegativity() << std::endl;


  sqlite3* molecule_database = open_sql_data_base("molecules.db");
  molecule molecule1 ;

  
  
  return 0;

}