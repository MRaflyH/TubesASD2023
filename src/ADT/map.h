#ifndef MAP_H
#define MAP_H

#include "set.h"

#define MaxCapacity 100
// #define ValUndef -1

typedef Word KeyType;
typedef Set ValType;

typedef struct { 
  KeyType Key;
  ValType Value;
} MapEntry;

typedef struct {
  MapEntry Content[MaxCapacity];
  int Length;
} Map;

void CreateM(Map *m);
/* I.S. m sembarang. */
/* F.S. m terdefinisi dan kosong. */

boolean IsEmptyM(Map m);
/* Fungsi mengecek jika isi map kosong m.length == 0. */
/* Prekondisi: m terdefinisi. */

boolean IsFullM(Map m);
/* Fungsi mengecek jika isi map penuh m.lengt == MaxCapacity. */
/* Prekondisi: m terdefinisi. */

boolean IsMemberM(Map m, KeyType k);
/* Fungsi mengecek jika key k adalah member map. */
/* Prekondisi: m dan k terdefinisi. */

ValType ValueM(Map m, KeyType k);
/* Fungsi mengembalikan value untuk key k dalam map. */
/* Prekondisi: m dan k terdefinisi. */

void InsertM(Map *m, KeyType k, ValType v);
/* I.S. m, k, dan v terdefinisi. */
/* F.S. memasukkan key k dengan value v pada akhir map. */

void DeleteM(Map *m, KeyType k);
/* I.S. m, k. */
/* F.S. menghapus key k dan valuenya pada map. */

void DisplayValueM(Map m, KeyType k);
/**
 * print value key k dalam map
 * jika kosong print "Kosong"
 * 
 *     1. {Element 1 Key k}
 *     2. {Element 2 Key k}
 *     3. {Element 3 Key k}
 *     4. {Element 4 Key k}
 * 
 * berakhir akhir dengan '\n'
 * Prekondisi: k adalah key valid
*/

void DisplayM(Map m);
/**
 * print key dan valuenya map
 * jika kosong print "Kosong"
 * 
 * Key 1: {Key A}
 *     1. {Element 1 Key A}
 *     2. {Element 2 Key A}
 *     3. {Element 3 Key A}
 *     4. {Element 4 Key A}
 * Key 2: {Key B}
 * Kosong
 * 
 * berakhir akhir dengan '\n'
*/

#endif