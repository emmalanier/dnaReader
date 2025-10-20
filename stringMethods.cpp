////////////////////////////////
//DEFINITION OF STRING METHODS//
////////////////////////////////

//LINK//
#include "stringHeader.h"

////////////////////////////////
//CONSTRUCTORS, GETTER, SETTER//
////////////////////////////////
myString::myString()
{
  myStringVar = " ";
}

myString::myString(const std::string & str)
{
  myStringVar = str ;
}

std::string myString::getMyStringVar()
{
  return myStringVar ;
}

void myString::setMyStringVar(const std::string & str)
{
  myStringVar = str ;
}


////////////////////////
//STRING MODIFICATIONS//
////////////////////////
std::string myString::lowerToUpper()
{
  std::string results;
  int chainSize = myStringVar.length();

  for (int i=0; i<chainSize; i ++)
    {
      results += std::toupper(myStringVar[i]);
    }

  return results;
}

std::string myString::upperToLower()
{
  std::string results;
  int chainSize = myStringVar.length();

  for (int i=0; i<chainSize; i ++)
    {
      results += std::tolower(myStringVar[i]);
    }

  return results;
}
