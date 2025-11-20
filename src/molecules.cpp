//////////////////////////////
//DNA READER - MOLECULES.CPP//
//////////////////////////////

//LINKS//
#include "molecules.h"

///////////////
//C++ METHODS//
///////////////

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

std::vector <std::string> readInstructions(molecule m)
{
  std::vector <std::string> results;
  int instructionsSize = m.infos.buildInstructions.length();
  int numberOfInstructions = std::count(m.infos.buildInstructions.begin(), m.infos.buildInstructions.end(), ';') + 1 ;
  results.resize(numberOfInstructions);
  
  int instructionIndex = 0;
  std::string currentInstruction;

  char c;
  
  std::cout<<m.infos.buildInstructions<<std::endl;

  for(int i=0; i<instructionsSize; i++)
    {
      c = m.infos.buildInstructions[i];
      
      if(!isspace(static_cast<unsigned char>(c)) && c != ';')
        {
          currentInstruction.push_back(c);
        }

      else if(c == ';')
        {
          results[instructionIndex] = currentInstruction;
          currentInstruction.clear();
          instructionIndex += 1;
        }

      else if(isspace(static_cast<unsigned char>(c)))
        continue;


      else
        std::cerr << "Something went wrong when reading instructions" << std::endl;
      }
  
    
  
  if (!currentInstruction.empty() && instructionIndex < numberOfInstructions)
    {
        results[instructionIndex] = currentInstruction;
    }
  
  return results;
  
}


std::vector <std::string> readAAABInstruction(std::string instruction)
{
  std::vector <std::string> results;
  
  int size = instruction.size();
  
  std::string functionToCall;
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
          if(instruction[i]== ' ')
            stepDone = true ;
            
          else if(isalpha(instruction[i]) == true && doneWithFunctionToCall == false)
            {
                functionToCall.push_back(instruction[i]);

              if(instruction[i+1]=='(')
                doneWithFunctionToCall=true;
              
              stepDone = true ;
            }
            
          else if(isalpha(instruction[i]) == true && doneWithTypeOfBond == false)
            {
                typeOfBond.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithTypeOfBond=true;
              
              stepDone = true ;
            }
    
          else if(isalpha(instruction[i]) == true && doneWithAddedAtom == false)
            {
                addedAtom.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithAddedAtom=true;
              
              stepDone = true ;
            }
    
          else if(isalpha(instruction[i]) == true && doneWithOlderAtom == false)
            {
                olderAtom.push_back(instruction[i]);
    
              if(instruction[i+1]==',')
                doneWithOlderAtom=true;
              
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
  std::string aAtomSymbol;
  std::string oAtomId;

  int aAtomIndex;
  int oAtomIndex;

  bool oAtomExists = false;
  bool aAtomExists = false;


  sqlite3* pointerForElements = openSQLDataBase("elements.db");
  sqlite3* pointerForMolecules = openSQLDataBase("molecules.db");

  std::cout << "Ok" << std::endl;

  //Creation on first atom's Id : 
  resultsMolecule.atoms.push_back(putFirstAtom(instructionsVec));
  std::string newId = shortName + "_" + resultsMolecule.atoms[0].infos.elementSymbol + "_" + std::to_string(001);
  resultsMolecule.atoms[0].idInMolecule = newId;

  
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
      

      if(atomIndex(resultsMolecule.atoms, oAtomId) >= 0)
        {
          oAtomExists = true;
          oAtomIndex = atomIndex(resultsMolecule.atoms, oAtomId);
        }
        
      else
        throw std::runtime_error("Older atom does not exist, can't continue building"); 
      

      if(atomIndex(resultsMolecule.atoms, aAtomId) >= 0)
        {
          aAtomExists = true;
          aAtomIndex = atomIndex(resultsMolecule.atoms, aAtomId);
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
          resultsMolecule.atoms[oAtomIndex].bonds.push_back(resultsMolecule.electronicBondsList.back()); 

          //Adding the bond to the added atom
          resultsMolecule.atoms[aAtomIndex].bonds.push_back(resultsMolecule.electronicBondsList.back());
          
        }
          
      else if(oAtomExists==true && aAtomExists==false)
        {
          //Creation of the atom
          for(int i=0; i<aAtomId.size(); i++)
            {
              if(isalpha(aAtomId[i])==true)
                aAtomSymbol.push_back(aAtomId[i]);
              else
                break;
            }
          resultsMolecule.atoms.push_back(createAtom(aAtomSymbol));

          //Copy and paste of the instructions in the previous if
          //Creation of the bond
          resultsMolecule.electronicBondsList.push_back(addAnAtomicBond(tob, aAtomId, oAtomId));

          //Adding the bond to the older atom
          resultsMolecule.atoms[oAtomIndex].bonds.push_back(resultsMolecule.electronicBondsList.back());

          //Adding the bond to the added atom
          resultsMolecule.atoms[oAtomIndex].bonds.push_back(resultsMolecule.electronicBondsList.back());
        }
      
      else
        throw std::runtime_error("Something went wrong, can't continue building");

      }

  return resultsMolecule;
}

std::string createAtomId(std::string moleculeName, atom a, int n)
{
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

      tempMolecule.infos = getMoleculeFromDB(database, moleculeName);
      instructions = readInstructions(tempMolecule);
      
      results = preBuiltMolecule(instructions, moleculeName);
    }

  else if(methodChoice==2)
    results = buildFromScratch();

  else
    std::cerr << "Input is not valid" << std::endl;
 
  return results;
}

bool isAAABChar(char c)
{
  bool results = false;

  if(isalnum(c) == true || c=='_')
    results = true;

  return results
}

//MOLECULE OUTPUT//
void outputMolecule(molecule m)
{
  std::cout << "Molecule name : " << m.infos.moleculeName <<std::endl;

  std::cout << "Atoms list : " << std::endl;

  for(int i=0; i<m.atoms.size(); i++)
    {
      std::cout << m.atoms[i].infos.elementName << ", " << m.atoms[i].idInMolecule << std::endl;
    }

  std::cout<< " "<< std::endl;

  std::cout << "Electronic bonds list : " << std::endl;

  for(int i=0; i<m.electronicBondsList.size(); i++)
    {
      std::cout << m.electronicBondsList[i].atomId_1 << ", " << m.electronicBondsList[i].atomId_1 << std::endl;
    }  

  std::cout << "Done" << std::endl;
}