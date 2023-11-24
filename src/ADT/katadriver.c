#include "kata.h"

int main() {
    Word kata1, kata2;
    Word int1, int2;

    CreateWord(6, "pisang", &kata1);
    printf("Kata 1: ");
    DisplayWord(kata1);
    printf("\n");
    
    PasteWord(kata1, &kata2);
    printf("Kata 2: ");
    DisplayWordNewLine(kata2);

    printf("Hasil IsWordSame(kata1, kata2) : %d\n", IsWordSame(kata1, kata2));

    CreateWord(2, "69", &int1);
    printf("%d\n", WordToInt(int1));

    IntToWord(420, &int2);
    DisplayWordNewLine(int2);

    CreateWord(8, "file.txt", &kata1);
    printf("%s\n", WordtoFileName(kata1));

    return 0;
}