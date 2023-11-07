#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
   while (CurrentChar == Blank) {
      Adv();
   }
}

void StartWord() {
   Start();
   IgnoreBlanks();
   if (CurrentChar == Mark) {
      EndWord = true;
   }
   else {
      EndWord = false;
      AdvWord();
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
      i ++;
   }

   if (i < MaxChar) {
      CurrentWord.Length = i;
   }
   else {
      CurrentWord.Length = MaxChar;
   }
} 
