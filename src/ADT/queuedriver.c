#include "queue.h"

int main() {
    Queue q;
    Word w1, w2, w3;
    Detail d;

    CreateQ(&q);
    printf("IsEmpty: %d\n", IsEmptyQ(q));

    CreateWord(4, "satu", &w1);
    CreateWord(4, "utas", &w2);
    CreateWord(4, "tasu", &w3);
    CreateD(&d, w1, w2, w3);
    EnqueueQ(&q, d);
    CreateWord(3, "dua", &w1);
    CreateWord(3, "aud", &w2);
    CreateWord(3, "uda", &w3);
    CreateD(&d, w1, w2, w3);
    EnqueueQ(&q, d);
    CreateWord(4, "tiga", &w1);
    CreateWord(4, "agit", &w2);
    CreateWord(4, "gati", &w3);
    CreateD(&d, w1, w2, w3);
    EnqueueQ(&q, d);
    CreateWord(5, "empat", &w1);
    CreateWord(5, "patem", &w2);
    CreateWord(5, "pamte", &w3);
    CreateD(&d, w1, w2, w3);
    EnqueueFirstQ(&q, d);

    printf("Length: %d\n", LengthQ(q));
    printf("IsIdxValid 0: %d\n", IsIdxValidQ(&q, 0));
    printf("IsIdxValid 100: %d\n", IsIdxValidQ(&q, 100));

    DisplayQ(q);
    DequeueQ(&q, &d);
    printf("\nsetelah dequeque\n");
    DisplayQ(q);
    printf("\nyang dequeque: ");
    DisplayD(d);

    return 0;
}