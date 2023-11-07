#include "mesinkata.c"
#include "mesinkarakter.c"
#include "kata.c"

int main() {
    Word QuitWord;
    CreateWord(4, "QUIT", &QuitWord);
    DisplayWord(QuitWord);

    StartWord();
    while (!IsWordSame(CurrentWord, QuitWord)) {
        while (!IsEOP()) {
            AdvWord();
            DisplayWord(CurrentWord);
        }
        DisplayWord(CurrentWord);
        StartWord();
    }
}