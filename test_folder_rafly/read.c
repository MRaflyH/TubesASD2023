#include "mesinkata.c"
#include "mesinkarakter.c"
 
// Driver code
int main()
{
    StartWord();

    int NPenyanyi;
    NPenyanyi = CurrentWord.Content[0] - '0';
    printf("%d\n", NPenyanyi);

    for (int i = 0; i < NPenyanyi; i++) {
        int NAlbum;
        NAlbum = 0;

        AdvWord();
        NAlbum = CurrentWord.Content[0] - '0';
        DisplayWord();
        printf("%d\n", NAlbum);

        for (int j = 0; j < NAlbum; j++) {
            int NLagu;
            NLagu = 0;

            AdvWord();
            NLagu = CurrentWord.Content[0] - '0';
            DisplayWord();
            printf("%d\n", NLagu);

            for (int k = 0; k < NLagu; k++) {
                AdvWord();
                DisplayWord();                
            }
        }
    }

    // do {
    //     DisplayWord();
    //     AdvWord();
    // } while (CurrentChar != '|');

    // DisplayWord();
    
    return 0;
}
