#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SIGN(a) ((a) < 0 ? -1 : (a) > 0 ? 1 : 0)
#define MOD(a, b) ((a) >= 0 ? (a) % (b) : ((a) + (b) - ((a) / (b) * (b))) % (b))
#define ABS(a) ((a) >= 0 ? (a) : -(a))

int check_place(int i, int j) {
    int circle_1 = ((i + 10) * (i + 10) + (j + 10) * (j + 10)) <= 100;
    int circle_2 = ((i + 20) * (i + 20) + (j + 20) * (j + 20)) <= 100;
    return circle_1 && circle_2;
}


void move(int count) {
    int i = 5, j = 5, l = 4;
    int result_k = -1;

    for (int k = 0; k < count; k++) {
        int temp_i = i, temp_j = j, temp_l = l;

        i = (float)i / 3 - ABS(i - k) * SIGN(l - j);
        j = MOD(temp_j, 10) - MOD(MAX(temp_i, temp_l), k + 1);
        l = temp_i + MOD(temp_j * k, 5) + (float)temp_l / 5 + 3;

        if (check_place(i, j) && result_k == -1 && k <= 50) {
            result_k = k;
        }
    }
    if (result_k != -1) {
        printf("Getting into a given area in %d steps.\n", result_k);
    } else {
        printf("Hit in the specified area is not fixed.\n");
    }
    printf("The movement is stopped at a step %d.\n", count);
    printf("Stop at a point (%d, %d).\n", i, j);
    printf("The dynamic motion parameter is equal to %d.\n", l);
}

int main() {
    move(50);
    return 0;
}