////////////////////
//Molecule Builder//
////////////////////

#include "molecules.h"

//The goal here is to convert the SMILES into something useable for OpenGl rendering. The first step will be converting
//it into a Cramer representation. To do so, we will first not take into account the scale/length/angles etc.

//Sub methods

std::vector<std::string> decompose_smiles(molecule& m)
{
    std::vector<std::string> results ;

    for(int i = 0; i < m.get_molecule_SMILES().length(); i++)
    {
        results.push_back(std::string(1, m.get_molecule_SMILES()[i]));
    }

    return results;
}

std::vector<int[2]> get_bracket_pairs(const std::vector<std::string>& smiles_decomposed)
{
    std::vector<int[2]> results ;
    std::vector<bool> closed; 
    int opened_brackets = 0;

    for(int i = 0; i < smiles_decomposed.size(); i++)
    {
        if(smiles_decomposed[i] == "[")
        {
            results.push_back({i, 0});
            opened_brackets++;
            closed.push_back(false);
        }

        else if(smiles_decomposed[i] == "]")
        {
            if(opened_brackets == 1)
            {
                results[results.size() - 1][1] = i;
                closed[closed.size() - 1] = true;
            }

            else if(opened_brackets > 1)
            {
                for(int j = results.size() - 1; j >= 0; j--)
                {
                    if(!closed[j])
                    {
                        results[j][1] = i;
                        closed[j] = true;
                        break;
                    }
                }

            }
            
            opened_brackets--;

        }
    }

    return results;
}

std::vector<int[2]> get_sc_pairs(const std::vector<std::string>& smiles_decomposed)
{
    std::vector<int[2]> results ;
    std::vector<bool> closed; 
    int opened_sc = 0;

    for(int i = 0; i < smiles_decomposed.size(); i++)
    {
        if(smiles_decomposed[i] == "(")
        {
            results.push_back({i, 0});
            opened_sc++;
            closed.push_back(false);
        }

        else if(smiles_decomposed[i] == ")")
        {
            if(opened_sc == 1)
            {
                results[results.size() - 1][1] = i;
                closed[closed.size() - 1] = true;
            }

            else if(opened_sc > 1)
            {
                for(int j = results.size() - 1; j >= 0; j--)
                {
                    if(!closed[j])
                    {
                        results[j][1] = i;
                        closed[j] = true;
                        break;
                    }
                }

            }
            
            opened_sc--;

        }
    }
    
    return results;
}

std::vector<std::vector<std::string>> get_brackets_content(const std::vector<std::string>& smiles_decomposed, const std::vector<int>& opening_brackets, const std::vector<int>& closing_brackets)
{
    std::vector<std::vector<std::string>> results ;
    int encapsulated_brackets = 0;

    for(int i = 0; i < opening_brackets.size(); i++)
    {
        encapsulated_brackets = std::count_if(opening_brackets.begin()+i+1, opening_brackets.end(), opening_brackets[i+1]>closing_brackets[i]);
    }

    return results;
}

//int brackets_opened(bool& condition, const std::string& beginning_string, const std::string& end_string, const std::string& current_string)
//{
//    if(beginning_string == current_string)
//    {
//        condition = true;
//    }

//    else if(end_string == current_string)
//    {
//        condition = false;
//    }
//}

//Main method
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

    smiles_decomposed = decompose_smiles(m);

    for(int i = 0; i < smiles_decomposed.size(); i++)
    {
        //check_is_in_brackets(in_brackets, "[", "]", smiles_decomposed[i]);
        //check_is_in_brackets(secondary_chain, "(", ")", smiles_decomposed[i]);

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

        else if(std::find(other_characters.begin(), other_characters.end(), smiles_decomposed[i][0]) < other_characters.end() && !secondary_chain)
        {
            main_chain_atoms[main_chain_atoms.size() - 1] += smiles_decomposed[i][0];

        }
    }

    return main_chain_atoms;
}