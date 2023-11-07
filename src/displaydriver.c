#include "display.h"
#include "data.h"

int main() {
    // JANGAN LUPA LOAD
    LoadData();

    Word DISPLAY;
    Word EXIT;
    boolean EndProgram = false;

    CreateWord(7, "DISPLAY", &DISPLAY);
    CreateWord(4, "EXIT", &EXIT);

    while (!EndProgram) {
        // INPUT BERAKHIR DENGAN ';'
        printf("DISPLAY/EXIT:\n");
        StartWordI();
        printf("\n");
        // DisplayWord(DISPLAY);
        if (IsWordSame(CurrentWord, EXIT)) {
            EndProgram = true;
        }
        else if (IsWordSame(CurrentWord, DISPLAY)) {
            Display();
        }
    }
    return 0;
}