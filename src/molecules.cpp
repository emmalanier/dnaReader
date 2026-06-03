//////////////////////////////
//DNA READER - MOLECULES.CPP//
//////////////////////////////

//LINKS//
#include "molecules.h"

//////////////////////////
//METHODS FOR ATOM CLASS//
//////////////////////////

//Constructors//
atom::atom()
{
  symbol = " ";
  name = " ";
  atomic_number = 0;
  atomic_mass = 0.0;
  atomic_radius = 0.0;
  electronegativity = 0.0;
  bonds_number = 0;
}

atom::atom(const std::vector<std::string>& infos)
{
  if (infos.size() != 7) 
  {
    throw std::invalid_argument("Invalid number of parameters for atom constructor");
  }

  symbol = infos[0];
  name = infos[1];
  atomic_number = std::stoi(infos[2]);
  atomic_mass = std::stod(infos[3]);
  atomic_radius = std::stod(infos[4]);
  electronegativity = std::stod(infos[5]);
  bonds_number = std::stoi(infos[6]);
}

atom::atom(const std::string& s, const std::string& n, int atomic_n, double atomic_m, double atomic_r, double e, int bn)
{
  symbol = s;
  name = n;
  atomic_number = atomic_n;
  atomic_mass = atomic_m;
  atomic_radius = atomic_r;
  electronegativity = e;
  bonds_number = bn;
}

//Getters//
std::string atom::get_symbol()
{
  return symbol;
}

std::string atom::get_name()
{
  return name;
}

int atom::get_atomic_number()
{
  return atomic_number;
}

double atom::get_atomic_mass()
{
  return atomic_mass;
}

double atom::get_atomic_radius()
{
  return atomic_radius;
}

double atom::get_electronegativity()
{
  return electronegativity;
}

int atom::get_bonds_number()
{
  return bonds_number;
}


//Setters//

void atom::set_symbol(const std::string& s)
{
  symbol = s;
}

void atom::set_name(const std::string& n)
{
  name = n;
}

void atom::set_atomic_number(int atomic_n)
{
  atomic_number = atomic_n;
}

void atom::set_atomic_mass(double atomic_m)
{
  atomic_mass = atomic_m;
}

void atom::set_atomic_radius(double atomic_r)
{
  atomic_radius = atomic_r;
}

void atom::set_electronegativity(double e)
{
  electronegativity = e;
}

void atom::set_bonds_number(int bn)
{
  bonds_number = bn;
}


//////////////////////////////
//METHODS FOR MOLECULE CLASS//
//////////////////////////////

//Constructors//

molecule::molecule()
{
  molecule_id = " ";
  molecule_name = " ";
  molecule_InChI = " ";
  molecule_SMILES = " ";
  molecule_IUPAC = " ";
  number_of_atoms = 0;
}

molecule::molecule(const std::vector<std::string>& infos)
{
  if (infos.size() != 5) 
  {
    throw std::invalid_argument("Invalid number of parameters for molecule constructor");
  }

  molecule_id = infos[0];
  molecule_name = infos[1];
  molecule_IUPAC = infos[2];
  molecule_InChI = infos[3];
  molecule_SMILES = infos[4];
}

molecule::molecule(const std::string& id, const std::string& name, const std::string& inchi, const std::string& smiles, const std::string& iupac)
{
  molecule_id = id;
  molecule_name = name;
  molecule_InChI = inchi;
  molecule_SMILES = smiles;
  molecule_IUPAC = iupac;
}


//Getters//

std::string molecule::get_molecule_id()
{
  return molecule_id;
}

std::string molecule::get_molecule_name()
{
  return molecule_name;
}

std::string molecule::get_molecule_formula()
{
  return molecule_formula;
}

std::string molecule::get_molecule_InChI()
{
  return molecule_InChI;
}

std::string molecule::get_molecule_SMILES()
{
  return molecule_SMILES;
}

std::string molecule::get_molecule_IUPAC()
{
  return molecule_IUPAC;
}

int molecule::get_number_of_atoms()
{
  return number_of_atoms;
}

std::vector<std::vector<atom>> molecule::get_bonds()
{
  return bonds;
}


//Setters//

void molecule::set_molecule_id(const std::string& id)
{
  molecule_id = id;
}

void molecule::set_molecule_name(const std::string& name)
{
  molecule_name = name;
}

void molecule::set_molecule_formula(const std::string& formula)
{
  molecule_formula = formula;
}

void molecule::set_molecule_InChI(const std::string& inchi)
{
  molecule_InChI = inchi;
}

void molecule::set_molecule_SMILES(const std::string& smiles)
{
  molecule_SMILES = smiles;
}

void molecule::set_molecule_IUPAC(const std::string& iupac)
{
  molecule_IUPAC = iupac;
}

void molecule::set_number_of_atoms(int num)
{
  number_of_atoms = num;
}

void molecule::set_bonds(const std::vector<std::vector<atom>>& b)
{
  bonds = b;
}

////////////////////////////////
//METHODS FOR AMINO ACID CLASS//
////////////////////////////////

//Constructors//

amino_acid::amino_acid()
{
  aa_abbr = " ";
  aa_letter = " ";
}

amino_acid::amino_acid(const std::string& abbr, const std::string& letter)
{
  aa_abbr = abbr;
  aa_letter = letter;
}


//Getters//

std::string amino_acid::get_aa_abbr()
{
  return aa_abbr;
}

std::string amino_acid::get_aa_letter()
{
  return aa_letter;
}


//Setters//

void amino_acid::set_aa_abbr(const std::string& abbr)
{
  aa_abbr = abbr;
}

void amino_acid::set_aa_letter(const std::string& letter)
{
  aa_letter = letter;
}
