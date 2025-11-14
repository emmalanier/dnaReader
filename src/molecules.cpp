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
atom putFirstAtom(std::vector <std::string> instructions)//Inaccurate, needs modifications
{
  atom results;
  std::string symbol;
  bool start = false;

  //Getting the symbol
  for(int i=0; i<instructions[0].size(); i++)
    {
      if(instructions[0][i] == '(')
        start = true;

      if(instructions[0][i] != '(' && start == true && instructions[0][i] != ')')
        symbol.push_back(instructions[0][i]);

      if(instructions[0][i] != ')')
        break;
    }
  
  results = createAtom(symbol);
  results.atomPosition = {0, 0, 0};

  return results;

}

electronicBond addAnAtomicBond(std::string typeOfBond, std::string aAtomId, std::string oAtomId)
{
  electronicBond newBond;
  
  newBond.bondType = typeOfBond;
  newBond.atomId_1 = oAtomId;
  newBond.atomId_2 = aAtomId;

//With this method, the atom #1 is considered to be the old atom, and the #2 to be the one just added

  return newBond;
}

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


std::vector <std::string> readAAABInstruction(std::string instruction)
{
  std::vector <std::string> results;
  
  int size = instruction.size();
  
  std::string functionToCall = " ";
  bool doneWithFunctionToCall = false;
  
  std::string typeOfBond = " ";
  bool doneWithTypeOfBond = false;
  
  std::string addedAtom = " ";
  bool doneWithAddedAtom = false;
  
  std::string olderAtom = " ";
  bool doneWithOlderAtom = false;

  bool stepDone = false;

  for(int i=0; i<size; i++)
    {
      stepDone = false ;
      
      while(stepDone != true)
        {
          if(instruction[i]= ' ')
            stepDone = true ;
            
          else if(isalpha(instruction[i]) == true && doneWithFunctionToCall == false)
            {
              if(functionToCall[0] == ' ')
                functionToCall[0] = instruction[i];

              else
                functionToCall.push_back(instruction[i]);

              if(instruction[i+1]=='(')
                doneWithFunctionToCall==true;
              
              stepDone = true ;
            }
            
          else if(isalpha(instruction[i]) == true && doneWithTypeOfBond == false)
            {
              if(typeOfBond == " ")
                typeOfBond[0] = instruction[i];

              else
                typeOfBond.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithTypeOfBond==true;
              
              stepDone = true ;
            }
    
          else if(isalpha(instruction[i]) == true && doneWithAddedAtom == false)
            {
              if(addedAtom[0] == ' ')
                addedAtom[0] = instruction[i];

              else
                addedAtom.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithAddedAtom==true;
              
              stepDone = true ;
            }
    
          else if(isalpha(instruction[i]) == true && doneWithOlderAtom == false)
            {
              if(olderAtom[0] == ' ')
                olderAtom[0] = instruction[i];

              else
                olderAtom.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithOlderAtom==true;
              
              stepDone = true ;
            }

//          else if(instruction[i]= ')')
//            {
    
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

  results = {functionToCall, "(", typeOfBond, addedAtom, olderAtom, ")"} ;

  return results;
}

  

atom selectAnOtherAtom(std::string atomId)
{

}

molecule linkWith();
molecule separateFrom();



//MOLECULE BUILDING//
molecule preBuiltMolecule(std::vector <std::string> instructionsVec, std::string name)
{
  std::vector <atom> results;
  molecule resultsMolecule;
  int numberOfInstructions = instructionsVec.size();

  //Var for reading instructions
  std::string instruction;
  std::vector <std::string> instructionElements;

  //Var for making Ids
  std::string shortName = {name[0], name[1], name[2]};
  int atomNumber = 0;

  //var for the aaab method
  std::string tob;
  std::string aAtomId;
  std::string oAtomId;

  int aAtomIndex;
  int oAtomIndex;

  bool oAtomExists = false;
  bool aAtomExists = false;

  //Creation on first atom's Id :
  results[0] = putFirstAtom(instructionsVec);
  std::string newId = shortName + "_" + std::to_string(0);
  results[0].idInMolecule = newId;

  
  //Adding other atoms
  for(int i=1; i<numberOfInstructions; i++)
    {
      //Reading current instruction
      instruction = instructionsVec[i];

      instructionElements = readAAABInstruction(instructionsVec[i]);

      
      if(instructionElements[0] == "AAAB" || instructionElements[0] == "aaab")
        {
          tob = instructionElements[2];
          aAtomId = instructionElements[3];
          oAtomId = instructionElements[4];
        }
          
      else
        std::cerr << "Couldn't read instruction #" << i+1 << std::endl;
      

      if(atomIndex(results, oAtomId) >= 0)
        {
          oAtomExists = true;
          oAtomIndex = atomIndex(results, oAtomId);
        }
        
      else
        throw std::runtime_error("Older atom does not exist, can't continue building");
      

      if(atomIndex(results, aAtomId) >= 0)
        {
          aAtomExists = true;
          aAtomIndex = atomIndex(results, aAtomId);
        }

      //Different cases :
      // 1 : older atom's Id is not found, program will stop (already implemented)
      // 2 : older atom's Id exists, added atom's Id exists : an electronic bond will be added
      // 3 : older atom's Id exists, added atom's Id does not exist : an atom + an electronic bound will be created
      if(oAtomExists==true && aAtomExists==true)
        {
          //Creation of the bond
          resultsMolecule.electronicBondsList.push_back(addAnAtomicBond(tob, aAtomId, oAtomId));

          //Adding the bond to the older atom
          results[oAtomIndex].bonds.push_back(resultsMolecule.electronicBondsList.back());

          //Adding the bond to the added atom
          results[oAtomIndex].bonds.push_back(resultsMolecule.electronicBondsList.back());
          
        }
          
      else if(oAtomExists==true && aAtomExists==false)
        {
          //Creation of the atom

          //Adding the atom to the molecule list

          //Copy and paste of the instructions in the previous if
        }
      
      else
        throw std::runtime_error("Something went wrong, can't continue building");

      }


  return resultsMolecule;
}

  
int atomIndex(std::vector <atom> atomVec, std::string id)
{
  int results = -1;
  int sizeOfVec = atomVec.size();
  bool atomFound = false;

  for(int i=0; i<sizeOfVec && atomFound == false ; i++)
    {
      if(atomVec[i].idInMolecule == id)
        {
          atomFound = true;
          results = i;
        }
    }

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
  molecule tempMolecule;
  molecule results;
  std::vector <std::string> instructions;
  std::string moleculeName;
  
  std::cout << "Select what applies : " << std::endl;
  std::cout << "1. I know exactly what molecule I want" << std::endl;
  std::cout << "2. I want to build a molecule from scratch" <<std::endl;
  std::cout << "Please enter the NUMBER of what applies to you." << std::endl;

  std::cin>>methodChoice;

  if(methodChoice==1)
    {
      std::cout << "Enter the name of the molecule you want" << std::endl;
      std::cin >> moleculeName;

      sqlite3* database = nullptr;
      int result = sqlite3_open("molecules.db", &database);

      if (result != SQLITE_OK) 
      {
        std::cerr << "Error opening database: " << sqlite3_errmsg(database) << std::endl;
      }

      tempMolecule = getMoleculeFromDB(database, moleculeName);
      instructions = readInstructions(tempMolecule);
      
      results = preBuiltMolecule(instructions, moleculeName);
    }

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


molecule getMoleculeFromDB(sqlite3* database, const std::string& moleculeName)
{

////VARIABLE DECLARATIONS////
  molecule results;
  
  const std::string sqlRequest = "SELECT moleculeName, moleculeId, buildInstructions FROM molecules WHERE moleculeName = ?;";

  sqlite3_stmt* prepStatement = NULL;

  int prepResult = sqlite3_prepare_v2(database, sqlRequest.c_str(), -1, &prepStatement, NULL);

  //Error handling//
  if (prepResult != SQLITE_OK) 
  {
    throw std::runtime_error("Failed to prepare SQL statement for element query");
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
    results.buildInstructions = reinterpret_cast<const char*>(sqlite3_column_int(prepStatement, 2));
  }

  else 
  {
    sqlite3_finalize(prepStatement);
    throw std::runtime_error("Element not found in database: " + moleculeName);
  }

  sqlite3_finalize(prepStatement);

  return results;

}