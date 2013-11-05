//Evan Racah
//ExtendibleLeaf 

using namespace std;
#include "vector.h" //include after all other includes
class ExtendibleLeaf
{
public:
	ExtendibleLeaf(int LeafSize);
	ExtendibleLeaf* insert(const int &object);
	void remove(const int &object);
  const int & find(const int &object);
  void split(const int &object);

private:
	vector<int> leaves;
	int LeafSize;
	int currentSize;
};