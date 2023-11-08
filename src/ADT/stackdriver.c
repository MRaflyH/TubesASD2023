#include "stack.h"

int main() {
    Stack s;
    Word w1, w2, w3;
    Detail d;

    CreateS(&s);

    CreateWord(4, "satu", &w1);
    CreateWord(4, "utas", &w2);
    CreateWord(4, "tasu", &w3);
    CreateD(&d, w1, w2, w3);
    PushS(&s, d);
    CreateWord(3, "dua", &w1);
    CreateWord(3, "aud", &w2);
    CreateWord(3, "uda", &w3);
    CreateD(&d, w1, w2, w3);
    PushS(&s, d);
    CreateWord(4, "tiga", &w1);
    CreateWord(4, "agit", &w2);
    CreateWord(4, "gati", &w3);
    CreateD(&d, w1, w2, w3);
    PushS(&s, d);
    CreateWord(5, "empat", &w1);
    CreateWord(5, "patem", &w2);
    CreateWord(5, "pamte", &w3);
    CreateD(&d, w1, w2, w3);
    PushS(&s, d);

    PopS(&s, &d);

    printf("Setelah dipop:\n");
    DisplayS(s);

    printf("\nKata yang dipop: ");
    DisplayD(d);

    return 0;
}