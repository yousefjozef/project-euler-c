#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef long long unsigned llu;
typedef long unsigned lu;

typedef struct PrimeListO
{
    lu data;
    struct PrimeListO *next;
} PrimeList;

PrimeList *head = NULL;
FILE *log_file = NULL;

void init();
PrimeList *new_ele(lu data);
PrimeList *push(PrimeList *ele, lu data);
PrimeList *next(PrimeList *ele);

lu np_prime(lu prime);
bool is_prime(lu prime);
lu next_prime(lu n);
llu prime_sum(lu range);
void print_log(lu n, llu sum);

void init() {
    head = new_ele(2);
}

PrimeList *new_ele(lu data) {
    PrimeList *ele = (PrimeList*)malloc(sizeof(PrimeList));
    ele->data = data;
    ele->next = NULL;
}

PrimeList *push(PrimeList *ele, lu data) {
    ele->next = new_ele(data);
    return ele->next;
}

PrimeList *next(PrimeList *ele) {
    if (!ele->next) {
        push(ele, next_prime(ele->data));
    }
    return ele->next;
}

lu np_prime(lu prime) {
    if (prime == 2) return 3;
    if (prime == 3) return 5;
    if (prime % 6 == 5) return prime + 2;
    if (prime % 6 == 1) return prime + 4;
}

bool is_prime(lu n) {
    for (PrimeList *i = head; i->data <= sqrtl(n); i = next(i)) {
        if (n % i->data == 0) {
            return false;
        }
    }
    return true;
}

lu next_prime(lu n) {
    do
    {
        n = np_prime(n);
    } while (!is_prime(n));
    return n;
}

llu prime_sum(lu range) {
    init();
    llu sum = 0;
    for (PrimeList *i = head; i->data < range; i = next(i)) {
        sum += i->data;
        print_log(i->data, sum);
    }
    return sum;
}

void print_log(lu n, llu sum) {
    fprintf(log_file, "%-12lu | %16llu\n", n, sum);
}

int main(int argc, char *argv[]) {
    clock_t t = clock();
    lu range;
    log_file = fopen("prime.log", "w+");
    sscanf(argv[1], "%lu", &range);
    printf("%llu\n", prime_sum(range));
    printf("%f", (float)(clock() - t) / CLOCKS_PER_SEC);
    fclose(log_file);
    return 0;
}