#include <stdio.h>
#include <ctype.h>

typedef enum {
    FIND,
    HEX,
    SKIP
} State;

int separator(char s) {
    char *m = " \t,\n";
    for (int i = 0; i < 4; i++) {
        if (s == m[i]) return 1;
    }
    return 0;
}

int isHex(char s) {
    return (s >= '0' && s <= '9') || (tolower(s) >= 'a' && tolower(s) <= 'f');
}

int main(void) {
    State state = FIND;
    char hexNumber[9]; // Максимальная длина шестнадцатеричного числа (8 символов) + '\0'
    int hexIndex = 0;
    int maxDigits = 0;
    int currentDigits = 0;
    int chr;

    while ((chr = getchar()) != EOF) {
        switch (state) {
            case SKIP: {
                if (separator(chr)) {
                    state = FIND;
                }
            } break;

            case FIND: {
                if (!separator(chr)) {
                    state = HEX;
                    hexNumber[hexIndex++] = chr;
                    currentDigits = 1;
                }
            } break;

            case HEX: {
                if (isHex(chr)) {
                    if (hexIndex < 8) {
                        hexNumber[hexIndex++] = chr;
                        currentDigits++;
                    }
                } else {
                    hexNumber[hexIndex] = '\0';
                    hexIndex = 0;
                    state = FIND;

                    if (currentDigits > 0 && (currentDigits < maxDigits || maxDigits == 0)) {
                        maxDigits = currentDigits;
                    }
                }
            } break;

            default: {
                if (separator(chr)) {
                    state = FIND;
                }
            } break;
        }
    }

    printf("Max digits: %d\n", maxDigits);

    fseek(stdin, 0, SEEK_SET); // Сброс ввода на начало

    state = FIND;
    hexIndex = 0;

    while ((chr = getchar()) != EOF) {
        switch (state) {
            case SKIP: {
                if (separator(chr)) {
                    state = FIND;
                }
            } break;

            case FIND: {
                if (!separator(chr)) {
                    state = HEX;
                    hexNumber[hexIndex++] = chr;
                    currentDigits = 1;
                }
            } break;

            case HEX: {
                if (isHex(chr)) {
                    if (hexIndex < 8) {
                        hexNumber[hexIndex++] = chr;
                        currentDigits++;
                    }
                } else {
                    hexNumber[hexIndex] = '\0';
                    hexIndex = 0;
                    state = FIND;

                    if (currentDigits == maxDigits) {
                        printf("%s\n", hexNumber);
                    }
                }
            } break;

            default: {
                if (separator(chr)) {
                    state = FIND;
                }
            } break;
        }
    }

    return 0;
}
