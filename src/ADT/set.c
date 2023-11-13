#include "set.h"

void CreateSet(Set *s){
    (*s).Length = 0;
}

boolean IsEmptySet(Set *s){
    return (*s).Length == 0;
}

boolean IsMemberSet(Set s, ElType x){
    for (int i =0; i < s.Length; i++){
        if (IsWordSame((s).Content[i],x)){
            return true;
        }
    }
    return false;
}

boolean IsIdxValidSet(Set s, int i) {
    return i < s.Length && i >= 0;
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
        DisplayWord(s.Content[i]);
    }
}

void DisplaySet(Set s){
    if (IsEmptySet(&s)){
        printf("Kosong\n");
    } else{
        for (int i = 0; i < s.Length; i++){
            printf("    %d. ", i+1);
            DisplayWord(s.Content[i]);
        }
    }
}

void CopySet(Set source, Set *dest) {
    CreateSet(dest);
    for (int i = 0; i < source.Length; i++) {
        PasteWord(source.Content[i], &(*dest).Content[i]);
        (*dest).Length++;
    }
}