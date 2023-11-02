#ifndef SET_H
#define SET_H

#include "boolean.h"

#define MaxCapacity 100

typedef int ElType;

typedef struct {
  ElType Content[MaxCapacity];
  int Length;
} Set;

void CreateSet(Set *s);

boolean IsEmptySet(Set *s);

boolean isMember(Set s, ElType x);

void AddSet(Set *s, ElType x);

void DeleteSet(Set *s, ElType x);

void GetSet(Set s, int i);

void DisplaySet(Set s);
// Mungkin kosong = "kosong"
// 1. Pink Venom
// 2. Shut Down
// 3. Typa Girl
// 4. Yeah Yeah Yeah
// 5. Hard to Love
// 6. The Happiest Girl
// 7. Tally
// 8. Ready for Love

#endif