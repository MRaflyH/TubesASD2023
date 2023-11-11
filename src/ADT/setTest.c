#include "set.h"
#include "kata.h"
#include <stdio.h>

int main() {
    Set s;
    Word x;

    // Membuat set
    CreateSet(&s);
    printf("Set telah dibuat.\n");

    // Membuat kata
    CreateWord(5, "Hello", &x);
    printf("Kata telah dibuat.\n");

    // Menambahkan elemen ke set
    printf("Menambahkan elemen ke set...\n");
    AddSet(&s, x);
    printf("Elemen telah ditambahkan.\n");

    // Menampilkan set
    printf("Menampilkan set:\n");
    DisplaySet(s);

    // Mengecek apakah set kosong
    printf("Mengecek apakah set kosong...\n");
    if (IsEmptySet(&s)) {
        printf("Set kosong.\n");
    } else {
        printf("Set tidak kosong.\n");
    }

    // Mengecek apakah elemen adalah anggota set
    printf("Mengecek apakah elemen adalah anggota set...\n");
    if (IsMemberSet(s, x)) {
        printf("Elemen adalah anggota set.\n");
    } else {
        printf("Elemen bukan anggota set.\n");
    }

    // Menghapus elemen dari set
    printf("Menghapus elemen dari set...\n");
    DeleteSet(&s, x);
    printf("Elemen telah dihapus.\n");

    // Menampilkan set setelah penghapusan
    printf("Menampilkan set setelah penghapusan:\n");
    DisplaySet(s);

    return 0;
}
