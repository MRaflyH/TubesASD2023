#include <stdio.h>
#include "set.h"
#include "mesinkata.h"
void CreateSet(Set *s){
    (*s).Length = 0;
}

boolean IsEmptySet(Set *s){
    return (*s).Length == 0;
}

boolean isMember(Set s, ElType x){
    for (int i =0; i < s.Length; i++){
        if (IsWordSame((s).Content[i],x)){
            return true;
        }
    }
    return false;
}

void AddSet(Set *s, ElType x){
    int i;
    boolean found = false;
    for (i = 0; i < (*s).Length; i++){
        if (IsWordSame((*s).Content[i],x)){
            found = true;
            break;
        }
    }
    if (!found){
        PasteWord(x ,&(*s).Content[i]);
        (*s).Length++;
    }
}

void DeleteSet(Set *s, ElType x){
    int i;
    boolean found = false;
    for (i = 0; i < (*s).Length; i++){
        if (IsWordSame((*s).Content[i],x)){
            found = true;
            break;
        }
    }
    if (found){
        for (int j = i; j < (*s).Length - 1; j++){
            PasteWord((*s).Content[j+1] ,&(*s).Content[j]);
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
    if (IsEmptySet(&s)){
        printf("kosong");
    } else{
        for (int i = 0; i < s.Length; i++){
            printf("%d\n", s.Content[i]);
        }
    }
}