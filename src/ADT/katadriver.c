#include "kata.h"

int main() {
    Word kata1, kata2;

    CreateWord(6, "pisang", &kata1);
    printf("Kata 1: ");
    DisplayWord(kata1);
    
    PasteWord(kata1, &kata2);
    printf("Kata 2: ");
    DisplayWord(kata2);

    printf("Hasil IsWordSame(kata1, kata2) : %d\n", IsWordSame(kata1, kata2));

    return 0;
}