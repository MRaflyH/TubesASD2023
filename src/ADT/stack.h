/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* Top adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "detaillagu.h"

#define NilStack -1
#define MaxEl 100
/* NilStack adalah stack dengan elemen kosong . */

/* Contoh deklarasi variabel bertype stack dengan ciri Top : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Detail Content[MaxEl]; /* tabel penyimpan elemen */
  IdxType Top;  /* alamat Top: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.Top = NilStack */
/* Elemen yang dipakai menyimpan nilai Stack Content[0]..Content[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.Content[(S.Top)] untuk mengakses elemen Top */
   /* S.Top adalah alamat elemen Top */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).Top
#define InfoTop(S) (S).Content[(S).Top]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateS(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : Top bernilai NilStack */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullS(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushS(Stack * S, Detail X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. Top bertambah 1, X menjadi Top yang baru, */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopS(Stack * S, Detail* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen Top yang lama, Top berkurang 1 */

void DisplayS(Stack s);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
#endif