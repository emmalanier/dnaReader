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
#include <algorithm>


///////////
//CLASSES//
///////////

class molecule
{
  protected:
    std::string molecule_id;
    std::string molecule_name;
    std::string molecule_formula;
    std::string molecule_InChI;
    std::string molecule_SMILES;
    std::string molecule_IUPAC;

  public:
    molecule();
    molecule(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);

    std::string get_molecule_id();
    std::string get_molecule_name();
    std::string get_molecule_formula();
    std::string get_molecule_InChI();
    std::string get_molecule_SMILES();
    std::string get_molecule_IUPAC();

    void set_molecule_id(const std::string&);
    void set_molecule_name(const std::string&);
    void set_molecule_formula(const std::string&);
    void set_molecule_InChI(const std::string&);
    void set_molecule_SMILES(const std::string&);
    void set_molecule_IUPAC(const std::string&);
}

class amino_acid : public molecule
{
  private:
    std::string aa_abbr;
    std::string aa_letter;
    std::string aa_name;
    std::string aa_molecule_id;
    std::string aa_InChI;
    std::string aa_SMILES;
    std::string aa_IUPAC;

  public:
    amino_acid();
    amino_acid(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
}

///////////////
//C++ METHODS//
///////////////


///////////////
//SQL METHODS//
///////////////

elementInfo getElementInfoFromDB(sqlite3*, const std::string&);
moleculeInfo getMoleculeFromDB(sqlite3*, const std::string&);
sqlite3* openSQLDataBase(const char*);

#endif //MOLECULES_H