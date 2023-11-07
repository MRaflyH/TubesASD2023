#include "mesininput.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanksI() {
   while (CurrentChar == Blank || CurrentChar == NewLine) {
      Adv();
   }
}

void StartWordI() {
   Start();
   // CreateWord(0, "", &CurrentWord);
   IgnoreBlanksI();
   if (CurrentChar == Mark) {
      EndWord = true;
   }
   else {
      EndWord = false;
      CopyWordI();
   }
   IgnoreBlanksI();
}

void AdvWordI() {
   IgnoreBlanksI();
   if (CurrentChar == Mark) {
      EndWord = true; 
   }
   else {
      CopyWordI();
   }
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
