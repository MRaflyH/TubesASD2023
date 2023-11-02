#include <stdio.h>
#include "set.h"

void CreateSet(Set *s){
    (*s).Length = 0;
}

boolean IsEmptySet(Set *s){
    return (*s).Length == 0;
}

boolean isMember(Set s, ElType x){
    for (int i =0; i < s.Length; i++){
        if (s.Content[i] == x){
            return true;
        }
    }
    return false;
}

void AddSet(Set *s, ElType x){
    int i;
    boolean found = false;
    for (i = 0; i < (*s).Length; i++){
        if ((*s).Content[i] == x){
            found = true;
            break;
        }
    }
    if (!found){
        (*s).Content[i] = x;
        (*s).Length++;
    }
}

void DeleteSet(Set *s, ElType x){
    int i;
    boolean found = false;
    for (i = 0; i < (*s).Length; i++){
        if ((*s).Content[i] == x){
            found = true;
            break;
        }
    }
    if (found){
        for (int j = i; j < (*s).Length - 1; j++){
            (*s).Content[j] = (*s).Content[j+1];
        }
        (*s).Length--;
    }
}

void GetSet(Set s, int i){
    if (i < (s).Length){
        printf("%d\n", (s).Content[i]);
    }
}

void DisplaySet(Set s){
    for (int i = 0; i < s.Length; i++){
        printf("%d\n", s.Content[i]);
    }
}