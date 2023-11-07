#include "mesinkarakter.h"

char CurrentChar;
boolean EOP;

static FILE *pita;
static int retval;

void Start() {
    printf("JALAN\n");
    pita = stdin;
    Adv();
}

void Adv() {
    retval = fscanf(pita, "%c", &CurrentChar);
    EOP = (CurrentChar == Mark);
}

char GetCC() {
    return CurrentChar;
}

boolean IsEOP() {
    return (CurrentChar == Mark);
}
