#ifndef STACK_H
#define STACK_H

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL

typedef int ElType;
typedef struct node* Address;

typedef struct node { 
  ElType Info;
  Address Next;
} Node;

typedef struct {
  Address AddrTop;
} Stack;

#define Next(s) (s)->Next
#define Info(s) (s)->Info
#define AddrTop(s) (s).AddrTop
#define Top(s) (s).AddrTop->Info

Address NewNode(ElType x);

void CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack s);
/* Mengirim true jika Stack kosong: lihat definisi di atas */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *s, ElType x);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *s, ElType *x);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void DisplayStack(Stack s);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

#endif