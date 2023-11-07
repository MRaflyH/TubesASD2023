#include "mesinkata.c"
#include "mesinkarakter.c"
 
// Driver code
int main()
{

    StartLine();
    int NPenyanyi = 0;
    for (int i = 0; i < CurrentWord.Length; i++) {
        NPenyanyi = NPenyanyi * 10 + (CurrentWord.Content[i] - '0');
    }

    for (int i = 0; i < NPenyanyi; i++) {
        printf("Penyanyi %d : ", i+1);
        AdvWordI();
        int NAlbum = 0;
        for (int j = 0; j < CurrentWord.Length; j++) {
            NAlbum = NAlbum * 10 + (CurrentWord.Content[j] - '0');
        }
        AdvLine();
        Display();

        for (int j = 0; j < NAlbum; j++) {
            printf("  Album %d : ", j+1);
            AdvWordI();
            int NLagu = 0;
            for (int k = 0; k < CurrentWord.Length; k++) {
                NLagu = NLagu * 10 + (CurrentWord.Content[k] - '0');
            }
            AdvLine();
            Display();

            for (int k = 0; k < NLagu; k++) {
                printf("    Lagu %d : ", k+1);
                AdvLine();
                Display();
            }
        }
    }

    printf("KELAR\n");
     
    return 0;
}
