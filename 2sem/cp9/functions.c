#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

line l[MAX_TEXT_SIZE];
int n = 0;

void print_table() {
    printf("====================\n");
    for (int i = 0; i < n; i++) {
        printf("%d  %s\n", l[i].key, l[i].str);
    }
    printf("====================\n");
}

void sorting() {
    int left = 0, right = n - 1;
    int flag = 1;
    while ((left < right) && flag) {
        flag = 0;
        for (int i = left; i < right; i++) {
            if (l[i].key > l[i+1].key) {
                line tmp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = tmp;
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (l[i].key < l[i-1].key) {
                line tmp = l[i];
                l[i] = l[i - 1];
                l[i - 1] = tmp;
                flag = 1;
            }
        }
        left++;
    }
}

void random_table() {
    for (int i = 0; i < n; ++i) {
        int j = rand() % n; // Использование rand() вместо random()
        line t = l[i];
        l[i] = l[j];
        l[j] = t;
    }
}

void reverse_table() {
    for (int i = 0; i < n / 2; ++i) {
        line t = l[i];
        l[i] = l[n - i - 1];
        l[n - i - 1] = t;
    }
}

int binary_search(int key) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (l[mid].key == key) {
            return mid; // Ключ найден, возвращаем индекс
        } else if (l[mid].key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Ключ не найден
}