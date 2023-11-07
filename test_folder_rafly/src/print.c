// JANGAN LUPA INCLUDE DATA
#include "data.h"

int main() {
    // HARUS LOAD DATA
    LoadData();

    printf("INI DAFTAR PENYANYI\n");
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

    return 0;
}