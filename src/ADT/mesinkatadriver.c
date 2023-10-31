#include "mesinkata.c"
#include "mesinkarakter.c"
#include <stdio.h> 

Word KataPisang;
Word KataPisang2;
Word KataGoreng;
int TempLen;
char *TempKata;

int main() {
    TempLen = 6;
    TempKata = "pisang";

    for (int i = 0; i < TempLen; i++) {
        KataPisang.Content[i] = *TempKata;
        KataPisang.Length++;
        TempKata++;
    }

    TempKata = "goreng";

    for (int i = 0; i < TempLen; i++) {
        KataPisang2.Content[i] = *TempKata;
        KataPisang2.Length++;
        TempKata++;
    }

    printf("%d\n", IsWordSame(KataPisang, KataPisang2));

    for (int i = 0; i < KataPisang.Length; i++) {
        printf("%c", KataPisang.Content[i]);
    }
    printf("\n");


    // printf("Input: ");
    // Start();
    // while (!IsEOP()) {
    //     DisplayWord();
    //     AdvWord();
    // }
    // DisplayWord();

    return 0;
}