/////////////////////////
//DNA READER - READER.H//
/////////////////////////

#ifndef READER_H
#define READER_H

//INCLUDES//
#include <fstream>
#include <iostream>
#include <iomanip>
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

inline aminoAcidInfo A{"Ala", {"GCU", "GCC", "GCA", "GCG", "gcu", "gcc", "gca", "gcg"}};
inline aminoAcidInfo R{"Arg", {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG", "cgu", "cgc", "cga", "cgg", "aga", "agg"}};
inline aminoAcidInfo N{"Asn", {"AAU", "AAC", "aau", "aac"}};
inline aminoAcidInfo D{"Asp", {"GAU", "GAC", "gau", "gac"}};
inline aminoAcidInfo C{"Cys", {"UGU", "UGC", "ugu", "ugc"}};
inline aminoAcidInfo Q{"Gln", {"CAA", "CAG", "caa", "cag"}};
inline aminoAcidInfo E{"Glu", {"GAA", "GAG", "gaa", "gag"}};
inline aminoAcidInfo G{"Gly", {"GGU", "GGC", "GGA", "GGG", "ggu", "ggc", "gga", "ggg"}};
inline aminoAcidInfo H{"His", {"CAU", "CAC", "cau", "cac"}};
inline aminoAcidInfo I{"Ile", {"AUU", "AUC", "AUA", "auu", "auc", "aua"}};
inline aminoAcidInfo L{"Leu", {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG", "uua", "uug", "cuu", "cuc", "cua", "cug"}};
inline aminoAcidInfo K{"Lys", {"AAA", "AAG", "aaa", "aag"}};
inline aminoAcidInfo M{"Met", {"AUG", "aug"}};
inline aminoAcidInfo F{"Phe", {"UUU", "UUC", "uuu", "uuc"}};
inline aminoAcidInfo P{"Pro", {"CCU", "CCC", "CCA", "CCG", "ccu", "ccc", "cca", "ccg"}};
inline aminoAcidInfo S{"Ser", {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC", "ucu", "ucc", "uca", "ucg", "agu", "agc"}};
inline aminoAcidInfo T{"Thr", {"ACU", "ACC", "ACA", "ACG", "acu", "acc", "aca", "acg"}};
inline aminoAcidInfo W{"Trp", {"UGG", "ugg"}};
inline aminoAcidInfo Y{"Tyr", {"UAU", "UAC", "uau", "uac"}};
inline aminoAcidInfo V{"Val", {"GUU", "GUC", "GUA", "GUG", "guu", "guc", "gua", "gug"}};
inline aminoAcidInfo STO{"Stop", {"UAG", "UAA", "UGA", "uag", "uaa", "uga"}};

inline std::vector <aminoAcidInfo> aminoAcidsList = {A, R, N, D, C, Q, E, G, H, I, L, K, M, F, P, S, T, W, Y, V, STO};

////////////////////////
//FUNCTION DECLARATION//
////////////////////////

//INPUTS//
std::vector <char> ReadInputsFromFile(const std::string&);
std::string chooseDataType(); //To tell if the file contains DNA or RNA

//CHAR METHODS//
bool sameChar(const char&, const char&);

//SEARCH METHODS//
int findStartCodon(std::vector <char>);

//CONVERSION METHODS//
void DNAtoRNA(const std::string&); //If the file contains DNA, converts it into RNA
std::vector <char> DNAtoRNAbis(const std::string&); //If the file contains DNA, converts it into RNA
std::vector <std::string> RNAtoAminoAcids(std::vector <char>, int);
void replaceChar();
//VECTOR SEARCH//
//bool isIn(std::string, std::vector <std::string>);

//OUTPUTS//
void writeAminoAcidsInFile(std::vector <std::string>);

#endif //READER_H