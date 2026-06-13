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
//DEFINES//
///////////


///////////
//CLASSES//
///////////

class atom
{
  protected:
    std::string symbol;
    std::string name;
    int atomic_number;
    double atomic_mass;
    double atomic_radius;
    double electronegativity;
    int bonds_number;

  public:
    atom();
    atom(const std::vector<std::string>&);
    atom(const std::string&, const std::string&, int, double, double, double, int);

    std::string get_symbol();
    std::string get_name();
    int get_atomic_number();
    double get_atomic_mass();
    double get_atomic_radius();
    double get_electronegativity();
    int get_bonds_number();

    void set_symbol(const std::string&);
    void set_name(const std::string&);
    void set_atomic_number(int);
    void set_atomic_mass(double);
    void set_atomic_radius(double);
    void set_electronegativity(double);
    void set_bonds_number(int);

};

class molecule : public atom
{
  protected:
  //Stuff from the SQL database
    std::string molecule_id;
    std::string molecule_name;
    std::string molecule_formula;
    std::string molecule_InChI;
    std::string molecule_SMILES;
    std::string molecule_IUPAC;

  //Stuff calculated later, from db infos
    int number_of_atoms;
    std::vector<std::vector<atom>> bonds;

  public:
    molecule();
    molecule(const std::vector<std::string>&);
    molecule(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);

    std::string get_molecule_id();
    std::string get_molecule_name();
    std::string get_molecule_formula();
    std::string get_molecule_InChI();
    std::string get_molecule_SMILES();
    std::string get_molecule_IUPAC();
    int get_number_of_atoms();
    std::vector<std::vector<atom>> get_bonds();

    void set_molecule_id(const std::string&);
    void set_molecule_name(const std::string&);
    void set_molecule_formula(const std::string&);
    void set_molecule_InChI(const std::string&);
    void set_molecule_SMILES(const std::string&);
    void set_molecule_IUPAC(const std::string&);
    void set_number_of_atoms(int);
    void set_bonds(const std::vector<std::vector<atom>>&);
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

    void set_aa_abbr(const std::string&);
    void set_aa_letter(const std::string&);
};

///////////////
//C++ METHODS//
///////////////

//Convert SMILES METHOD (incomplete)//
std::vector<std::string> convert_smiles(molecule&);

//Sub methods
std::vector<std::string> decompose_smiles(molecule&);
std::vector<int[2]> get_bracket_pairs(const std::vector<std::string>&);
std::vector<int[2]> get_sc_pairs(const std::vector<std::string>&);
//void check_is_in_brackets(bool&, const std::string&, const std::string&, const std::string&);

///////////////
//SQL METHODS//
///////////////

std::vector<std::string> get_element_from_DB(sqlite3*, const std::string&);
std::vector<std::string> get_molecule_from_DB(sqlite3*, const std::string&);
sqlite3* open_sql_data_base(const char*);

#endif //MOLECULES_H