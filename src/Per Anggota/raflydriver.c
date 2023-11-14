#include "rafly.h"

int main() {
    EndProgram = false;
    DaftarPenyanyi = CreateLS();
    DaftarPlaylist = CreateLD();
    CreateQ(&QueueLagu);
    CreateS(&RiwayatLagu);
    CreateM(&AlbumPenyanyi);
    CreateM(&LaguAlbum);

    Word WordLoad, WordExit, WordDisplay;
    CreateWord(4, "LOAD", &WordLoad);
    CreateWord(4, "EXIT", &WordExit);
    CreateWord(7, "DISPLAY", &WordDisplay);

    while (!EndProgram) {
        StartWordI();
        if (IsWordSame(CurrentWord, WordLoad)) {
            AdvWordI();
            LOAD();
        }
        else if (IsWordSame(CurrentWord, WordDisplay)) {
            DISPLAY();
        }
        else if (IsWordSame(CurrentWord, WordExit)) {
            EndProgram = true;
        }
        printf("\n");
    }
    return 0;
}