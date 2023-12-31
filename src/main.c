#include "data.h"
#include "console.h"

int main() {
    Initiate();
    PRINTWELCOME();
    printf("\n");
    HELP();
    printf("\n");

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
            if (IsEOP()) {
                if (IsWordSame(CurrentWord, WordDEFAULT)) {
                    if (LoggedIn) {
                        LISTDEFAULT();
                    }
                    else {
                        CorrectSession = false;
                    }
                }
                else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                    if (LoggedIn) {
                        LISTPLAYLIST();
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
            if (IsWordSame(CurrentWord, WordSWAP)) {
                if (LoggedIn) {
                    QUEUESWAP();
                }
                else {
                    CorrectSession = false;
                }
            }
            else if (IsWordSame(CurrentWord, WordREMOVE)) {
                if (LoggedIn) {
                    QUEUEREMOVE();
                }
                else {
                    CorrectSession = false;
                }
            }
            else {
                if (IsEOP()) {
                    if (IsWordSame(CurrentWord, WordSONG)) {
                        if (LoggedIn) {
                            QUEUESONG();
                        }
                        else {
                            CorrectSession = false;
                        }
                    }
                    else if (IsWordSame(CurrentWord, WordPLAYLIST)) {
                        if (LoggedIn) {
                            QUEUEPLAYLIST();
                        }
                        else {
                            CorrectSession = false;
                        }
                    }
                    else if (IsWordSame(CurrentWord, WordCLEAR)) {
                        if (LoggedIn) {
                            QUEUECLEAR();
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
                if (IsWordSame(CurrentWord, WordSWAP)) {
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
                else {
                    if (IsEOP()) {
                        if (IsWordSame(CurrentWord, WordCREATE)) {
                            if (LoggedIn) {
                                PLAYLISTCREATE();
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
                    else {
                        KnownCommand = false;
                    }
                }
            }
        }
        
        else if (IsWordSame(CurrentWord, WordSTATUS)) {
            if (IsEOP()) {
                if (LoggedIn) {
                    STATUS();
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
            if (IsEOP()) {
                HELP();
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
        else if (IsWordSame(CurrentWord, WordENHANCE)) {
            ENHANCE();
        }

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

    PRINTKELUAR();

    return 0;
}