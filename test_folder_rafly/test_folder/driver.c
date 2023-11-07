#include "mesinkata.h"

int main() {
    Word QUIT;
    CreateWord(4, "QUIT", &QUIT);
    
    boolean EndProgram = false;

    // while (!EndProgram)
    // {
        StartWord();
        DisplayWord(CurrentWord);
        EndProgram = IsWordSame(CurrentWord, QUIT);
    // }
        StartWord();
        DisplayWord(CurrentWord);
        EndProgram = IsWordSame(CurrentWord, QUIT);

    return 0;
}