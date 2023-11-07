#include "stack.h"

int main() {
    Stack s;
    Word w;

    CreateS(&s);

    CreateWord(6, "pisang", &w);
    PushS(&s, w);

    CreateWord(6, "banana", &w);
    PushS(&s, w);

    CreateWord(6, "goreng", &w);
    PushS(&s, w);

    CreateWord(3, "api", &w);
    PushS(&s, w);

    DisplayS(s);

    PopS(&s, &w);

    printf("\nSetelah dipop:\n");
    DisplayS(s);

    printf("\nKata yang dipop: ");
    DisplayWord(w);

    return 0;
}