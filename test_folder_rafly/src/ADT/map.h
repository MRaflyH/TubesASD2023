#ifndef MAP_H
#define MAP_H

#include "set.h"

#define MaxCapacity 100
// #define ValUndef -1

typedef Word KeyType;
typedef Set ValType;

typedef struct { 
  KeyType Key;
  ValType Value;
} MapEntry;

typedef struct {
  MapEntry Content[MaxCapacity];
  int Length;
} Map;

void CreateM(Map *m);

boolean IsEmptyM(Map m);

boolean IsFullM(Map m);

boolean IsMemberM(Map m, KeyType k);

ValType ValueM(Map m, KeyType k);

void InsertM(Map *m, KeyType k, ValType v);

void DeleteM(Map *m, KeyType k);

void DisplayValueM(Map m, KeyType k);

void DisplayM(Map m);

#endif