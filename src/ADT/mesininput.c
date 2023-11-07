#include "mesininput.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
   while (CurrentChar == Blank || CurrentChar == NewLine) {
      Adv();
   }
}

void StartWord() {
   Start();
   // CreateWord(0, "", &CurrentWord);
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
