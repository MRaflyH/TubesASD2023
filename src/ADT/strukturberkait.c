// UDAH BIKIN UNTUK QUEUE TAPI TERNYATA GA KEPAKE
// hai dzul, ini aku rafly aja yang kerjain ya

#include "strukturberkait.h"

Address NewNodeSB(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        PasteWord(x, &Info(p));
        Next(p) = NULL;
    }
    return p;
}

void CreateSB(StrukBerkait *s){
    (*s).Next = Nil;
}

boolean IsEmptySB(StrukBerkait s) {
    return s.Next == Nil;
}

int LengthSB(StrukBerkait s) {
    Address p;
    int counter;
    p = s.Next;
    while (p != Nil) {
        p = Next(p);
        counter++;
    }
    return counter;
}

void InsertSB(StrukBerkait *s, ElType x, int i) {
    Address p;
    p = NewNodeSB(x);

    if (p != NULL) {
        if (i == 0) {
            Next(p) = (*s).Next;
            (*s).Next = p;
        }
        else {
            int counter = 0;
            Address loc = (*s).Next;
            while (counter < i - 1) {
                counter++;
                loc = Next(loc);
            }
            Next(p) = Next(loc);
            Next(loc) = p;
        }
    }
}

void DeleteSB(StrukBerkait *s, ElType *x, int i) {
    Address p;
    p = NewNodeSB(*x);

    if (p != NULL) {
        if (i == 0) {
            Next(p) = (*s).Next;
            (*s).Next = p;
        }
        else {
            int counter = 0;
            Address loc = (*s).Next;
            while (counter < i - 1) {
                counter++;
                loc = Next(loc);
            }
            p = Next(loc);
            PasteWord(Info(p), x);
            Next(loc) = Next(p);
            free(p);
        }
    }
}

void DisplaySB(StrukBerkait s) {
    Address p;
    p = s.Next;
    
    if (p == Nil) {
        printf("Kosong\n");
    }
    else {
        int i = 0;
        while (p != Nil) {
            printf("%d. ", i+1);
            DisplayWord(Info(p));
            p = Next(p);
            i++;
        }
    }
}
