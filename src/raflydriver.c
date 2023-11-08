#include "rafly.h"

int main() {
    DaftarPenyanyi = CreateLS();
    DaftarPlaylist = CreateLD();
    CreateQ(&QueueLagu);
    CreateS(&RiwayatLagu);
    CreateM(&AlbumPenyanyi);
    CreateM(&LaguAlbum);
    CreateSB(&Playlist);

    Word WordLoad, WordExit, WordDisplay;
    CreateWord(4, "LOAD", &WordLoad);
    CreateWord(4, "EXIT", &WordExit);
    CreateWord(7, "DISPLAY", &WordDisplay);

    while (true) {
        StartWordI();
        if (IsWordSame(CurrentWord, WordLoad)) {
            AdvWordI();
            LOAD();
        }
        else if (IsWordSame(CurrentWord, WordDisplay)) {
            Display();
        }
        else if (IsWordSame(CurrentWord, WordExit)) {
            break;
        }
        printf("\n");
    }
    return 0;
}