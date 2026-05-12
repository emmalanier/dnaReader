////////////////////////////////////////////
//TEMPLATE DECLARATIONS FOR STRING METHODS//
////////////////////////////////////////////

#pragma once

////////////
//INCLUDES//
////////////
#include "stringHeader.h"

///////////
//CONTENT//
///////////

//TO CHECK IF A STRING IS IN A CONTAINER//
template <typename container>
bool myString::isIn(const container & vec) const
{
  bool results = false;

  for(int i=0; i<vec.size(); i++)
    {
      if(myStringVar==vec[i])
        {
          results = true;
          break;
        }
    }

  return results ;

}