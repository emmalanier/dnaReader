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
  int numberOfElectronPairs;

  std::string bondType;

  std::vector <electron> groupA;
  std::vector <electron> groupB;
};

struct atom
{
  int electronsNumber;
  int lonePairsNumber;
  int sharedPairsNumber;
  int totalPairsNumber;

  std::string idInMolecule ;

  double atomicMass;

  std::string elementName;

  elementInfo infos;
  position atomPosition;

  std::vector <electronicBond> electronicBondsList;
};

struct molecule
{
  std::string moleculeName;
  std::vector <atom> atoms;
  std::tuple <std::string, int> numberOfAtoms;

};

///////////////
//C++ METHODS//
///////////////

//MATHS//
myVector distanceVector(electron, electron);

double distanceValue(position, position);

//ATOM CREATION//
atom createAtom();

//MOLECULE METHODS//
atom putFirstAtom(); //PF
atom addAnAtomicBond(); //AAAB
atom selectAnOtherAtom(); //SAOA
molecule linkWith(); //LW
molecule separateFrom(); //SF

//MOLECULE BUILDING//
molecule buildMolecule();
molecule preBuiltMolecule();
molecule buildFromScratch();

///////////////
//SQL METHODS//
///////////////

elementInfo getElementInfoFromDB(sqlite3*, const std::string&);

#endif //MOLECULES_H