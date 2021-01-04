#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<time.h>

typedef unsigned long long llu;
typedef unsigned long lu;

FILE *log_file = NULL;

void print_log(unsigned a, unsigned b, unsigned c, bool is_pythagorean) {
    char *str;
    if (is_pythagorean) str = "true";
    else                str = "false";
    fprintf(log_file, "%-3u | %-3u | %-3u | %s\n", a, b, c, str);
    fflush(log_file);
    
}

lu pow2(unsigned n) {
    return (lu)n * n;
}

bool is_pythagorean(unsigned a, unsigned b, unsigned c) {
    return (pow2(a) + pow2(b) == pow2(c));
}

llu pythagorean() {
    bool loop = true;
    unsigned a, b, c;
    for (unsigned i = 501; i < 1000; i++) {
        for (unsigned j = 1; (j < 251) && loop; j++) {
            a = j;
            b = i - j;
            c = 1000 - i;
            if(c < b ) continue;
            loop = !is_pythagorean(a, b, c);
            print_log(a, b, c, !loop);
        }
    }
    fprintf(log_file, "-------------------------------------\n");
    fprintf(log_file, "%lu\n", (lu)a + b + c);
    return (llu)a * b * c;
}

int main(int argc, char *argv[]) {
    log_file = fopen("pythagorean.log", "w+");
    llu result = pythagorean();
    printf("%llu\n", result);
    fclose(log_file);
    return 0;
}