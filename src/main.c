#include "data.h"
#include "console.h"
#include <unistd.h>

int main() {
    Initiate();
    // untuk testing aja
    Word WordDISPLAY;
    CreateWord(7, "DISPLAY", &WordDISPLAY);
    // sampe sini

    usleep(100000);
    printf(" _       __     __                             __\n");
    usleep(100000);
    printf("| |     / /__  / /________  ____ ___  ___     / /_____\n");
    usleep(100000);
    printf("| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\   / __/ __ \\\n");
    usleep(100000);
    printf("| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/  / /_/ /_/ /\n");
    usleep(100000);
    printf("|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/   \\__/\\____/\n");
    usleep(100000);
    printf(" _       __                             _       __\n");
    usleep(100000);
    printf("| |     / /___ ___  ______ _____  ____ | |     / /___ __   _____\n");
    usleep(100000);
    printf("| | /| / / __ `/ / / / __ `/ __ \\/ __ `/ | /| / / __ `/ | / / _ \\\n");
    usleep(100000);
    printf("| |/ |/ / /_/ / /_/ / /_/ / / / / /_/ /| |/ |/ / /_/ /| |/ /  __/\n");
    usleep(100000);
    printf("|__/|__/\\__,_/\\__, /\\__,_/_/ /_/\\__, / |__/|__/\\__,_/ |___/\\___/\n");
    usleep(100000);
    printf("             /____/            /____/\n");
    usleep(100000);
    printf("\n");
    usleep(100000);
    printf("    __  __      ____         //|    //|     __\n");
    usleep(100000);
    printf("   / / / /___ _/ / /___     |/||   |/||   _/_/\n");
    usleep(100000);
    printf("  / /_/ / __ `/ / / __ \\                _/_/  \n");
    usleep(100000);
    printf(" / __  / /_/ / / / /_/ /              _/_/\n");
    usleep(100000);
    printf("/_/ /_/\\__,_/_/_/\\____/     ______   /_/\n");
    usleep(100000);
    printf("                           /_____/\n");
    usleep(100000);
    printf("\n");
    usleep(100000);

    // HELP();

    while (!EndProgram) {

        printf(">> ");
        StartWordI();
        printf("\n");

        if (IsWordSame(CurrentWord, WordSTART)) {
            if (IsEOP()) {
                if (!LoggedIn) {
                    START();
                }
                else {
                    CorrectSession = false;
                }
                }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordLOAD)) {
            AdvLineI();
            if (IsEOP()) {
                if (!LoggedIn) {
                    LOAD();
                }
                else {
                    CorrectSession = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordLIST)) {
            AdvWordI();
            if (!IsEOP()) {
                if (IsWordSame(CurrentWord, WordDEFAULT)) {
                    if (LoggedIn) {
                        printf("RUN LISTDEFAULT\n");
                        // LISTDEFAULT();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                    if (LoggedIn) {
                        printf("RUN LISTPLAYLIST\n");
                        // LISTPLAYLIST();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordPLAY)) {
            AdvWordI();
            if (IsEOP()) {
                if (IsWordSame(CurrentWord, WordSONG)) {
                    if (LoggedIn) {
                        PLAYSONG();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                    if (LoggedIn) {
                        PLAYPLAYLIST();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordQUEUE)) {
            AdvWordI();
            if (IsEOP()) {
                if (IsWordSame(CurrentWord, WordSONG)) {
                    if (LoggedIn) {
                        printf("RUN QUEUESONG\n");
                        // QUEUESONG();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                    if (LoggedIn) {
                        printf("RUN QUEUEPLAYLIST\n");
                        // QUEUEPLAYLIST();
                    }
                    else {
                        CorrectSession = false;
                    }
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
                    if (LoggedIn) {
                        printf("RUN QUEUECLEAR\n");
                        // QUEUECLEAR();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordSONG)) {
            AdvWordI();
            if (IsEOP()) {
                if (IsWordSame(CurrentWord, WordNEXT)) {
                    if (LoggedIn) {
                        SONGNEXT();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordPREVIOUS)) {
                    if (LoggedIn) {
                        SONGPREVIOUS();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
            AdvWordI();
            if (IsWordSame(CurrentWord, WordADD)) {
                AdvWordI();
                if (IsEOP()) {
                    if (IsWordSame(CurrentWord, WordSONG)) {
                        if (LoggedIn) {
                            PLAYLISTADDSONG();
                        }
                        else {
                            CorrectSession = false;
                        }
                    }
                    else if (IsWordSame(CurrentWord, WordALBUM)) {
                        if (LoggedIn) {
                            PLAYLISTADDALBUM();
                        }
                        else {
                            CorrectSession = false;
                        }
                    }
                    else {
                        KnownCommand = false;
                    }
                }
                else {
                    KnownCommand = false;
                }
            }
            else {
                if (IsWordSame(CurrentWord, WordCREATE)) {
                    if (LoggedIn) {
                        PLAYLISTCREATE();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordSWAP)) {
                    if (LoggedIn) {
                        PLAYLISTSWAP();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordREMOVE)) {
                    if (LoggedIn) {
                        PLAYLISTREMOVE();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordDELETE)) {
                    if (LoggedIn) {
                        PLAYLISTDELETE();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else {
                    KnownCommand = false;
                }
            }
        }
        
        else if (IsWordSame(CurrentWord, WordSTATUS)) {
            if (IsEOP()) {
                if (LoggedIn) {
                    printf("RUN STATUS\n");
                    // STATUS();
                }
                else {
                    CorrectSession = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordSAVE)) {
            if (!IsEOP()) {
                AdvLineI();
                if (LoggedIn) {
                    SAVE();
                }
                else {
                    CorrectSession = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordQUIT)) {
            if (IsEOP()) {
                if (LoggedIn) {
                    QUIT();
                }
                else {
                    CorrectSession = false;
                }
            }
            else {
                KnownCommand = false;
            }
        }
        
        else if (IsWordSame(CurrentWord, WordHELP)) {
            if (IsEOP) {
                printf("RUN HELP\n");
                // HELP();
            }
            else {
                KnownCommand = false;
            }
        }
        // UNTUK TESTING
        else if (IsWordSame(CurrentWord, WordDISPLAY)) {
            DISPLAY();
        }
        // SAMPE SINI
        else {
            KnownCommand = false;
        }

        if (!KnownCommand || !CorrectSession) {
            INVALIDCOMMAND();
        }

        if (!IsEOF()) {
            AdvLineI();
        }
        
        printf("\n");
    }

    usleep(100000);
    printf("    __ __                         __        __                        __           _\n");
    usleep(100000);
    printf("   / //_/___ _____ ___  __  __   / /_____  / /_  ______ ______   ____/ /___ ______(_)\n");
    usleep(100000);
    printf("  / ,< / __ `/ __ `__ \\/ / / /  / //_/ _ \\/ / / / / __ `/ ___/  / __  / __ `/ ___/ /\n");
    usleep(100000);
    printf(" / /| / /_/ / / / / / / /_/ /  / ,< /  __/ / /_/ / /_/ / /     / /_/ / /_/ / /  / /\n");
    usleep(100000);
    printf("/_/ |_\\__,_/_/ /_/ /_/\\__,_/  /_/|_|\\___/_/\\__,_/\\__,_/_/      \\__,_/\\__,_/_/  /_/\n");
    usleep(100000);
    printf(" _       __                             _       __\n");
    usleep(100000);
    printf("| |     / /___ ___  ______ _____  ____ | |     / /___ __   _____\n");
    usleep(100000);
    printf("| | /| / / __ `/ / / / __ `/ __ \\/ __ `/ | /| / / __ `/ | / / _ \\\n");
    usleep(100000);
    printf("| |/ |/ / /_/ / /_/ / /_/ / / / / /_/ /| |/ |/ / /_/ /| |/ /  __/\n");
    usleep(100000);
    printf("|__/|__/\\__,_/\\__, /\\__,_/_/ /_/\\__, / |__/|__/\\__,_/ |___/\\___(_)\n");
    usleep(100000);
    printf("             /____/            /____/\n");
    usleep(100000);
    printf("\n");
    usleep(100000);
    printf("    ____            __      __       //|    //|     __\n");
    usleep(100000);
    printf("   / __ \\____ _____/ /___ _/ /_     |/||   |/||   _/_/\n");
    usleep(100000);
    printf("  / / / / __ `/ __  / __ `/ __ \\                _/_/\n");
    usleep(100000);
    printf(" / /_/ / /_/ / /_/ / /_/ / / / /              _/_/\n");
    usleep(100000);
    printf("/_____/\\__,_/\\__,_/\\__,_/_/ /_/     ______   /_/\n");
    usleep(100000);
    printf("                                   /_____/\n");
    usleep(100000);
    printf("\n");
    usleep(100000);

    return 0;
}