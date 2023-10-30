#ifndef MAP_H
#define MAP_H

#include "boolean.h"

#define MaxCapacity 100
#define ValUndef -1

typedef int KeyType;
typedef int ElType;

typedef struct { 
  KeyType Key;
  ElType Value;
} MapEntry;

typedef struct {
  MapEntry Content[MaxCapacity];
  int Length;
} Map;

void CreateEmpty(Map *M);

boolean IsEmpty(Map M);

boolean IsFull(Map M);

ElType Value(Map M, KeyType k);

void Insert(Map *M, KeyType k, ElType v);

void Delete(Map *M, KeyType k);

boolean IsMember(Map M, KeyType k);

#endif