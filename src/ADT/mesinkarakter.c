#include "mesinkarakter.h"

char CurrentChar;
boolean EOP;

static FILE *pita;
static int retval;

void StartF(char * FileName) {
    pita = fopen(FileName, "r");
    Adv();
}

void Start() {
    pita = stdin;
    Adv();
}

void Adv() {
    retval = fscanf(pita, "%c", &CurrentChar);
    EOP = feof(pita);
}

char GetCC() {
    return CurrentChar;
}

boolean IsEOP() {
    return (feof(pita));
}
