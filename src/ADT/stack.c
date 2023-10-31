#include "stack.h"

Address NewNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        Info(p) = x;
        Next(p) = NULL;
    }
    return p;
}

void CreateStack(Stack *s) {
    AddrTop(*s) = Nil;
}

boolean IsEmpty(Stack s) {
    return AddrTop(s) == Nil;
}

void Push(Stack *s, ElType x) {
    Address p;
    p = NewNode(x);
    if (p != Nil) {
        Next(p) = AddrTop(*s);
        AddrTop(*s) = p;
    }
}

void Pop(Stack *s, ElType *x) {
    Address p;
    *x = Top(*s);
    p = AddrTop(*s);
    AddrTop(*s) = Next(AddrTop(*s));
    Next(p) = Nil;
    free(p);
}

void DisplayStack(Stack s) {
    Address p;
    p = AddrTop(s);
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