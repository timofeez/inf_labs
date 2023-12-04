#include <stdio.h>
#include <stdint.h>

typedef enum {
    FIND,
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    SKIP
} State;

int separator(char s) {
    char *m = " \t,\n";
    for (int i = 0; i < 4; i++) {
        if (s == m[i]) return 1;
    }
    return 0;
}

int main(void) {
    int counter = 0;
    int maxDigitCount = 0;
    char maxHexNumber[9];  // Место для хранения максимального числа в шестнадцатеричной системе

    char fcache, scache;
    int chr;

    State state = FIND;

    while ((chr = getchar()) != EOF) {
        switch (state) {
            case SKIP:
            {
                if (separator(chr)) state = FIND;
            }
            break;

            case FIND:
            {
                if (!separator(chr)) {
                    state = FIRST;
                    fcache = chr;
                }
            }
            break;

            case FIRST:
            {
                if (((chr == '1' | chr == '0') && fcache == '0') | (chr == '0' && fcache == '1')) {
                    state = SECOND;
                    scache = chr;
                } else if (!separator(chr)) {
                    state = SKIP;
                } else {
                    state = FIND;
                }
            }
            break;

            case SECOND:
            {
                if (chr == '1' && scache == '0' && fcache == '1') {
                    state = SKIP;
                } else if (chr == '0' | chr == '1') {
                    state = THIRD;
                } else if (!separator(chr)) {
                    state = SKIP;
                } else {
                    state = FIND;
                }
            }
            break;

            case THIRD:
            {
                if (chr == '0' | chr == '1') {
                    state = FOURTH;
                } else if (!separator(chr)) {
                    state = SKIP;
                } else {
                    state = FIND;
                }
            }
            break;

            case FOURTH:
            {
                if (chr == '0' | chr == '1') {
                    state = FIRST;
                    fcache = chr;
                } else if (separator(chr)) {
                    counter++;

                    // Переводим текущее четырехбитное число в десятичное и проверяем, является ли оно максимальным
                    uint32_t currentNumber = strtol(maxHexNumber, NULL, 16);
                    int digitCount = snprintf(NULL, 0, "%X", currentNumber);

                    if (digitCount > maxDigitCount) {
                        maxDigitCount = digitCount;
                    }

                    state = FIND;
                } else {
                    state = SKIP;
                }
            }
            break;
        }
    }

    if (state == FOURTH) {
        counter++;

        // Переводим текущее четырехбитное число в десятичное и проверяем, является ли оно максимальным
        uint32_t currentNumber = strtol(maxHexNumber, NULL, 16);
        int digitCount = snprintf(NULL, 0, "%X", currentNumber);

        if (digitCount > maxDigitCount) {
            maxDigitCount = digitCount;
        }
    }

    printf("Общее количество шестнадцатиричных чисел: %d\n", counter);
    printf("Максимальное число цифр в 32-битной архитектуре: %d\n", maxDigitCount);

    return 0;
}
