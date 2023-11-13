#ifndef MESIN_INPUT_H
#define MESIN_INPUT_H

#include "mesinkarakter.h"
#include "kata.h"

void IgnoreBlanksI();
/* Mengabaikan satu atau beberapa Blank dan Mark
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ Blank atau currentChar = Mark */

void StartWordI();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata sampai Blank yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void StartLineI();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          currentWord adalah kata sampai Mark yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void AdvWordI();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyWordI */

void AdvLineI();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, pasti MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure CopyLineI */

void CopyWordI();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyLineI();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = MARK;
          currentChar adalah Mark.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
          
#endif