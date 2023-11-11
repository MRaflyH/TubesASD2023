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

        printf(">> ");
        StartWordI();
        printf("\n");

        if (IsWordSame(CurrentWord, WordSTART)) {
            if (!LoggedIn) {
                START();
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordLOAD)) {
            if (!LoggedIn) {
                AdvWordI();
                LOAD();
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordLIST)) {
            if (LoggedIn) {
                AdvWordI();
                if (IsWordSame(CurrentWord, WordDEFAULT)) {
                    printf("RUN LISTDEFAULT\n");
                    // LISTDEFAULT();
                }
                else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                    printf("RUN LISTPLAYLIST\n");
                    // LISTPLAYLIST();
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordPLAY)) {
            if (LoggedIn) {
                AdvWordI();
                if (IsWordSame(CurrentWord, WordSONG)) {
                    printf("RUN PLAYSONG\n");
                    // PLAYSONG();
                }
                else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                    printf("RUN PLAYPLAYLIST\n");
                    // PLAYPLAYLIST();
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordQUEUE)) {
            if (LoggedIn) {
                AdvWordI();
                if (IsWordSame(CurrentWord, WordSONG)) {
                    printf("RUN QUEUESONG\n");
                    // QUEUESONG();
                }
                else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                    printf("RUN QUEUEPLAYLIST\n");
                    // QUEUEPLAYLIST();
                }
                else if (IsWordSame(CurrentWord, WordSWAP)) {
                    printf("RUN QUEUESWAP\n");
                    // QUEUEPLAYSWAP();
                }
                else if (IsWordSame(CurrentWord, WordREMOVE)) {
                    printf("RUN QUEUEREMOVE\n");
                    // QUEUEREMOVE();
                }
                else if (IsWordSame(CurrentWord, WordCLEAR)) {
                    printf("RUN QUEUECLEAR\n");
                    // QUEUECLEAR();
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordSONG)) {
            if (LoggedIn) {
                AdvWordI();
                if (IsWordSame(CurrentWord, WordNEXT)) {
                    printf("RUN SONGNEXT\n");
                    // SONGNEXT();
                }
                else if (IsWordSame(CurrentWord, WordPREVIOUS)) {
                    printf("RUN SONGPREVIOUS\n");
                    // SONGPREVIOUS();
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
            if (LoggedIn) {
                AdvWordI();
                if (IsWordSame(CurrentWord, WordCREATE)) {
                    PLAYLISTCREATE();
                }
                else if (IsWordSame(CurrentWord, WordADD)) {
                    AdvWordI();
                    if (IsWordSame(CurrentWord, WordSONG)) {
                        PLAYLISTADDSONG();
                    }
                    else if (IsWordSame(CurrentWord, WordALBUM)) {
                        PLAYLISTADDALBUM();
                    }
                    else {
                        KnownCommand = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordSWAP)) {
                    PLAYLISTSWAP();
                }
                else if (IsWordSame(CurrentWord, WordREMOVE)) {
                    PLAYLISTREMOVE();
                }
                else if (IsWordSame(CurrentWord, WordDELETE)) {
                    PLAYLISTDELETE();
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordSTATUS)) {
            if (LoggedIn) {
                printf("RUN STATUS\n");
                // STATUS();
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordSAVE)) {
            if (LoggedIn) {
                AdvWordI();
                printf("RUN SAVE\n");
                //SAVE();
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordQUIT)) {
            if (LoggedIn) {
                printf("RUN QUIT\n");
                // QUIT();
                EndProgram = true;
            }
            else {
                ValidCommand = false;
            }
        }
        else if (IsWordSame(CurrentWord, WordHELP)) {
            printf("RUN HELP\n");
            // HELP();
        }
        // UNTUK TESTING
        else if (IsWordSame(CurrentWord, WordDISPLAY)) {
            DISPLAY();
        }
        // SAMPE SINI
        else {
            KnownCommand = false;
        }

        if (!KnownCommand || !ValidCommand) {
            INVALIDCOMMAND();
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