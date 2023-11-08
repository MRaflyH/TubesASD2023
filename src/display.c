// INCLUDE H FILE
#include "display.h"

// BOLEH PAKE PARAMETER TAPI MASIH VOID YAA. OUTPUT GAUSAH. SEMUA DATA DI DATA.H ITU UNIVERSAL
void Display() {
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
    printf("\nINI CURRENT LAGU\n");
    DisplayWord(CurrentLagu);
    printf("\nINI ISI PLAYLIST\n");
    DisplaySB(Playlist);
}