#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>

typedef unsigned long long llu;
typedef unsigned long lu;

typedef struct Triplet__ {
    int a;
    int b;
    int c;
} Triplet;

FILE *file_log = NULL;

lu pow2(int n);

bool is_pythagorean(Triplet t);
int sum(Triplet t);
Triplet even_generator(int a);
Triplet odd_generator(int a);
bool for_condition(Triplet t);
llu pythagorean();
void print_log(Triplet t, int s);

lu pow2(int n) {
    return (lu)pow(n, 2);
}

bool is_pythagorean(Triplet t) {
    return pow2(t.a) + pow2(t.b) == pow2(t.c);
}

int sum(Triplet t) {
    return t.a + t.b + t.c;
}

Triplet even_generator(int n) {
    return (Triplet){n, pow2(n/2) - 1, pow2(n/2) + 1};
}

Triplet odd_generator(int n) {
    return (Triplet){n, pow2(n) / 2, pow2(n) / 2 + 1};
}

bool for_condition(Triplet t) {
    int s = sum(t);
    print_log(t, s);
    bool first = is_pythagorean(t) && (s == 1000);
    if (first) return false;
    return s < 2000;
}

llu pythagorean() {
    Triplet t = {3, 4, 5};
    for (int i = 5; for_condition(t); i++) {
        if (i & 1) {
            t = odd_generator(i);
        }
        else {
            t = even_generator(i);
        }
    }
    return (llu)t.a * t.b * t.c;
}

void print_log(Triplet t,int s) {
    fprintf(file_log, "%-3d | %-3d | %-3d | %-4d\n", t.a, t.b, t.c, s);
}

int main() {
    file_log = fopen("pythagorean.log", "w+");
    llu result = pythagorean();
    printf("%llu\n", result);
    fclose(file_log);
    return 0;
}