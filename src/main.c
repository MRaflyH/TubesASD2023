#include "data.h"
#include "console.h"
#include <unistd.h>

int main() {
    Initiate();
    // untuk testing aja
    Word WordDISPLAY;
    CreateWord(7, "DISPLAY", &WordDISPLAY);
    // sampe sini

    printf(" _       __     __                             __                \n");
    usleep(100000);
    printf("| |     / /__  / /________  ____ ___  ___     / /_____           \n");
    usleep(100000);
    printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\          \n");
    usleep(100000);
    printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /          \n");
    usleep(100000);
    printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/   \\__/\\____/           \n");
    usleep(100000);
    printf(" _       __                             _       __               \n");
    usleep(100000);
    printf("| |     / /___ ___  ______ _____  ____ | |     / /___ __   _____ \n");
    usleep(100000);
    printf("| | /| / / __ `/ / / / __ `/ __ \\/ __ `/ | /| / / __ `/ | / / _ \\\n");
    usleep(100000);
    printf("| |/ |/ / /_/ / /_/ / /_/ / / / / /_/ /| |/ |/ / /_/ /| |/ /  __/\n");
    usleep(100000);
    printf("|__/|__/\\__,_/\\__, /\\__,_/_/ /_/\\__, / |__/|__/\\__,_/ |___/\\___/ \n");
    usleep(100000);
    printf("             /____/            /____/                            \n\n");
    usleep(100000);

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
        // SAMPE SINI
        else {
            printf("Command tidak diketahui!\n");
        }

        printf("\n");
    }

    printf("  ________                __      __  __               \n");
    usleep(100000);
    printf(" /_  __/ /_  ____ _____  / /__    \\ \\/ /___  __  __    \n");
    usleep(100000);
    printf("  / / / __ \\/ __ `/ __ \\/ //_/     \\  / __ \\/ / / /    \n");
    usleep(100000);
    printf(" / / / / / / /_/ / / / / ,<        / / /_/ / /_/ /     \n");
    usleep(100000);
    printf("/_/ /_/ /_/\\__,_/_/ /_/_/|_|      /_/\\____/\\__,_/      \n");
    usleep(100000);
    printf("    ____              ____  __            _            \n");
    usleep(100000);
    printf("   / __/___  _____   / __ \\/ /___ ___  __(_)___  ____ _\n");
    usleep(100000);
    printf("  / /_/ __ \\/ ___/  / /_/ / / __ `/ / / / / __ \\/ __ `/\n");
    usleep(100000);
    printf(" / __/ /_/ / /     / ____/ / /_/ / /_/ / / / / / /_/ / \n");
    usleep(100000);
    printf("/_/  \\____/_/     /_/   /_/\\__,_/\\__, /_/_/ /_/\\__, /  \n");
    usleep(100000);
    printf("                                /____/        /____/   \n\n");
    usleep(100000);
    return 0;
}