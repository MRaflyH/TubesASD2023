#include "mesinkata.h"
#include <stdio.h>

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
   while (CurrentChar == Blank) {
      Adv();
   }
}

void StartWord() {
    printf(">> ");
    Start();
    IgnoreBlanks();
    if (CurrentChar == Mark) {
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWord();
    }
}

void AdvWord() {
   IgnoreBlanks();
   if (CurrentChar == Mark) {
      EndWord = true; 
   }
   else {
      CopyWord();
   }
   IgnoreBlanks();
}

void CopyWord() {
   int i = 0;
   while (CurrentChar != Mark && CurrentChar != Blank) {
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

void DisplayWord() {
    for (int i = 0; i < CurrentWord.Length; i++) {
        printf("%c", CurrentWord.Content[i]);
    }
    printf("\n");
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