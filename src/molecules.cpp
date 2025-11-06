//////////////////////////////
//DNA READER - MOLECULES.CPP//
//////////////////////////////

//LINKS//
#include "molecules.h"

///////////////
//C++ METHODS//
///////////////

//MATHS//

myVector distanceVector(electron A, electron B)
{
  myVector results;

  results.size = distanceValue(A.atomPosition, B.atomPosition);

  results.x_vector = B.atomPosition.x - A.atomPosition.x ;
  results.y_vector = B.atomPosition.y - A.atomPosition.y ;
  results.z_vector = B.atomPosition.z - A.atomPosition.z ;

  return results;
}

double distanceValue(position A, position B)
{
  double results ;
  
  results = sqrt(pow((B.x-A.x), 2) + pow((B.y-A.y), 2) + pow((B.z-A.z),2));

  return results;
}


//ATOM CREATION//
atom createAtom();

//MOLECULE METHODS//
atom putFirstAtom(std::string symbol)
{

}

atom addAnAtomicBond(std::string symbol, std::string typeOfBond)
{

}

atom selectAnOtherAtom(std::string atomId)
{

}

molecule linkWith();
molecule separateFrom();

//MOLECULE BUILDING//
molecule buildMolecule()
{
  int methodChoice = 0;
  molecule results;
  
  std::cout << "Select what applies : " << std::endl;
  std::cout << "1. I know exactly what molecule I want" << std::endl;
  std::cout << "2. I want to build a molecule from scratch" <<std::endl;
  std::cout << "Please enter the NUMBER of what applies to you." << std::endl;

  std::cin>>methodChoice;

  if(methodChoice==1)
    results = preBuiltMolecule();

  else if()
    results = buildMoleculeFromScratch();

  else
    std::cerr << "Input is not valid" << std::endl;

  return results;
}

///////////////
//SQL METHODS//
///////////////

elementInfo getElementInfoFromDB(sqlite3* database, const std::string& symbol)
{

////VARIABLE DECLARATIONS////
  elementInfo results;
  
  const std::string sqlRequest = "SELECT elementSymbol, elementName, atomicNumber, protonNumber, atomicRadius, electronegativity FROM elements WHERE elementSymbol = ?;";

  sqlite3_stmt* prepStatement = NULL;

  int prepResult = sqlite3_prepare_v2(database, sqlRequest.c_str(), -1, &prepStatement, NULL);

  //Error handling//
  if (prepResult != SQLITE_OK) 
  {
    throw std::runtime_error("Failed to prepare SQL statement for element query");
  }
  //////////////////

  int bindResult = sqlite3_bind_text(prepStatement, 1, symbol.c_str(), -1, SQLITE_STATIC);

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
    results.elementSymbol = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 0));
    results.elementName = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 1));
    results.atomicNumber = sqlite3_column_int(prepStatement, 2);
    results.protonNumber = sqlite3_column_int(prepStatement, 3);
    results.atomicRadius = sqlite3_column_double(prepStatement, 4);
    results.electronegativity= sqlite3_column_double(prepStatement, 5);
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Element not found in database: " + symbol);
  }

  sqlite3_finalize(prepStatement);

  return results;

}


molecule getMoleculeFromDB(sqlite3* database, const int moleculeId)
{

////VARIABLE DECLARATIONS////
  molecule results;
  
  const std::string sqlRequest = "SELECT moleculeId, moleculeName, buildInstructions FROM molecules WHERE moleculeId = ?;";

  sqlite3_stmt* prepStatement = NULL;

  int prepResult = sqlite3_prepare_v2(database, sqlRequest.c_str(), -1, &prepStatement, NULL);

  //Error handling//
  if (prepResult != SQLITE_OK) 
  {
    throw std::runtime_error("Failed to prepare SQL statement for element query");
  }
  //////////////////

  int bindResult = sqlite3_bind_text(prepStatement, 1, moleculeId.c_str(), -1, SQLITE_STATIC);///NEEDS MODIFICATION

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
    results.moleculeId = sqlite3_column_text(prepStatement, 0);
    results.moleculeName = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 1));
    results.buildInstructions = reinterpret_cast<const char*>(sqlite3_column_int(prepStatement, 2));
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Element not found in database: " + symbol);
  }

  sqlite3_finalize(prepStatement);

  return results;

}

aminoAcidInfo getAminoAcidInfoFromDB(sqlite3* database, const std::string& aaAbbr)
{

////VARIABLE DECLARATIONS////
  aminoAcidInfo results;
  
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
    results.aaAbbr = reinterpret_cas<const char*>(sqlite3_column_text(prepStatement, 0));
    results.aaLetter = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 1));
    results.aaName = reinterpret_cast<const char*>(sqlite3_column_int(prepStatement, 2));
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Element not found in database: " + symbol);
  }

  sqlite3_finalize(prepStatement);

  return results;

}