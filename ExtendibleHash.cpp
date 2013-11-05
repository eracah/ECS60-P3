#include "ExtendibleHash.h"
using namespace std;



int Ehash(int value, int bits)  //oh a non member function
{
  return value >> (18 - bits);
} // Ehash()

ExtendibleHash::ExtendibleHash(const int & notFound, int b, int LSize) :
  bits(b), LeafSize(LSize)
{

} // ExtendibleHash()

void ExtendibleHash::insert(const int &object)
{
	
} // insert()


void ExtendibleHash::remove(const int &object)
{
}  // remove()


const int & ExtendibleHash::find(const int &object)
{
	return 0;
}  // find()



void ExtendibleHash::split(const int &object)
{
 
}  // split()


