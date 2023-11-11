#ifndef LIST_DINAMIK_H
#define LIST_DINAMIK_H

#include "strukturberkait.h"
#include <stdlib.h>

#define InitialCapacity 16

typedef int IdxType;

typedef struct {
    StrukBerkait *Content;
    int Capacity;
    int Neff;
} ListDinamik;

ListDinamik CreateLD();
/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */

void DeallocateLD(ListDinamik *l);
/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */

boolean IsEmptyLD(ListDinamik l);
/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */

boolean IsFullLD(ListDinamik l);

boolean IsIdxValidLD(ListDinamik l, IdxType i);

ElType GetLD(ListDinamik l, IdxType i);
/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */

void InsertLD(ListDinamik *l, ElType x, IdxType i);
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DeleteLD(ListDinamik *l, IdxType i);
/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DisplayLD(ListDinamik l);
// Mungkin kosong = "Kosong"
// 1. K-pop Enjoyer
// 2. Z E R O 4.0
// 3. Be the main character
// 4. Hey i liked you.

void DisplayIsiLD(ListDinamik l, ElType x);
void DisplaySemuaLD(ListDinamik l);


#endif