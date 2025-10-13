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

std::string Ala[8] = {"GCU", "GCC", "GCA", "GCG"};
std::string Arg[12] = {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG"};
std::string Asn[4] = {"AAU", "AAC"};
std::string Asp[4] = {"GAU", "GAC"};
std::string Cys[4] = {"UGU", "UGC"};
std::string Gln[4] = {"CAA", "CAG"};
std::string Glu[4] = {"GAA", "GAG"};
std::string Gly[8] = {"GGU", "GGC", "GGA", "GGG"};
std::string His[4] = {"CAU", "CAC"};
std::string Ile[6] = {"AUU", "AUC", "AUA"};
std::string Leu[12] = {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG"};
std::string Lys[4] = {"AAA", "AAG"};
std::string Met[2] = {"AUG"};
std::string Phe[4] = {"UUU", "UUC"};
std::string Pro[8] = {"CCU", "CCC", "CCA", "CCG"};
std::string Ser[12] = {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC"};
std::string Thr[8] = {"ACU", "ACC", "ACA", "ACG"};
std::string Trp[2] = {"UGG"};
std::string Tyr[4] = {"UAU", "UAC"};
std::string Val[8] = {"GUU", "GUC", "GUA", "GUG"};
std::string STOP[6] = {"UAG", "UAA", "UGA"};

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