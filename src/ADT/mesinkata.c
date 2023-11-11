#include "mesinkata.h"

extern boolean EndWord;
extern Word CurrentWord;

void IgnoreBlanks() {
    while (CurrentChar == Blank || CurrentChar == NewLine || CurrentChar == Mark) {
        Adv();
    }

}

void StartFile(char *FileName) {
    StartF(FileName);
    IgnoreBlanks();
    if (CurrentChar == NewLine) {
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyLine();
    }
    IgnoreBlanks();
}

void StartWord() {
    Start();
    IgnoreBlanks();
    if (CurrentChar == Mark) {
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWord();
    }
    IgnoreBlanks();
}

void AdvWord() {
    IgnoreBlanks();
    if (CurrentChar == Blank) {
        EndWord = true; 
    }
    else {
        CopyWord();
    }
    IgnoreBlanks();
}

void AdvLine() {
    IgnoreBlanks();
    if (CurrentChar == NewLine) {
        EndWord = true; 
    }
    else {
        CopyLine();
    }
    IgnoreBlanks();
}

void AdvMark() {
    IgnoreBlanks();
    if (CurrentChar == Mark) {
        EndWord = true; 
    }
    else {
        CopyMark();
    }
    Adv();
    IgnoreBlanks();
}

void CopyWord() {
    int i = 0;
    while (CurrentChar != Blank && !IsEOP()) {
        CurrentWord.Content[i] = CurrentChar;
        Adv();
        i += 1;
    }

    if (i < MaxChar) {
        CurrentWord.Length = i;
    }
    else {
        CurrentWord.Length = MaxChar;
    }
}

void CopyLine() {
    int i = 0;
    while (CurrentChar != NewLine && !IsEOP()) {
        CurrentWord.Content[i] = CurrentChar;
        Adv();
        i += 1;
    }

    if (i < MaxChar) {
        CurrentWord.Length = i;
    }
    else {
        CurrentWord.Length = MaxChar;
    }
}

void CopyMark() {
    int i = 0;
    while (CurrentChar != Mark && !IsEOP()) {
        CurrentWord.Content[i] = CurrentChar;
        Adv();
        i += 1;
    }

    if (i < MaxChar) {
        CurrentWord.Length = i;
    }
    else {
        CurrentWord.Length = MaxChar;
    }
}
