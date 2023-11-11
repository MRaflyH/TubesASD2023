#include "liststatik.h"

ListStatik CreateLS() {
    ListStatik NewList;
    NewList.Neff = 0;
    return NewList;
}

boolean IsEmptyLS(ListStatik l) {
    return l.Neff == 0;
}

boolean SearchLS(ListStatik l, ElType x) {
    boolean found = false;
    int i = 0;
    while (!found && i < l.Neff) {
        if (IsWordSame(l.Content[i], x)) {
            found = true;
        }
        i++;
    }
    return found;
}

void InsertLS(ListStatik *l, ElType x) {
    PasteWord(x, &(*l).Content[(*l).Neff]);
    (*l).Neff++;
}

void DisplayLS(ListStatik l) {
    if (IsEmptyLS(l)) {
        printf("   Kosong\n");
    }
    else {
        for (int i = 0; i < l.Neff ; i++) {
            printf("   %d. ", i+1);
            DisplayWord(l.Content[i]);
        }
    }
}