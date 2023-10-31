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

void CreateM(Map *m);

boolean IsEmptyM(Map m);

boolean IsFull(Map m);

boolean IsMember(Map m, KeyType k);
// check kalau ada keytype

ElType Value(Map m, KeyType k);
// return value dari key, kalau key gaada, ValUndef

void Insert(Map *m, KeyType k, ElType v);
// kalau udah ada keynya, replace

void Delete(Map *m, KeyType k);

#endif