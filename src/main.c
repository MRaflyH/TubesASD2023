#include "data.h"
#include "console.h"

int main() {
    Initiate();
    Word WordDISPLAY;
    CreateWord(7, "DISPLAY", &WordDISPLAY);


    printf(" _       __     __                             __                \n");
    printf("| |     / /__  / /________  ____ ___  ___     / /_____           \n");
    printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\          \n");
    printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /          \n");
    printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/   \\__/\\____/           \n");
    printf(" _       __                             _       __               \n");
    printf("| |     / /___ ___  ______ _____  ____ | |     / /___ __   _____ \n");
    printf("| | /| / / __ `/ / / / __ `/ __ \\/ __ `/ | /| / / __ `/ | / / _ \\\n");
    printf("| |/ |/ / /_/ / /_/ / /_/ / / / / /_/ /| |/ |/ / /_/ /| |/ /  __/\n");
    printf("|__/|__/\\__,_/\\__, /\\__,_/_/ /_/\\__, / |__/|__/\\__,_/ |___/\\___/ \n");
    printf("             /____/            /____/                            \n");
    printf("\n");

    while (!EndProgram) {
        StartWordI();
        if (IsWordSame(CurrentWord, WordLOAD)) {
            AdvWordI();
            LOAD();
        }
        else if (IsWordSame(CurrentWord, WordDISPLAY)) {
            DISPLAY();
        }
        else if (IsWordSame(CurrentWord, WordQUIT)) {
            EndProgram = true;
        }
        printf("\n");
    }


    return 0;
}