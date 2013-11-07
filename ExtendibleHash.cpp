




int Ehash(int value, int bits)  //oh a non member function
{
  return value >> (18 - bits);
} // Ehash()

ExtendibleHash::ExtendibleHash(const int & notFound, int b, int LSize):
  bits(b), LeafSize(LSize), notFound(notFound)
{
	int ptrIndex;
	ExtendibleLeaf * firstLeafPtr= new ExtendibleLeaf(LeafSize,1);

	//resize to a size of 2^bits
	Directory.resize(1 << bits);

	//set all ptrIndexs in directory to firstLeafPtr
	for(ptrIndex = 0; ptrIndex < Directory.size(); ptrIndex++)
	{
		Directory[ptrIndex] = firstLeafPtr;
	}



} // ExtendibleHash()

void ExtendibleHash::insert(const int &object)
{
	ExtendibleLeaf *newLeaf = NULL;
	int oldBits=bits;
	int ptrIndex;
	//call insert on leaf that has a key equal to hash of object
	newLeaf = (Directory[Ehash(object,bits)])->insert(object);

	if(newLeaf != NULL) //Leaf was split
	{
		if(newLeaf -> getLeadingBits() <= bits) //no need to rehash new leaf leading bits still less than directory's bits
			updatePtr(newLeaf);
		else //newleaf's leading bits>bits
		{
			//change current bits to leadingbits of new leaf
			bits = newLeaf -> getLeadingBits();

			//rehash directory
			Directory.resize(1<<bits);

			//go thru directory backwards and uodate pointers to leaves
			ptrIndex = (1<<oldBits)-1;
			while(ptrIndex >= 0)
			{
				updatePtr(Directory[ptrIndex--]);
			}//while

			//update new leaf's pointer
			updatePtr(newLeaf);

		}//else
			

	}//if

} // insert()


void ExtendibleHash::remove(const int &object)
{
	//call remove for leaf that this object would be in if it existed
	Directory[Ehash(object,bits)] -> remove(object);
}  // remove()


const int & ExtendibleHash::find(const int &object)
{
	

	soughtValue=Directory[Ehash(object,bits)] -> find(object);

	if(soughtValue==-1)
		return notFound;
	else
		return soughtValue;
}  // find()



void ExtendibleHash::split(const int &object)
{
 
}  // split()

void ExtendibleHash::updatePtr(ExtendibleLeaf* Leaf)
{
	int ptrIndex;
	int leadBits=Leaf -> getLeadingBits();
	
	//get difference in bits 
	int bitDiff = bits - leadBits;
	int hashedValue=Ehash(Leaf->getFirstElement(),leadBits);

	if (bitDiff < 0)
		cout<<"ERROR"<<endl;

	//make every pointer indexed by a key that asscoaies with this leaf be a pointer to this leaf
	for(ptrIndex = hashedValue; ptrIndex < hashedValue+(1<<bitDiff); ptrIndex++)
		Directory[ptrIndex] = Leaf;


}


