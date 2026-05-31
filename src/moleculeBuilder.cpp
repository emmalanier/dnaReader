////////////////////
//Molecule Builder//
////////////////////

#include "molecules.h"

std::vector<std::string> convert_smiles(molecule& m)
{
    std::vector<char> smiles_decomposed ;

    for(int i = 0; i < m.get_molecule_SMILES().length(); i++)
    {
        smiles_decomposed.push_back(m.get_molecule_SMILES()[i]);
    }
}