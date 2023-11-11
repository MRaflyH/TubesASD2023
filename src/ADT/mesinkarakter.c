#include "mesinkarakter.h"

char CurrentChar;
boolean EOP;

static FILE *pita;
static int retval;

void StartF(char * FileName) {
    pita = fopen(FileName, "r");
    Adv();
}

void StartWrite(char * FileName) {
    pita = fopen(FileName, "w");
}

void Start() {
    pita = stdin;
    Adv();
}

void Adv() {
    retval = fscanf(pita, "%c", &CurrentChar);
    EOP = feof(pita);
}
void AdvWrite(char cc) {
    fprintf(pita, "%c", cc);
}
void AdvWriteBlank() {
    fprintf(pita, "%c", Blank);
}
void AdvWriteMark() {
    fprintf(pita, "%c", Mark);
}
void AdvWriteNewLine() {
    fprintf(pita, "%c", NewLine);
}

void EndWrite() {
    fclose(pita);
}

char GetCC() {
    return CurrentChar;
}

boolean IsEOP() {
    return (feof(pita));
}
