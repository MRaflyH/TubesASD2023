#include "kata.h"

void CreateWord(int length, char * string, Word * w) {
    (*w).Length = 0;
    for (int i = 0; i < length; i++) {
        (*w).Content[i] = * string;
        (*w).Length++;
        string++;
    }
}

boolean IsWordSame(Word w, Word v) {
    boolean IsSame = true;
    if (w.Length != v.Length) {
        IsSame = false;
    }
    else {
        int i = 0;
        while (IsSame && i < w.Length) {
            if (w.Content[i] != v.Content[i]) {
                IsSame = false;
            }
            i++;
        }
    }
    return IsSame;
}

void PasteWord(Word source, Word * dest) {
    (*dest).Length = 0;

    for (int i = 0; i < source.Length; i++) {
        (*dest).Content[i] = source.Content[i];
        (*dest).Length++;
    }
}

void DisplayWord(Word w) {
    if (w.Length == 0) {
        printf("Kosong\n");
    }
    else {
        for (int i = 0; i < w.Length; i++) {
            printf("%c", w.Content[i]);
        }
        printf("\n");
    }
}

int WordToInt(Word w) {
    int sum = 0;
    int digit;
    for (int i = 0; i < w.Length; i++) {
        digit = w.Content[i] - '0';
        sum = sum * 10 + digit;
    }
    return sum;
}
