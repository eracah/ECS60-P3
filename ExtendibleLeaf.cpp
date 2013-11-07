//Evan Racah
//Extendible leaf implementations

	//forward declaration
	int Ehash(int value, int bits);

	ExtendibleLeaf::ExtendibleLeaf(int LSize, int LBits):
	LeafSize(LSize),leadingBits(LBits)
	{
		currentSize=0;
		notFound=-1;
		leaves.resize(LeafSize);
	}//ExtendibleLeaf::ExtendibleLeaf
	ExtendibleLeaf* ExtendibleLeaf::insert(const int &object)
	{
		ExtendibleLeaf *newLeaf=NULL;

		if(currentSize < LeafSize)
			leaves[currentSize++] = object;
		else
			newLeaf = split(object);
		return newLeaf;
	}//ExtendibleLeaf::insert

	void ExtendibleLeaf::remove(const int &object)
	{
		int index = findIndex(object);

		//make the value at this index equal the last value in vector
		leaves[index]=leaves[currentSize-1];

		//leazy deletion the size is decremented
		currentSize--;
	}//ExtendibleLeaf::remove(const int &object)
  const int & ExtendibleLeaf::find(const int &object)
  {
  	int index = findIndex(object);
  	if(index==notFound)
  		return notFound;
  	else
  		return leaves[index];
  }//ExtendibleLeaf::find(const int &object)

  int ExtendibleLeaf::findIndex(const int &object)
  {
  	int index=0,found = 0;

  	

  	while(index<currentSize && !found)
  	{
  		if(leaves[index]==object)
  			found = 1;
  		else
  			index++;

  	}
  	
  	if(!found)
  		return notFound;
  	else
  		return index;
  }//ExtendibleLeaf::findIndex
  ExtendibleLeaf* ExtendibleLeaf::split(const int &object)
  {
  	int key;
  	int valueIndex;
  	//make it have the current leadingBits of this leaf, but the number will probably increase
  	ExtendibleLeaf *newLeaf=new ExtendibleLeaf(LeafSize,leadingBits);
  	int Bits=leadingBits-1; //juts because incremented at start of loop

  	//while we have not hashed past the number bits we can hash to
  	//and nothing has been differentiated enough to be moved to new leaf
  	while(Bits < 18 && newLeaf->getSize()==0) 
  	{
  		Bits++;
  		//key will be the hashed value of first element in leaf
  		key = Ehash(this -> getFirstElement(),Bits);
  		if(Ehash(object,Bits)!=key)
  			newLeaf -> insert(object);
  		
  		//loop through elements backwards, so removal process does not mess up
  		//indexing for checking ie we will always be passed an index that changes 
  		//value due to deletion and when current size changes due to deletion
  		//we do not need it anymore because it was just a starting point
  		for(valueIndex = currentSize-1; valueIndex > 0; valueIndex--)
  		{
  			if(Ehash(leaves[valueIndex],Bits)!=key) // element different than key
  			{
  				newLeaf -> insert(leaves[valueIndex]);
  				remove(leaves[valueIndex]);
  			}//if

				
  		}//for

  	}//while

  	if (Bits>=18)
  		cout<<"Error!"<<endl;

  	//set the new leading bits for this leaf and newleaf
  	leadingBits=Bits;
  	newLeaf ->setLeadingBits(Bits);

  	return newLeaf;


  }//ExtendibleLeaf::split(const int &object)

  void ExtendibleLeaf::setLeadingBits(int leadBits)
  {
  	leadingBits = leadBits;
  }//ExtendibleLeaf::setLeadingBits(int leadBits)
	const int & ExtendibleLeaf::getFirstElement()
	{
		return leaves[0];
	}//ExtendibleLeaf::getFirstElement()




