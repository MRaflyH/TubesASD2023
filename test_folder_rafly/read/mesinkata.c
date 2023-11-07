#include "mesinkata.h"
#include <stdio.h>

boolean EndWord;
Word CurrentWord;

void IgnoreBlanksI() {
   while (CurrentChar == Blank) {
      Adv();
   }
}

void IgnoreNewLines() {
   while (CurrentChar == NewLine) {
      Adv();
   }
}

void StartWordI() {
    Start();
    IgnoreBlanksI();
    if (CurrentChar == Mark) {
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWordI();
    }
}

void StartLine() {
    Start();
    IgnoreBlanksI();
    if (CurrentChar == NewLine) {
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyLine();
    }
}

void AdvWordI() {
   IgnoreNewLines();
   IgnoreBlanksI();
   if (CurrentChar == Mark) {
      EndWord = true; 
   }
   else {
      CopyWordI();
   }
   IgnoreNewLines();
   IgnoreBlanksI();
}

void AdvLine() {
   IgnoreNewLines();
   IgnoreBlanksI();
   if (CurrentChar == NewLine) {
      EndWord = true; 
   }
   else {
      CopyLine();
   }
   IgnoreNewLines();
   IgnoreBlanksI();
}

void CopyWordI() {
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

void CopyLine() {
   int i = 0;
   while (CurrentChar != Mark && CurrentChar != NewLine) {
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


void Display() {
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