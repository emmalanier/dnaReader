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
                    //file >> buffer;
                    results.push_back(file.get());
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

//SQL INPUTS//
aminoAcid getAminoAcidFromDB(sqlite3* database, const std::string& aaAbbr)
{

////VARIABLE DECLARATIONS////
  aminoAcid results;
  
  const std::string sqlRequest = "SELECT aaAbbr, aaLetter, aaName, moleculeId FROM aminoAcids WHERE aaAbbr = ?;";

  sqlite3_stmt* prepStatement = NULL;

  int prepResult = sqlite3_prepare_v2(database, sqlRequest.c_str(), -1, &prepStatement, NULL);

  //Error handling//
  if (prepResult != SQLITE_OK) 
  {
    throw std::runtime_error("Failed to prepare SQL statement for element query");
  }
  //////////////////

  int bindResult = sqlite3_bind_text(prepStatement, 1, aaAbbr.c_str(), -1, SQLITE_STATIC);///NEEDS MODIFICATION

  //Error handling//
  if (bindResult != SQLITE_OK) 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Failed to bind element symbol parameter");
  }
  //////////////////

  int stepResult = sqlite3_step(prepStatement);


////ACTUAL METHOD////
  if (stepResult == SQLITE_ROW)
  {
    results.aaAbbr = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 0));
    results.aaLetter = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 1));
    results.aaName = reinterpret_cast<const char*>(sqlite3_column_int(prepStatement, 2));
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Element not found in database: " + aaAbbr);
  }

  sqlite3_finalize(prepStatement);

  return results;

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

std::vector <char> DNAtoRNAbis(const std::string& filename)
{
  std::vector <char> inputs = ReadInputsFromFile(filename);
  int n = inputs.size();

  for(int i = 0; i<n; i++)
    {
      if(inputs[i] == 't')
        inputs[i] = 'u' ;
      else if(inputs[i] == 'T')
        inputs[i] = 'U';
    }
  
  return inputs;
}

  

std::vector <std::string> RNAtoAminoAcids(std::vector <char> RNAvector, int posStartCodon)
{
  std::vector <std::string> aminoAcids ; //Stock résultats
  myString codon;
  int n = aminoAcidsList.size();
  std::string interString;

  for(int i=posStartCodon; i<RNAvector.size()-posStartCodon; i+=3)
    {
      interString.push_back(RNAvector[i]) ;
      interString.push_back(RNAvector[i+1] );
      interString.push_back(RNAvector[i+2]);
      codon.setMyStringVar(interString) ;

      for(int j=0; j<n ; j++)
        {
          if(codon.isIn(aminoAcidsList[j].codonsList) == true)
            {
              aminoAcids.push_back(aminoAcidsList[j].aaAbbrForList);
              break;
            }
        }
      interString.clear();
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
    std::cerr << "Not able to find start codon" << std::endl ;
            

}


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