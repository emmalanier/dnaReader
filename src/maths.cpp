//////////////////////////
//DNA READER - MATHS.CPP//
//////////////////////////

#include "maths.h"

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