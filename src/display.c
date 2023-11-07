// INCLUDE H FILE
#include "display.h"

void Display() {
    // HARUS LOAD DATA
    LoadData();

    // SEMENTARA UNTUK TEST CASE, HARUS INPUT MANUAL PAKE BERIKUT
    char * inputString;
    int inputLength;
    Word inputWord;
    inputString = "test input";
    inputLength = 10;
    CreateWord(inputLength, inputString, &inputWord);
    printf("INI ADALAH INPUT KAMU : ");
    DisplayWord(inputWord);

    printf("\nINI DAFTAR PENYANYI\n");
    DisplayLS(DaftarPenyanyi);

    printf("\nINI DAFTAR PLAYLIST\n");
    DisplayLD(DaftarPlaylist);

    printf("\nINI QUEUE LAGU\n");
    DisplayQ(QueueLagu);

    printf("\nINI RIWAYAT LAGU\n");
    DisplayS(RiwayatLagu);

    printf("\nINI MAP ALBUM : PENYANYI\n");
    DisplayM(AlbumPenyanyi);

    printf("\nINI MAP LAGU : ALBUM\n");
    DisplayM(LaguAlbum);

    printf("\nINI ISI PLAYLIST\n");
    DisplaySB(Playlist);

    printf("\nINI CURRENT LAGU\n");
    DisplayWord(CurrentLagu);
}