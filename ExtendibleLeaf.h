//Evan Racah
//ExtendibleLeaf 

using namespace std;
#include "vector.h" //include after all other includes
class ExtendibleLeaf
{
public:
	ExtendibleLeaf(int LeafSize, int leadingBits);
	ExtendibleLeaf* insert(const int &object);
	void remove(const int &object);
  const int & find(const int &object);
  void split(const int &object);
  void setLeadingBits(int leadBits); //private?
  int getLeadingBits() 
  {
  	return leadingBits;
  } //get the number of leading bits
  const int & getFirstElement(); //returns first element in vector so calling object has an idea of whats in there
  //get a an element from a leaf or just the hashed leading bits of element in leaf?

private:
	vector<int> leaves;
	int LeafSize;
	int currentSize;
	int leadingBits; // the maximum number of leading bits that a leaf has in common
	//Extendibleleaf parent or way of seeing old hash key to leaf?
};

