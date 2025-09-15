#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Використаємо приклад: f(x) = 4x³ – 2x² – 5x + 0.25 */
double f_variant(double x) {
    return 4*pow(x,3) - 2*pow(x,2) - 5*x + 0.25;
}

int main(void) {
    double X1, X2, delta;
    unsigned int N;
    int mode;

    printf("Виберіть режим:\n1 - X1, X2, N\n2 - X1, X2, delta\nВибір: ");
    if (scanf("%d", &mode) != 1) return 1;

    printf("Введіть X1: "); scanf("%lf", &X1);
    printf("Введіть X2: "); scanf("%lf", &X2);
    if (X2 <= X1) { printf("X2 має бути > X1\n"); return 1; }

    if (mode == 1) {
        printf("Введіть N: "); scanf("%u", &N);
        if (N < 2) { printf("N >= 2\n"); return 1; }
        delta = (X2 - X1) / (N - 1);
    } else if (mode == 2) {
        printf("Введіть delta: "); scanf("%lf", &delta);
        if (delta <= 0) { printf("delta > 0\n"); return 1; }
        N = (unsigned int)(floor((X2 - X1)/delta) + 1);
    } else {
        printf("Невірний режим.\n");
        return 1;
    }

    printf("\nТаблиця значень функції:\n");
    printf("-----------------------------------------------------------\n");
    printf("| %6s | %12s | %15s |\n", "№", "x", "f(x)");
    printf("-----------------------------------------------------------\n");

    double prev_x = X1;
    double prev_fx = f_variant(prev_x);

    for (unsigned int i = 0; i < N; ++i) {
        double x = X1 + i*delta;
        if (i == N-1) x = X2; /* точне завершення */
        double fx = f_variant(x);

        printf("| %6u | %12.6lf | %15.6lf |\n", i+1, x, fx);

        if (i > 0) {
            if (prev_fx == 0.0) {
                printf("  Корінь в точці x = %.6lf\n", prev_x);
            } else if (prev_fx * fx < 0.0) {
                printf("  Знак змінюється на [%.6lf, %.6lf]\n", prev_x, x);
            }
        }

        prev_x = x;
        prev_fx = fx;
    }
    printf("-----------------------------------------------------------\n");

    return 0;
}