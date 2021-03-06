// Author: Sean Davis
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring> //clever so he can use strtok
#include "ExtendibleHash.h"

using namespace std;
int main(int argc, char* argv[])
// argv[1] is data filename in the form: "Hash-" Maxsize "-" LeafSize "-"
//             StartBits "-" Seed ".dat"
{
  char command;
  int value, value2, StartBits, LeafSize;

  ifstream inf(argv[1]);
  strtok(argv[1], "-");
  strtok(NULL, "-");
  LeafSize = atoi(strtok(NULL, "-"));
  StartBits = atoi(strtok(NULL, "-"));
  ExtendibleHash  hash(-1, StartBits, LeafSize);

  while(inf >> command)
  {
    inf >> value;
    switch(command)
    {
      case 'i' : hash.insert(value); break;
      case 'd' : hash.remove(value); break;
      case 'f' :
        inf >> value2;
        if(value2 != hash.find(value)) //??? what?? if -1 doesnt equal
          cout << "Bad find: Sought:" << value << " returned: " << hash.find(value) << endl;
        else
          cout << "Good find: Sought: " << value << " returned: "<< hash.find(value) << endl;
        break;
        
      case 'b' :
        if(value != hash.GetBits())
          cout << "Bad bits: Expected: " << value << " got: " << hash.GetBits() << endl;
        else
          cout << "Good bits: " << hash.GetBits() << endl;
        break;
    } // switch
  } // while more in file
  return 0;
} // main()
