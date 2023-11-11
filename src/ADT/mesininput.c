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
void StartLineI() {
   Start();
   IgnoreBlanksI();
   if (CurrentChar == Mark) {
      EndWord = true;
   }
   else {
      EndWord = false;
      CopyLineI();
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
void AdvLineI() {
   IgnoreBlanksI();
   if (CurrentChar == Mark) {
      EndWord = true; 
   }
   else {
      CopyLineI();
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
void CopyLineI() {
   int i = 0;
   while (CurrentChar != Mark) {
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