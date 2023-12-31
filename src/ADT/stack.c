#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateS (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : Top bernilai NilStack */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyS (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S)==NilStack);
}

boolean IsFullS (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S)==MaxEl-1);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushS (Stack * S, Detail X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi Top yang baru,Top bertambah 1 */
{
    if (IsFullS(*S)) {
        for (int i = 0; i < (*S).Top; i++) {
            PasteD((*S).Content[i+1], &(*S).Content[i]);
        }
    }
    else {
        Top(*S) += 1;
    }
    PasteD(X, &InfoTop(*S));
}

void PushFirstS (Stack * S, Detail X)
{
    Top(*S) += 1;
    for (int i = Top(*S); i > 0; i--) {
        PasteD((*S).Content[i-1], &(*S).Content[i]);
    }
    PasteD(X, &(*S).Content[0]);
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopS (Stack * S, Detail* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen Top yang lama, Top berkurang 1 */
{
    PasteD(InfoTop(*S), X);
    Top(*S) -= 1;
}

void DisplayS(Stack s){
    if(IsEmptyS(s)){
        printf("Kosong\n");
    } else{
        IdxType i;
        for(i=Top(s); i>0; i--){
            printf("    %d. ",  Top(s) - i + 1);
            DisplayD(s.Content[i]);
        }
        printf("    %d. ", Top(s) - i + 1);
        DisplayD(s.Content[i]);
    }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */