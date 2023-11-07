#include "queue.h"

int main() {
    Queue q;
    Word w;
    CreateQ(&q);

    CreateWord(4, "satu", &w);
    EnqueueQ(&q, w);
    CreateWord(3, "dua", &w);
    EnqueueQ(&q, w);
    CreateWord(4, "tiga", &w);
    EnqueueQ(&q, w);
    CreateWord(5, "empat", &w);
    EnqueueQ(&q, w);

    DisplayQ(q);

    return 0;
}