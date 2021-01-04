#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long unsigned llu;

int isPithagorean(int a, int b, int c) {
    if (powl(a, 2) + powl(b, 2) == powl(c, 2)) {
        return 1;
    }
    return 0;
}

int isSquare(int a) {
    if (sqrtl(a) == (int)sqrtl(a)) {
        return 1;
    }
    return 0;
}

int spt() {
    for (int i = 500; i < 1000; i++) {
        if (isSquare(i)) {
            
        }
    }
}

int main() {

    return 0;
}