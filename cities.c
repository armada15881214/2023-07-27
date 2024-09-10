#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_CITIES 26

typedef struct {
    char name;
    int x;
    int y;
} City;

double distance(City a, City b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void swap(City *a, City *b) {
    City temp = *a;
    *a = *b;
    *b = temp;
}

double total_distance(City *cities, int n) {
    double total = 0;
    for (int i = 0; i < n - 1; i++) {
        total += distance(cities[i], cities[i + 1]);
    }
    total += distance(cities[n - 1], cities[0]);
    return total;
}

void permute(City *cities, int l, int r, City *best_permutation, double *best_distance) {
    if (l == r) {
        double current_distance = total_distance(cities, r + 1);
        if (current_distance < *best_distance) {
            for (int i = 0; i <= r; i++) {
                best_permutation[i] = cities[i];
            }
            *best_distance = current_distance;
        }
    } else {
        for (int i = l; i <= r; i++) {
            swap(&cities[l], &cities[i]);
            permute(cities, l + 1, r, best_permutation, best_distance);
            swap(&cities[l], &cities[i]);
        }
    }
}

int main() {
    int n;
    printf("èÑâÒÇ∑ÇÈìsésÇÃêîÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢: ");
    scanf("%d", &n);

    if (n > MAX_CITIES) {
        printf("ìsésÇÃêîÇ™ëΩÇ∑Ç¨Ç‹Ç∑ÅBç≈ëÂ26ìsésÇ‹Ç≈Ç≈Ç∑ÅB\n");
        exit(1);
    }

    City cities[n];
    for (int i = 0; i < n; i++) {
        cities[i].name = 'A' + i;
        printf("%cÇÃxç¿ïWÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢: ", cities[i].name);
        scanf("%d", &cities[i].x);
        printf("%cÇÃyç¿ïWÇì¸óÕÇµÇƒÇ≠ÇæÇ≥Ç¢: ", cities[i].name);
        scanf("%d", &cities[i].y);
    }

    City best_permutation[n];
    double best_distance = INFINITY;
    permute(cities, 0, n - 1, best_permutation, &best_distance);

    printf("ç≈íZãóó£: %f\n", best_distance);
    printf("ç≈ìKÇ»èáèò: ");
    for (int i = 0; i < n; i++) {
        printf("%c ", best_permutation[i].name);
    }
    printf("\n");

    return 0;
}
