////////////////////////////
//DNA READER - MOLECULES.H//
////////////////////////////

#ifndef MOLECULES_H
#define MOLECULES_H

////////////
//INCLUDES//
////////////
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sqlite3.h>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <cctype>

////////////////////////////////////////////////////////
//MODIFICATIONS TO DO ONCE THE CODE WILL BE WORKING : //
//                                                    //
//- Change the atom structure to a class              //
//- Change the addAnAtomicBond method so that multiple//
//  bonds can be created at once                      //
//- Create methods to handle asymmetrical carbons,    //
//  chirality etc                                     //
//                                                    //
////////////////////////////////////////////////////////

//////////////
//STRUCTURES//
//////////////

struct elementInfo
{
  std::string elementSymbol;
  std::string elementName;
  int atomicNumber;
  int protonNumber;
  double atomicRadius;
  double electronegativity;
};

struct moleculeInfo
{
  std::string moleculeName;
  std::string moleculeId; //For SQL database
  std::string buildInstructions;
};

struct position
{
  double x;
  double y;
  double z;
};

struct myVector
{
  double size;

  double x_vector;
  double y_vector;
  double z_vector;
};

struct electron
{
  position electronPosition;
};

struct electronicBond
{
  std::string bondType;

  //VARIABLES FOR MORE COMPLEX PROBLEMS
  int numberOfElectronPairs;

  std::vector <electron> groupA;
  std::vector <electron> groupB;

  //VARIABLES FOR SIMPLIFIED MODELS
  std::string atomId_1;
  std::string atomId_2;
};

struct atom
{
  int electronsNumber;
  int lonePairsNumber;
  int sharedPairsNumber;
  int totalPairsNumber;

  std::string idInMolecule ;

  double atomicMass;

  elementInfo infos;
  position atomPosition;
  std::vector <electronicBond> bonds;
};

struct molecule
{
  moleculeInfo infos;
  std::vector <atom> atoms;
  std::tuple <std::string, int> numberOfAtoms;
  std::vector <electronicBond> electronicBondsList;

};



///////////////
//C++ METHODS//
///////////////


//ATOM CREATION//
atom createAtom(sqlite3*, std::string);

//MOLECULE METHODS//
atom putFirstAtom(std::string); //PF
electronicBond addAnAtomicBond(std::string, std::string, std::string); //AAAB
atom selectAnOtherAtom(std::string); //SAOA
molecule linkWith(molecule); //LW
molecule separateFrom(molecule); //SF

//MOLECULE BUILDING//
molecule buildMolecule();
molecule preBuiltMolecule(std::vector <std::string>, std::string);
molecule buildFromScratch();

std::vector <std::string> readInstructions(molecule);

std::vector <std::string> readAAABInstruction(std::string);

int atomIndex(std::vector <atom>, std::string);
std::string findCarbonType();

void outputMolecule(molecule);
std::string createAtomId(std::string, atom, int);

///////////////
//SQL METHODS//
///////////////

elementInfo getElementInfoFromDB(sqlite3*, const std::string&);
moleculeInfo getMoleculeFromDB(sqlite3*, const std::string&);
sqlite3* openSQLDataBase(const char*);

#endif //MOLECULES_H