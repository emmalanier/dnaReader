////////////////////
//Molecule Builder//
////////////////////

#include "molecules.h"

//The goal here is to convert the SMILES into something useable for OpenGl rendering. The first step will be converting
//it into a Cramer representation. To do so, we will first not take into account the scale/length/angles etc.

std::vector<std::string> convert_smiles(molecule& m)
{
    bool secondary_chain = false;
    bool in_brackets = false;
    
    int char_in_brackets = 0;
    int atoms_left = m.get_number_of_atoms();
    int secondary_chains_number = 0;

    //Will need optimization :
    std::vector<char> other_characters ;
    other_characters.push_back('@');
    other_characters.push_back('=');
    other_characters.push_back('-');
    other_characters.push_back('+');
    other_characters.push_back('#');
    other_characters.push_back('/');
    other_characters.push_back('\\');

    //
    std::vector<std::string> smiles_decomposed ;
    std::vector<std::string> main_chain_atoms ;


    for(int i = 0; i < m.get_molecule_SMILES().length(); i++)
    {
        smiles_decomposed[i] = (m.get_molecule_SMILES()[i]);
    }

    for(int i = 0; i < smiles_decomposed.size(); i++)
    {

        if(smiles_decomposed[i] == "(")
        {
            secondary_chain = true;
            secondary_chains_number++;
        }

        else if(smiles_decomposed[i] == ")")
        {
            secondary_chain = false;
        }

        else if(smiles_decomposed[i] == "[")
        {
            in_brackets = true;
        }

        else if(smiles_decomposed[i] == "]")
        {
            in_brackets = false;
        }

        else
        {
            if(in_brackets)
            {
                char_in_brackets++;
            }

            else if(!in_brackets)
            {
                char_in_brackets = 0;
            }


            if(std::isalpha(smiles_decomposed[i][0]) && !secondary_chain && !in_brackets)
            {
                main_chain_atoms.push_back(smiles_decomposed[i]);
                
            }

            else if(std::isalpha(smiles_decomposed[i][0]) && !secondary_chain && in_brackets)
            {
                if(char_in_brackets > 1)
                {
                    main_chain_atoms[main_chain_atoms.size() - 1] += smiles_decomposed[i][0];
                }

                else
                main_chain_atoms.push_back(smiles_decomposed[i]);
            }

            else if(std::find(other_characters.begin(), other_characters.end(), smiles_decomposed[i][0]) < other_characters.end())
            {
                main_chain_atoms[main_chain_atoms.size() - 1] += smiles_decomposed[i][0];

            }
        }   
    }
    return main_chain_atoms;
}