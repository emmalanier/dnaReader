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
};

struct molecule
{
  std::string moleculeName;
  std::vector <atom> atoms;

};

///////////
//METHODS//
///////////

myVector distanceVector(electron, electron);

double distanceValue(position, position);

#endif //MOLECULES_H