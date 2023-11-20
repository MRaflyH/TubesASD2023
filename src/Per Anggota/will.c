#include "will.h"

void ListDefault(){
    printf("Daftar Penyanyi: \n");
    DisplayLS(DaftarPenyanyi);
    printf("Ingin melihat album yang ada? (Y/N): ");
    if (IsWordSame(CurrentWord, WordY)){
        printf("Pilih penyanyi untuk melihat album mereka: ");
        StartWordI();
        Word penyanyi = CurrentWord;
        // cari penyanyi
        DisplayValueM(AlbumPenyanyi, penyanyi);

        printf("Ingin melihat lagu yang ada? (Y/N): ");
        StartWordI();
        if (IsWordSame(CurrentWord, WordY)){
            printf("Pilih album untuk melihat lagu yang ada di album: ");
            StartWordI();
            Word album = CurrentWord;
            // cari album
            DisplayValueM(LaguAlbum, album);
        }
    }
}
void ListPlaylist(){
    return;
}
