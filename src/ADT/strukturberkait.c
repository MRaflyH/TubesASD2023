// UDAH BIKIN UNTUK QUEUE TAPI TERNYATA GA KEPAKE
// hai dzul, ini aku rafly aja yang kerjain ya

#include "strukturberkait.h"

Address NewNodeSB(Detail x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        PasteD(x, &Info(p));
        Next(p) = NULL;
    }
    return p;
}

boolean IsIdxValidSB(StrukBerkait s, int i) {
    return i < LengthSB(s) && i >= 0;
}

void CreateSB(StrukBerkait *s){
    First(*s) = Nil;
}

boolean IsEmptySB(StrukBerkait s) {
    return First(s) == Nil;
}

int LengthSB(StrukBerkait s) {
    Address p;
    int counter;
    counter = 0;
    p = First(s);
    while (p != Nil) {
        p = Next(p);
        counter++;
    }
    return counter;
}
void GetSB(StrukBerkait *s, Detail *x, int i) {
    int idx;
    Address p;

    idx = 0;
    p = First(*s);

    while (p != Nil && idx != i) {
        idx++;
        p = Next(p);
    }

    if (i == idx) {
        PasteD(Info(p), x);
    }

}

void SetSB(StrukBerkait *s, Detail x, int i) {
    int idx;
    Address p;

    idx = 0;
    p = First(*s);

    while (p != Nil && idx != i) {
        idx++;
        p = Next(p);
    }

    if (i == idx) {
        PasteD(x, &Info(p));
    }
}

void InsertSB(StrukBerkait *s, Detail x, int i) {
    Address p;
    p = NewNodeSB(x);

    if (p != NULL) {
        if (i == 0) {
            Next(p) = First(*s);
            First(*s) = p;
        }
        else {
            int counter = 0;
            Address loc = First(*s);
            while (counter < i - 1) {
                counter++;
                loc = Next(loc);
            }
            Next(p) = Next(loc);
            Next(loc) = p;
        }
    }
}

void DeleteSB(StrukBerkait *s, Detail *x, int i) {
    Address p;
    p = First(*s);

    if (p != NULL) {
        if (i == 0) {
            Next(p) = First(*s);
            First(*s) = p;
        }
        else {
            int counter = 0;
            Address loc = First(*s);
            while (counter < i - 1) {
                counter++;
                loc = Next(loc);
            }
            p = Next(loc);
            PasteD(Info(p), x);
            Next(loc) = Next(p);
            free(p);
        }
    }
}

void DisplaySB(StrukBerkait s) {
    Address p;
    p = First(s);
    
    if (p == Nil) {
        printf("Kosong\n");
    }
    else {
        int i = 0;
        while (p != Nil) {
            printf("%d. ", i+1);
            DisplayD(Info(p));
            p = Next(p);
            i++;
        }
    }
}
