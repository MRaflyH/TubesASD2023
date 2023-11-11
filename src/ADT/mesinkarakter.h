#ifndef MESIN_KARAKTER_H
#define MESIN_KARAKTER_H

#include "../../src/boolean.h"
#include "stdio.h"

#define Mark ';'
#define NewLine '\n'
#define Blank ' '
extern char CurrentChar;
extern boolean EOP;

void StartF(char * FileName);
void StartWrite(char * FileName);

void Start();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void Adv();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void AdvWrite(char cc);

void AdvWriteBlank();

void AdvWriteMark();

void AdvWriteNewLine();

void EndWrite();

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOP();
/* Mengirimkan true jika currentChar = MARK */

#endif