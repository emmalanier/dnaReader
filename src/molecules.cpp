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

molecule::molecule()
{
  molecule_id = " ";
  molecule_name = " ";
  molecule_formula = " ";
  molecule_InChI = " ";
  molecule_SMILES = " ";
  molecule_IUPAC = " ";
  number_of_atoms = 0;
}

molecule::molecule(const std::string& id, const std::string& name, const std::string& formula, const std::string& inchi, const std::string& smiles, const std::string& iupac)
{
  molecule_id = id;
  molecule_name = name;
  molecule_formula = formula;
  molecule_InChI = inchi;
  molecule_SMILES = smiles;
  molecule_IUPAC = iupac;
}


///////////////
//C++ METHODS//
///////////////

//Method below will prob be moved to another file
/*std::vector<std::string> convert_smiles(molecule& m)
{
    for(int i = 0; i < m.get_molecule_SMILES().length(); i++)
    {
        
    }
}*/