#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h> 

int main() {
    printf("Input: ");
    Start();
    while (!IsEOP()) {
        DisplayWord();
        AdvWord();
    }
    DisplayWord();
    return 0;
}