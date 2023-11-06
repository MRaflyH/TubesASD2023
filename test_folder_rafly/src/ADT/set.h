#ifndef SET_H
#define SET_H

#include "kata.h"

#define MaxCapacity 100

typedef Word ElType;

typedef struct {
  ElType Content[MaxCapacity];
  int Length;
} Set;

void CreateSet(Set *s);

boolean IsEmptySet(Set *s);

boolean IsMemberSet(Set s, ElType x);

void AddSet(Set *s, ElType x);

void DeleteSet(Set *s, ElType x);

void GetSet(Set s, int i);

void DisplaySet(Set s);

void CopySet(Set source, Set * dest);

#endif