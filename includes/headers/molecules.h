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

//////////////
//STRUCTURES//
//////////////

struct position
{
  double x;
  double y;
  double z;
};

struct electron
{
  position electronPosition;
};

struct electronicBond
{
  int numberOfElectronPairs;

  std::vector <electron> groupA;
  std::vector <electron> groupB;
};

struct atom
{
  int atomicNumber;
  int protonsNumber;
  int electronsNumber;
  int lonePairsNumber;
  int sharedPairsNumber;

  double electronegativity;
  double atomicMass;
  double atomicRadius;

  std::string elementName;

  std::vector <electronicBond> electronicBondsList;
};

struct molecule
{
  std::string moleculeName;
  std::vector <atom> atoms;

};

#endif //MOLECULES_H