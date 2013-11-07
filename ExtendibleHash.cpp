
using namespace std;



int Ehash(int value, int bits)  //oh a non member function
{
  return value >> (18 - bits);
} // Ehash()

ExtendibleHash::ExtendibleHash(const int & notFound, int b, int LSize) :
  bits(b), LeafSize(LSize)
{
	int ptrIndex;
	ExtendibleLeaf * firstLeafPtr= new ExtendibleLeaf(LeafSize,1);

	//resize to a size of 2^bits
	Directory.resize(2 << bits);

	//set all ptrIndexs in directory to firstLeafPtr
	for(ptrIndex = 0; ptrIndex < Directory.size(); ptrIndex++)
	{
		Directory[ptrIndex] = firstLeafPtr;
	}



} // ExtendibleHash()

void ExtendibleHash::insert(const int &object)
{
	ExtendibleLeaf *newLeaf = NULL;

	//call insert on leaf that has a key equal to hash of object
	newLeaf = (Directory[Ehash(object,bits)]).insert(object);

	if(newLeaf!=NULL) //Leaf was split
	{
		if
	}//if

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


