#include "data.h"
#include "console.h"

int main() {
    Initiate();
    // untuk testing aja
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
    printf("             /____/            /____/                            \n\n");

    while (!EndProgram) {
        StartWordI();
        if (IsWordSame(CurrentWord, WordSTART)) {
            START();
        }
        else if (IsWordSame(CurrentWord, WordLOAD)) {
            AdvWordI();
            LOAD();
        }
        else if (IsWordSame(CurrentWord, WordQUIT)) {
            EndProgram = true;
        }
        // UNTUK TESTING
        else if (IsWordSame(CurrentWord, WordDISPLAY)) {
            DISPLAY();
        }
        else {
            printf("Command tidak diketahui!\n");
        }

        printf("\n");
    }

    printf("  ________                __      __  __               \n");
    printf(" /_  __/ /_  ____ _____  / /__    \\ \\/ /___  __  __    \n");
    printf("  / / / __ \\/ __ `/ __ \\/ //_/     \\  / __ \\/ / / /    \n");
    printf(" / / / / / / /_/ / / / / ,<        / / /_/ / /_/ /     \n");
    printf("/_/ /_/ /_/\\__,_/_/ /_/_/|_|      /_/\\____/\\__,_/      \n");
    printf("    ____              ____  __            _            \n");
    printf("   / __/___  _____   / __ \\/ /___ ___  __(_)___  ____ _\n");
    printf("  / /_/ __ \\/ ___/  / /_/ / / __ `/ / / / / __ \\/ __ `/\n");
    printf(" / __/ /_/ / /     / ____/ / /_/ / /_/ / / / / / /_/ / \n");
    printf("/_/  \\____/_/     /_/   /_/\\__,_/\\__, /_/_/ /_/\\__, /  \n");
    printf("                                /____/        /____/   \n\n");
    return 0;
}