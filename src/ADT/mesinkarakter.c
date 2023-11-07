#include "mesinkarakter.h"

char CurrentChar;
boolean EOP;

static FILE *pita;
static int retval;

void Start(char * FileName) {
    pita = fopen(FileName, 'r');
    Adv();
}

void Start() {
    printf(">> ");
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
