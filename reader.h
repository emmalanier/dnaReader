/////////////////////////
//DNA READER - READER.H//
/////////////////////////

#ifndef READER_H
#define READER_H

//INCLUDES//
#include <vector>
#include <string>

//////////
//ARRAYS//
//////////

std::string Ala[8] = {"GCU", "GCC", "GCA", "GCG", "gcu", "gcc", "gca", "gcg"};
std::string Arg[12] = {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG", "cgu", "cgc", "cga", "cgg", "aga", "agg"};
std::string Asn[4] = {"AAU", "AAC", "aau", "aac"};
std::string Asp[4] = {"GAU", "GAC", "gau", "gac"};
std::string Cys[4] = {"UGU", "UGC", "ugu", "ugc"};
std::string Gln[4] = {"CAA", "CAG", "caa", "cag"};
std::string Glu[4] = {"GAA", "GAG", "gaa", "gag"};
std::string Gly[8] = {"GGU", "GGC", "GGA", "GGG", "ggu", "ggc", "gga", "ggg"};
std::string His[4] = {"CAU", "CAC", "cau", "cac"};
std::string Ile[6] = {"AUU", "AUC", "AUA", "auu", "auc", "aua"};
std::string Leu[12] = {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG", "uua", "uug", "cuu", "cuc", "cua", "cug"};
std::string Lys[4] = {"AAA", "AAG", "aaa", "aag"};
std::string Met[2] = {"AUG", "aug"};
std::string Phe[4] = {"UUU", "UUC", "uuu", "uuc"};
std::string Pro[8] = {"CCU", "CCC", "CCA", "CCG", "ccu", "ccc", "cca", "ccg"};
std::string Ser[12] = {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC", "ucu", "ucc", "uca", "ucg", "agu", "agc"};
std::string Thr[8] = {"ACU", "ACC", "ACA", "ACG", "acu", "acc", "aca", "acg"};
std::string Trp[2] = {"UGG", "ugg"};
std::string Tyr[4] = {"UAU", "UAC", "uau", "uac"};
std::string Val[8] = {"GUU", "GUC", "GUA", "GUG", "guu", "guc", "gua", "gug"};
std::string STOP[6] = {"UAG", "UAA", "UGA", "uag", "uaa", "uga"};

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

#endif //READER_H