#ifndef EXTENDIBLE_HASH_H
  #define EXTENDIBLE_HASH_H

#include "ExtendibleLeaf.h"
#include "vector"

class ExtendibleHash
{
  vector<ExtendibleLeaf *> Directory;
  int bits;
  int size;
  int LeafSize;

public:
  ExtendibleHash(const int & notFound, int s, int LSize = 2);
  void insert(const int &object);
  void remove(const int &object);
  const int & find(const int &object); //why the reference here? save from copying?
  void split(const int &object);   //resizes vector?????????
  int GetBits()const {return bits;}

}; // class ExtendibleHashing

#include "ExtendibleHash.cpp"

#endif

