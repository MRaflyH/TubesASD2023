#ifndef SET_H
#define SET_H

#include "boolean.h"

#define MaxCapacity 100

typedef int ElType;

typedef struct {
  ElType Content[MaxCapacity];
  int Length;
} Set;

// CreateSet
// IsEmpty
// Length
// Add
// Remove
// IsIn
// IsEqual
// Union
// Intersection
// SetDifference
// Copy
// IsSubset

#endif