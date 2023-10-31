#include "ADT/mesinkata.c"
#include "ADT/mesinkarakter.c"
#include <stdio.h>

boolean EndProgram = false;
boolean InSession;

int TempLen;
char *TempKata;
Word KataSTART;
Word KataLOAD;
Word KataLIST;
Word KataDEFAULT;
Word KataPLAYLIST;
Word KataPLAY;
Word KataSONG;
Word KataQUEUE;
Word KataSWAP;
Word KataREMOVE;
Word KataCLEAR;
Word KataNEXT;
Word KataPREVIOUS;
Word KataCREATE;
Word KataADD;
Word KataALBUM;
Word KataDELETE;
Word KataSTATUS;
Word KataSAVE;
Word KataQUIT;
Word KataHELP;


int main() {
    if (true) { // biar bisa diminimize aja
        TempLen = 5;
        TempKata = "START";
        for (int i = 0; i < TempLen; i++) {
            KataSTART.Content[i] = *TempKata;
            KataSTART.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "LOAD";
        for (int i = 0; i < TempLen; i++) {
            KataLOAD.Content[i] = *TempKata;
            KataLOAD.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "LIST";
        for (int i = 0; i < TempLen; i++) {
            KataLIST.Content[i] = *TempKata;
            KataLIST.Length++;
            TempKata++;
        }

        TempLen = 7;
        TempKata = "DEFAULT";
        for (int i = 0; i < TempLen; i++) {
            KataDEFAULT.Content[i] = *TempKata;
            KataDEFAULT.Length++;
            TempKata++;
        }

        TempLen = 8;
        TempKata = "PLAYLIST";
        for (int i = 0; i < TempLen; i++) {
            KataPLAYLIST.Content[i] = *TempKata;
            KataPLAYLIST.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "PLAY";
        for (int i = 0; i < TempLen; i++) {
            KataPLAY.Content[i] = *TempKata;
            KataPLAY.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "SONG";
        for (int i = 0; i < TempLen; i++) {
            KataSONG.Content[i] = *TempKata;
            KataSONG.Length++;
            TempKata++;
        }

        TempLen = 5;
        TempKata = "QUEUE";
        for (int i = 0; i < TempLen; i++) {
            KataQUEUE.Content[i] = *TempKata;
            KataQUEUE.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "SWAP";
        for (int i = 0; i < TempLen; i++) {
            KataSWAP.Content[i] = *TempKata;
            KataSWAP.Length++;
            TempKata++;
        }

        TempLen = 6;
        TempKata = "REMOVE";
        for (int i = 0; i < TempLen; i++) {
            KataREMOVE.Content[i] = *TempKata;
            KataREMOVE.Length++;
            TempKata++;
        }

        TempLen = 5;
        TempKata = "CLEAR";
        for (int i = 0; i < TempLen; i++) {
            KataCLEAR.Content[i] = *TempKata;
            KataCLEAR.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "NEXT";
        for (int i = 0; i < TempLen; i++) {
            KataNEXT.Content[i] = *TempKata;
            KataNEXT.Length++;
            TempKata++;
        }

        TempLen = 8;
        TempKata = "PREVIOUS";
        for (int i = 0; i < TempLen; i++) {
            KataPREVIOUS.Content[i] = *TempKata;
            KataPREVIOUS.Length++;
            TempKata++;
        }

        TempLen = 6;
        TempKata = "CREATE";
        for (int i = 0; i < TempLen; i++) {
            KataCREATE.Content[i] = *TempKata;
            KataCREATE.Length++;
            TempKata++;
        }

        TempLen = 3;
        TempKata = "ADD";
        for (int i = 0; i < TempLen; i++) {
            KataADD.Content[i] = *TempKata;
            KataADD.Length++;
            TempKata++;
        }

        TempLen = 5;
        TempKata = "ALBUM";
        for (int i = 0; i < TempLen; i++) {
            KataALBUM.Content[i] = *TempKata;
            KataALBUM.Length++;
            TempKata++;
        }

        TempLen = 6;
        TempKata = "DELETE";
        for (int i = 0; i < TempLen; i++) {
            KataDELETE.Content[i] = *TempKata;
            KataDELETE.Length++;
            TempKata++;
        }

        TempLen = 6;
        TempKata = "STATUS";
        for (int i = 0; i < TempLen; i++) {
            KataSTATUS.Content[i] = *TempKata;
            KataSTATUS.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "SAVE";
        for (int i = 0; i < TempLen; i++) {
            KataSAVE.Content[i] = *TempKata;
            KataSAVE.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "QUIT";
        for (int i = 0; i < TempLen; i++) {
            KataQUIT.Content[i] = *TempKata;
            KataQUIT.Length++;
            TempKata++;
        }

        TempLen = 4;
        TempKata = "HELP";
        for (int i = 0; i < TempLen; i++) {
            KataHELP.Content[i] = *TempKata;
            KataHELP.Length++;
            TempKata++;
        }
    }

    while (!EndProgram) {
        StartWord();

        if (IsWordSame(CurrentWord, KataSTART)) {
            printf("Run START\n");
        }

        else if (IsWordSame(CurrentWord, KataLOAD)) {
            AdvWord();
            printf("Run LOAD\n");
            DisplayWord();
        }

        else if (IsWordSame(CurrentWord, KataLIST)) {
            AdvWord();
            if (IsWordSame(CurrentWord, KataDEFAULT)) {
                printf("Run LIST DEFAULT\n");
            }
            else if (IsWordSame(CurrentWord, KataPLAYLIST)) {
                printf("Run LIST PLAYLIST\n");
            }
        }

        else if (IsWordSame(CurrentWord, KataPLAY)) {
            AdvWord();
            if (IsWordSame(CurrentWord, KataSONG)) {
                printf("Run PLAY SONG\n");
            }
            else if (IsWordSame(CurrentWord, KataPLAYLIST)) {
                printf("Run PLAY PLAYLIST\n");
            }
        }

        else if (IsWordSame(CurrentWord, KataQUEUE)) {
            AdvWord();
            if (IsWordSame(CurrentWord, KataSONG)) {
                printf("Run QUEUE SONG\n");
            }
            else if (IsWordSame(CurrentWord, KataPLAYLIST)) {
                printf("Run QUEUE PLAYLIST\n");
            }
            else if (IsWordSame(CurrentWord, KataSWAP)) {
                printf("Run QUEUE SWAP\n");
                AdvWord();
                DisplayWord();
                AdvWord();
                DisplayWord();
            }
            else if (IsWordSame(CurrentWord, KataREMOVE)) {
                printf("Run QUEUE REMOVE\n");
                AdvWord();
                DisplayWord();
            }
            else if (IsWordSame(CurrentWord, KataCLEAR)) {
                printf("Run QUEUE CLEAR\n");
            }
        }

        else if (IsWordSame(CurrentWord, KataSONG)) {
            AdvWord();
            if (IsWordSame(CurrentWord, KataNEXT)) {
                printf("Run SONG NEXT\n");
            }
            else if (IsWordSame(CurrentWord, KataPREVIOUS)) {
                printf("Run SONG PREVIOUS\n");
            }
        }

        else if (IsWordSame(CurrentWord, KataPLAYLIST)) {
            AdvWord();
            if (IsWordSame(CurrentWord, KataCREATE)) {
                printf("Run PLAYLIST CREATE\n");
            }
            else if (IsWordSame(CurrentWord, KataADD)) {
                AdvWord();
                if (IsWordSame(CurrentWord, KataSONG)) {
                    printf("Run PLAYLIST ADD SONG\n");
                }
                else if (IsWordSame(CurrentWord, KataALBUM)) {
                    printf("Run PLAYLIST ADD ALBUM\n");
                }
            }
            else if (IsWordSame(CurrentWord, KataSWAP)) {
                printf("Run PLAYLIST SWAP\n");
                AdvWord();
                DisplayWord();
                AdvWord();
                DisplayWord();
                AdvWord();
                DisplayWord();
            }
            else if (IsWordSame(CurrentWord, KataREMOVE)) {
                printf("Run PLAYLIST SWAP\n");
                AdvWord();
                DisplayWord();
                AdvWord();
                DisplayWord();
            }
            else if (IsWordSame(CurrentWord, KataDELETE)) {
                printf("Run PLAYLIST DELETE\n");
            }
        }

        else if (IsWordSame(CurrentWord, KataSTATUS)) {
            printf("Run STATUS\n");
        }

        else if (IsWordSame(CurrentWord, KataSAVE)) {
            printf("Run SAVE\n");
        }

        else if (IsWordSame(CurrentWord, KataQUIT)) {
            printf("Run QUIT\n");
        }

        else if (IsWordSame(CurrentWord, KataHELP)) {
            printf("Run HELP\n");
        }
        
        else {
            printf("Command Unknown\n");
        }

        EndProgram = true;
    }
    return 0;
}