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
};

class amino_acid : public molecule
{
  private:
    std::string aa_abbr;
    std::string aa_letter;

  public:
    amino_acid();
    amino_acid(const std::string&, const std::string&);

    std::string get_aa_abbr();
    std::string get_aa_letter();
};

///////////////
//C++ METHODS//
///////////////


///////////////
//SQL METHODS//
///////////////

std::vector<std::string> get_element_from_DB(sqlite3*, const std::string&);
std::vector<std::string> get_molecule_from_DB(sqlite3*, const std::string&);
sqlite3* open_sql_data_base(const char*);

#endif //MOLECULES_H