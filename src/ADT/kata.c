#include "kata.h"
#include "stdlib.h"

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

void DisplayWordSpace(Word w) {
    if (w.Length == 0) {
        printf("Kosong\n");
    }
    else {
        for (int i = 0; i < w.Length; i++) {
            printf("%c", w.Content[i]);
        }
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

void IntToWord(int i, Word * w) {
    int digit;
    CreateWord(0, "", w);

    while (i > 0) {
        digit = i % 10;
        for (int j = (*w).Length; j > 0; j--) {
            (*w).Content[j] = (*w).Content[j-1];
        }
        i = i / 10;
        (*w).Length++;
    }
}

char* WordtoFileName(Word w) {
    // char * file_name = "../save/saved1.txt";
    int folder_length = 8;
    char * folder = "../save/";
    char * s;
    s = (char *)malloc(sizeof(char) * (folder_length + w.Length + 1));

    for (int i = 0; i < folder_length; i++) {
        s[i] = folder[i];
    }

    for (int i = 0; i < w.Length; i++) {
        s[i+folder_length] = w.Content[i];
    }
    s[w.Length + folder_length] = '\0';
    return s;
}
