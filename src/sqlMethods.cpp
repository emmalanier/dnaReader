///////////////////////////////
//DNA READER - SQLMETHODS.CPP//
///////////////////////////////

#include "molecules.h"


sqlite3* openSQLDataBase(const char* filename)
{
  sqlite3* results = nullptr;

  int dbOpen = sqlite3_open(filename, &results);

  if (dbOpen != SQLITE_OK) 
  {
    throw std::runtime_error("Couldn't open the database");
  }

  std::cout << "Database opened successfully!" << std::endl;

  return results;
}

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

/*moleculeInfo getMoleculeFromDB(sqlite3* database, const std::string& moleculeName)
{

////VARIABLE DECLARATIONS////
  moleculeInfo results;
  
  const std::string sqlRequest = "SELECT moleculeName, moleculeId, buildInstructions FROM molecules WHERE moleculeName = ?;";

  sqlite3_stmt* prepStatement = NULL;

  int prepResult = sqlite3_prepare_v2(database, sqlRequest.c_str(), -1, &prepStatement, NULL);

  //Error handling//
  if (prepResult != SQLITE_OK) 
  {
    std::string err = sqlite3_errmsg(database);
    throw std::runtime_error("Failed to prepare SQL statement for molecule query" + err);
  }
  //////////////////

  int bindResult = sqlite3_bind_text(prepStatement, 1, moleculeName.c_str(), -1, SQLITE_STATIC);///Should work

  //Error handling//
  if (bindResult != SQLITE_OK) 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Failed to bind moleculeId parameter");
  }
  //////////////////

  int stepResult = sqlite3_step(prepStatement);


////ACTUAL METHOD////
  if (stepResult == SQLITE_ROW)
  {
    results.moleculeName = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 0));
    results.moleculeId = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 1));
    results.buildInstructions = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 2));
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Element not found in database: " + moleculeName);
  }

  sqlite3_finalize(prepStatement);

  return results;

}*/

std::vector<std::string> get_amino_acid_from_db(sqlite3* database, const std::string& aa_abbr)
{

////VARIABLE DECLARATIONS////
  std::vector<std::string> results;
  
  const std::string sqlRequest = "SELECT aa_abbr, aa_letter, aa_name, aa_molecule_id, aa_InChI, aa_SMILES, aa_IUPAC FROM amino_acids WHERE aa_abbr = ?;";

  sqlite3_stmt* prepStatement = NULL;

  int prepResult = sqlite3_prepare_v2(database, sqlRequest.c_str(), -1, &prepStatement, NULL);

  //Error handling//
  if (prepResult != SQLITE_OK) 
  {
    std::string err = sqlite3_errmsg(database);
    throw std::runtime_error("Failed to prepare SQL statement for molecule query" + err);
  }
  //////////////////

  int bindResult = sqlite3_bind_text(prepStatement, 1, aa_abbr.c_str(), -1, SQLITE_STATIC);///Should work

  //Error handling//
  if (bindResult != SQLITE_OK) 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Failed to bind amino acid abbreviation parameter");
  }
  //////////////////

  int stepResult = sqlite3_step(prepStatement);


////ACTUAL METHOD////
  if (stepResult == SQLITE_ROW)
  {
    results.push_back(reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 0)));
    results.push_back(reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 1)));
    results.push_back(reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 2)));
    results.push_back(reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 3)));
    results.push_back(reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 4)));
    results.push_back(reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 5)));
    results.push_back(reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 6)));
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Amino acid not found in database: " + aa_abbr);
  }

  sqlite3_finalize(prepStatement);

  return results;

}