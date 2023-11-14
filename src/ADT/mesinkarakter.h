#ifndef MESIN_KARAKTER_H
#define MESIN_KARAKTER_H

#include "../../src/boolean.h"
#include "stdio.h"

#define Mark ';'
#define NewLine '\n'
#define Blank ' '
extern char CurrentChar;
extern boolean EOP;

void StartRead(char * FileName);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari FileName.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != EOF maka EOP akan padam (false)
          Jika currentChar = EOF maka EOP akan menyala (true) */

void StartWrite(char * FileName);
/* Mesin siap dioperasikan. Pita disiapkan untuk ditulis.
   I.S. : sembarang
   F.S. : FileName dalam state dibuka dan siap ditulis */

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
/* Pita dimajukan satu karakter.
   I.S. : sembarang
   F.S. : character terakhir pada pita adalah cc */

void AdvWriteBlank();
/* Pita dimajukan satu karakter.
   I.S. : sembarang
   F.S. : character terakhir pada pita adalah Blank */

void AdvWriteMark();
/* Pita dimajukan satu karakter.
   I.S. : sembarang
   F.S. : character terakhir pada pita adalah Mark */

void AdvWriteNewLine();
/* Pita dimajukan satu karakter.
   I.S. : sembarang
   F.S. : character terakhir pada pita adalah NewLine */

void EndWrite();
/* Menutup pita.
   I.S. : pita terbuka
   F.S. : pita tertutup */

char GetCC();
/* Mengirimkan currentChar */

boolean IsEOF();
/* Mengirimkan true jika feof(pita) == true */

#endif