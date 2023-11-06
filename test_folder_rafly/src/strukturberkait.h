#ifndef STRUKTUR_BERKAIT_H
#define STRUKTUR_BERKAIT_H

#include "kata.h"
#include <stdlib.h>

#define Nil NULL

typedef Word ElType;
typedef struct node* Address;

typedef struct node { 
  ElType Info;
  Address Next;
} Node;

typedef Address StrukBerkait;

#define Next(q) (q)->Next
#define Info(q) (q)->Info

Address NewNodeSB(ElType x);

boolean IsIdxValidSB(StrukBerkait *s, int i);

void CreateSB(StrukBerkait *s);
/* I.S. sembarang */
/* F.S. Sebuah sb kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah sb kosong */

/* ********** Pemeriksa Status StrukBerkait ********** */
boolean IsEmptySB(StrukBerkait s);
/* Mengirim true jika sb kosong: lihat definisi di atas */

int LengthSB(StrukBerkait s);
/* Mengirimkan banyaknya elemen StrukBerkait. Mengirimkan 0 jika sb kosong. */

void InsertSB(StrukBerkait *s, ElType x, int i);

void DeleteSB(StrukBerkait *s, ElType *x, int i);

/* ********** Display StrukBerkait ********** */
void DisplaySB(StrukBerkait s);
/* Proses : Menuliskan isi StrukBerkait dengan traversal, StrukBerkait ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. sb boleh kosong */
/* F.S. Jika sb tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika StrukBerkait kosong : menulis [] */
#endif