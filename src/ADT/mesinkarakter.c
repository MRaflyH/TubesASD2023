#include "mesinkarakter.h"

char CurrentChar;
boolean EOP;

static FILE *pita;
static int retval;

void Start() {
    EOP = false;
    pita = stdin;
    Adv();
}

void Adv() {
    retval = fscanf(pita, "%c", &CurrentChar);
    EOP = (CurrentChar == Mark);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
    return CurrentChar;
}

boolean IsEOP() {
    return (CurrentChar == Mark);
}
