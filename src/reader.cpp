///////////////////////////
//DNA READER - READER.CPP//
///////////////////////////

//LINKS//
#include "reader.h"
#include "stringHeader.h"

#define codonSize 3
///////////////////////
//FUNCTION DEFINITION//
///////////////////////

//INPUTS//

std::vector <char> ReadInputsFromFile(const std::string& filename)
{
    std::vector <char> results;
    std::ifstream file(filename);
    char buffer;

    if(file.is_open())
        {
            while(!file.eof())
                {
                    file >> buffer;
                    results.push_back(buffer);
                }
            file.close();
        }

    else
        {
            std::cerr << "Unable to open file" << filename << std::endl ;
        }
    return results;
}

std::string chooseDataType()
{
  int number;
  std::string choice;
  
  std::cout << "Does the file contain DNA or RNA" << std::endl;
  std::cout << "1. DNA" << std::endl;
  std::cout << "2. RNA" << std::endl;
  std::cout << "3. Unknown data type" << std::endl;
  std::cout << "Please enter a number" << std::endl;

  std::cin >> number;

  if(number==1)
    choice = "DNA";
  else if(number==2)
    choice = "RNA";
  else
    std::cerr << "Unknown type ; can't work" << std::endl; //To implement : method to analyze the file

  return choice;
}

//CONVERSION METHODS//
void DNAtoRNA(const std::string& filename)
{
  char inputBuffer;
  std::fstream file(filename, std::fstream::in | std::fstream::out);
  std::streambuf* coutbuf = std::cout.rdbuf();

  while(!file.eof())
    {
      inputBuffer = getchar();
      if(inputBuffer == 'T' || inputBuffer == 't')
        {
          if(inputBuffer == 'T')
            file.put('U');
          else if(inputBuffer == 't')
            file.put('u');
          else
            std::cerr << "Error" << std::endl;
        }
    }

  file.close();
  
}

std::vector <std::string> RNAtoAminoAcids(std::vector <char> RNAvector)
{
  std::vector <std::string> aminoAcids ; //Stock résultats
  myString codon;
  int n = aminoAcidsList.size();
  std::string interString;

  for(int i=0; i<RNAvector.size(); i+=3)
    {
      interString = RNAvector[i] + RNAvector[i+1] + RNAvector[i+2];
      codon.setMyStringVar(interString) ;

      for(int j=0; j<n ; j++)
        {
          if(codon.isIn(aminoAcidsList[j].codons) == true)
            {
              aminoAcids.push_back(aminoAcidsList[j].name);
              break;
            }
        }
    }

  return aminoAcids;

}

void replaceChar(const std::string& filename, char c)
{
  std::fstream file(filename, std::ios::in | std::ios::out);
}
  
//COMP METHODS//

bool sameChar(const char& a, const char& b)
{
  if(a==b)
    return true;

  else
    return false;
}



//SEARCH METHODS//
int findStartCodon(std::vector <char> inputVector)
{
  int indexOfStartCodon = 0;
  //Finding first letter (A)
  for(int i=0; i<inputVector.size(); i++)
    {
        if(inputVector[i]=='A' || inputVector[i]=='a')
        {
          if(inputVector[i+1]=='U' || inputVector[i+1]=='u')
          {
              if(inputVector[i+2]=='G' || inputVector[i+2]=='g')
              {
                indexOfStartCodon = i;
                break;
              }
    
              else 
              {
                indexOfStartCodon = -1;
              }
            }
          else 
          {
            indexOfStartCodon = -1;
          }
        }
          
        else 
        {
          indexOfStartCodon = -1;
        }
      }

  if(indexOfStartCodon >= 0)
    return indexOfStartCodon;
  else
    std::cerr << "Not able to find start codon" << std::endl;
            

}


//VECTOR METHODS//
/*bool isIn(std::string s, std::vector <std::string> vec)
{
  int n = vec.size();
  bool b;

  for(int i=0; i<n; i++)
    {
      if(s==vec[i])
        {
          b=true;
          break;
        }
      else
        b=false;
    }

  return b;
}*/

//OUTPUTS//
void writeAminoAcidsInFile(std::vector <std::string> aaList)
{
  int n = aaList.size();
  std::streambuf* coutbuf = std::cout.rdbuf();
  std::ofstream outputFile("aminoAcidsSequence.txt");
  std::cout.rdbuf(outputFile.rdbuf());

  for(int i=0; i<n; i++)
    {
      std::cout << aaList[i] << " - " ;
    }

  std::cout.rdbuf(coutbuf);
  outputFile.close();
    
}