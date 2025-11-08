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
  std::string olderAtomId;
  std::string addedAtomId;
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

  std::vector <electronicBond> electronicBondsList;
};

struct molecule
{
  std::string moleculeName;
  std::vector <atom> atoms;
  std::tuple <std::string, int> numberOfAtoms;

  std::string moleculeId; //For SQL database
  std::string buildInstructions;

};



///////////////
//C++ METHODS//
///////////////

//MATHS//
myVector distanceVector(electron, electron);

double distanceValue(position, position);

//ATOM CREATION//
atom createAtom(sqlite3*, std::string);

//MOLECULE METHODS//
atom putFirstAtom(std::string); //PF
void addAnAtomicBond(std::string, atom, atom); //AAAB
atom selectAnOtherAtom(std::string); //SAOA
molecule linkWith(molecule); //LW
molecule separateFrom(molecule); //SF

//MOLECULE BUILDING//
molecule buildMolecule();
molecule preBuiltMolecule();
molecule buildFromScratch();

std::vector <std::string> readInstructions(molecule);
std::vector <std::string> readAAABInstruction(std::string);

///////////////
//SQL METHODS//
///////////////

elementInfo getElementInfoFromDB(sqlite3*, const std::string&);
molecule getMoleculeFromDB(sqlite3*, const std::string&);


#endif //MOLECULES_H