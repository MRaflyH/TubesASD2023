#include "file3.h"

int isPrime(int i) {
    if (isEven(i)) {
        return 1;
    }
    return i % 3 == 0;
}
