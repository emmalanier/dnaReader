/////////////////////////
//DNA READER - READER.H//
/////////////////////////

#ifndef READER_H
#define READER_H

//INCLUDES//
#include <vector>
#include <string>

//////////////
//STRUCTURES//
//////////////
struct aminoAcidInfo
{
  std::string name ;
  std::vector <std::string> codons ;
};

//////////
//ARRAYS//
//////////

std::vector <std::string> Ala = {"GCU", "GCC", "GCA", "GCG", "gcu", "gcc", "gca", "gcg"};
std::vector <std::string> Arg = {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG", "cgu", "cgc", "cga", "cgg", "aga", "agg"};
std::vector <std::string> Asn = {"AAU", "AAC", "aau", "aac"};
std::vector <std::string> Asp = {"GAU", "GAC", "gau", "gac"};
std::vector <std::string> Cys = {"UGU", "UGC", "ugu", "ugc"};
std::vector <std::string> Gln = {"CAA", "CAG", "caa", "cag"};
std::vector <std::string> Glu = {"GAA", "GAG", "gaa", "gag"};
std::vector <std::string> Gly = {"GGU", "GGC", "GGA", "GGG", "ggu", "ggc", "gga", "ggg"};
std::vector <std::string> His = {"CAU", "CAC", "cau", "cac"};
std::vector <std::string> Ile = {"AUU", "AUC", "AUA", "auu", "auc", "aua"};
std::vector <std::string> Leu = {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG", "uua", "uug", "cuu", "cuc", "cua", "cug"};
std::vector <std::string> Lys = {"AAA", "AAG", "aaa", "aag"};
std::vector <std::string> Met = {"AUG", "aug"};
std::vector <std::string> Phe = {"UUU", "UUC", "uuu", "uuc"};
std::vector <std::string> Pro = {"CCU", "CCC", "CCA", "CCG", "ccu", "ccc", "cca", "ccg"};
std::vector <std::string> Ser = {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC", "ucu", "ucc", "uca", "ucg", "agu", "agc"};
std::vector <std::string> Thr = {"ACU", "ACC", "ACA", "ACG", "acu", "acc", "aca", "acg"};
std::vector <std::string> Trp = {"UGG", "ugg"};
std::vector <std::string> Tyr = {"UAU", "UAC", "uau", "uac"};
std::vector <std::string> Val = {"GUU", "GUC", "GUA", "GUG", "guu", "guc", "gua", "gug"};
std::vector <std::string> STOP = {"UAG", "UAA", "UGA", "uag", "uaa", "uga"};

std::vector <std::vector <std::string>> aminoAcidsList = {Ala, Arg, Asn, Asp, Cys, Gln, Glu, Gly, His, Ile, Leu, Lys, Met, Phe, Pro, Ser, Thr, Trp, Tyr, Val, STOP};

////////////////////////
//FUNCTION DECLARATION//
////////////////////////

//INPUTS//
std::vector <char> ReadInputsFromFile(const std::string&);
void chooseDataType(); //To tell if the file contains DNA or RNA

//CHAR METHODS//
bool sameChar(const char&, const char&);

//SEARCH METHODS//
int findStartCodon(std::vector <char>);

//CONVERSION METHODS//
void DNAtoRNA(); //If the file contains DNA, converts it into RNA
std::vector <std::string> RNAtoAminoAcids(std::vector <char>);

//VECTOR SEARCH//
bool isIn(std::string, std::vector <std::string>);

#endif //READER_H