#include "stack.h"

Address NewNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        Info(p) = val;
        Next(p) = NULL;
    }
    return p;
}

void CreateEmpty(Stack *S) {
    *S = Nil;
}

boolean IsEmpty(Stack S) {
    return S == Nil;
}

void Push(Stack * S, ElType X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, ElType* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */