//////////////////////////////
//DNA READER - MOLECULES.CPP//
//////////////////////////////

//LINKS//
#include "molecules.h"

///////////////
//C++ METHODS//
///////////////

//MATHS//

myVector distanceVector(position A, position B)
{
  myVector results;

  results.size = distanceValue(A, B);

  results.x_vector = B.x - A.x ;
  results.y_vector = B.y - A.y ;
  results.z_vector = B.z - A.z ;

  return results;
}

double distanceValue(position A, position B)
{
  double results ;
  
  results = sqrt(pow((B.x-A.x), 2) + pow((B.y-A.y), 2) + pow((B.z-A.z),2));

  return results;
}


//ATOM CREATION//
atom createAtom(std::string atomSymbol)
{
  atom results ;
  
  sqlite3* database = nullptr;
  int result = sqlite3_open("elements.db", &database);

  if (result != SQLITE_OK) 
  {
    std::cerr << "Error opening database: " << sqlite3_errmsg(database) << std::endl;
  }

  results.infos = getElementInfoFromDB(database, atomSymbol);

  return results;
  
}

//MOLECULE METHODS//
atom putFirstAtom(std::string symbol)
{
  atom results;
  results = createAtom(symbol);
  results.atomPosition = {0, 0, 0};
  return results;

}

void addAnAtomicBond(std::string typeOfBond, atom addedAtom, atom olderAtom)
{
  electronicBond newBond;
  newBond.bondType = typeOfBond;
  newBond.olderAtomId = olderAtom.idInMolecule;
  newBond.addedAtomId = addedAtom.idInMolecule;
  olderAtom.electronicBondsList.push_back(newBond);
  addedAtom.electronicBondsList.push_back(newBond);
}

std::vector <std::string> readAAABInstruction(std::string instruction)
{
  std::vector <std::string> results;
  
  int size = instruction.size();
  
  std::string functionToCall = NULL;
  bool doneWithFunctionToCall = false;
  
  std::string typeOfBond;
  bool doneWithTypeOfBond = false;
  
  std::string addedAtom;
  bool doneWithAddedAtom = false;
  
  std::string olderAtom;
  bool doneWithOlderAtom = false;

  bool stepDone = false;

  for(int i=0; i<size; i++)
    {
      stepDone = false ;
      
      while(stepDone != true)
        {
          if(instruction[i]= ' ' || instruction[i]= ')')
            stepDone = true ;
            
          else if(isalpha(instruction[i]) == true && doneWithFunctionToCall == false)
            {
              functionToCall.push_back(instruction[i]);
    
              if(instruction[i+1]=='(')
                doneWithFunctionToCall==true;
              
              stepDone = true ;
            }
            
          else if(isalpha(instruction[i]) == true && doneWithTypeOfBond == false)
            {
              typeOfBond.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithTypeOfBond==true;
              
              stepDone = true ;
            }
    
          else if(isalpha(instruction[i]) == true && doneWithAddedAtom == false)
            {
              typeOfBond.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithAddedAtom==true;
              
              stepDone = true ;
            }
    
          else if(isalpha(instruction[i]) == true && doneWithOlderAtom == false)
            {
              typeOfBond.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithOlderAtom==true;
              
              stepDone = true ;
            }
    
          else if(doneWithFunctionToCall==true && doneWithTypeOfBond == true && doneWithAddedAtom == true && doneWithOlderAtom == true)
            {
              std::cout << "Build instructions read" << std::endl;
              stepDone = true ;
            }
    
          else
            {
              std::cerr << "Couldn't read build instructions" << std::endl;
              stepDone = true ;
            }
          }
      }

  return results;
}

  

atom selectAnOtherAtom(std::string atomId)
{

}

molecule linkWith();
molecule separateFrom();

std::vector <std::string> readInstructions(molecule m)//Must implement handling of the ';' char
{
  std::vector <std::string> results;
  int instructionsSize = m.buildInstructions.size();
  int numberOfInstructions ;
  bool newInstruction ;

  for(int i=0; i<instructionsSize; i++)
    {
      if(m.buildInstructions[i] != ' ' && newInstruction == true)
        {
          results[numberOfInstructions].push_back(m.buildInstructions[i]) ;
          newInstruction = false;
          numberOfInstructions += 1;
        }

      else if(m.buildInstructions[i] != ' ' && newInstruction == false)
        {
          results[numberOfInstructions].push_back(m.buildInstructions[i]);
          newInstruction == false;
        }

      else if(m.buildInstructions[i] == ' ')
        newInstruction == true;

      else
        std::cerr << "Something went wrong when reading instructions" << std::endl;
      }
  
}


//MOLECULE BUILDING//
molecule preBuiltMolecule(std::vector <std::string> instructionsVec)
{
  molecule results;
  int numberOfInstructions = instructionsVec.size();
  std::string instruction;

  for(int i=0; i<numberOfInstructions; i++)
    {
      readAAABInstr
      if()

      else
        std::cerr << "Couldn't read instruction #" << i+1 << std::endl;

  return results;
}

molecule buildFromScratch()
{
  molecule results;

  return results;
}

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

  else if(methodChoice==2)
    results = buildFromScratch();

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


molecule getMoleculeFromDB(sqlite3* database, const std::string& moleculeId)
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

  int bindResult = sqlite3_bind_text(prepStatement, 1, moleculeId.c_str(), -1, SQLITE_STATIC);///Should work

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
    results.moleculeId = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 0));
    results.moleculeName = reinterpret_cast<const char*>(sqlite3_column_text(prepStatement, 1));
    results.buildInstructions = reinterpret_cast<const char*>(sqlite3_column_int(prepStatement, 2));
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Element not found in database: " + moleculeId);
  }

  sqlite3_finalize(prepStatement);

  return results;

}