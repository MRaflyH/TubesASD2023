#include "display.h"
#include "data.h"

int main() {
    // JANGAN LUPA LOAD
    LoadData();

    // CONTOH INPUT UNTUK PARAMETER
    char * inputString;
    int inputLength;
    Word inputWord;
    inputString = "test input 1";
    inputLength = 12;
    CreateWord(inputLength, inputString, &inputWord);
    printf("INI ADALAH INPUT KAMU DI DRIVER: ");
    DisplayWord(inputWord);

    // KALAU MAU PAKE INTEGER, PAKE x = WordToInt(Word w)
    Display();
}