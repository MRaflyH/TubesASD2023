// UDAH BIKIN UNTUK QUEUE TAPI TERNYATA GA KEPAKE
#include "strukturberkait.h"

Address NewNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        Info(p) = x;
        Next(p) = NULL;
    }
    return p;
}

void CreateQueue(Queue *q) {
    AddrHead(*q) = Nil;
    AddrTail(*q) = Nil;
}

boolean IsEmpty(Queue q) {
    return AddrHead(q) == Nil && AddrTail(q) == Nil;
}

int Length(Queue q) {
    Address p;
    int counter;
    p = AddrHead(q);
    while (p != Nil) {
        counter++;
        p = Next(p);
    }
    return counter;
}

void Enqueue(Queue *q, ElType x) {
    Address p;
    p = NewNode(x);
    if (p != NULL) {
        if (IsEmpty(*q)) {
            AddrHead(*q) = p;
        }
        else {
            Next(AddrTail(*q)) = p;
        }
        AddrTail(*q) = p;
    }
}

void Dequeue(Queue *q, ElType *x) {
    Address p;
    *x = Head(*q);
    p = AddrHead(*q);
    AddrHead(*q) = Next(AddrHead(*q));
    if (AddrHead(*q) == Nil) {
        AddrHead(*q) = Nil;
    }
    Next(p) = Nil;
    free(p);
}

void DisplayQueue(Queue q) {
    Address p;
    p = AddrHead(q);
    printf("[");
    while (p != Nil) {
        printf("%d", Info(p));
        p = Next(p);
        if (p != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}
