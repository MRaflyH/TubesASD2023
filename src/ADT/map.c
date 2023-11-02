#include <stdio.h>
#include "map.h"

void CreateM(Map *m) {
    (*m).Length = 0;
}

boolean IsEmptyM(Map m) {
    return (m.Length == 0);
}

boolean IsFull(Map m) {
    return (m.Length == MaxCapacity);
}

boolean IsMember(Map m, KeyType k) {
    int i;
    for (i = 0; i < m.Length; i++) {
        if (m.Content[i].Key == k) {
            return true;
        }
    }
    return false;
}

ElType Value(Map m, KeyType k) {
    int i;
    for (i = 0; i < m.Length; i++) {
        if (m.Content[i].Key == k) {
            return m.Content[i].Value;
        }
    }
    return ValUndef;
}

void Insert(Map *m, KeyType k, ElType v) {
    if (!IsFull(*m) && !IsMember(*m, k)) {
        (*m).Content[(*m).Length].Key = k;
        (*m).Content[(*m).Length].Value = v;
        (*m).Length++;
    }
}

void Delete(Map *m, KeyType k) {
    int i;
    for (i = 0; i < (*m).Length; i++) {
        if ((*m).Content[i].Key == k) {
            (*m).Content[i] = (*m).Content[(*m).Length - 1];
            (*m).Length--;
            return;
        }
    }
}