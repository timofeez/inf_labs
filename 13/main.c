#include <stdio.h>
#include <wctype.h>

int separator(char s) {
    char *m = " \t,\n";
    for (int i = 0; i < 4; i++) {
        if (s == m[i]) return 1;
    }
    return 0;
}

int main(void) {
    const unsigned int lu = 1;
    unsigned int uppercaseLetters = 0;
    unsigned int currentWord = 0;
    int hasWordWithMoreThanOneUppercase = 0;
    int wordCount = 0;

    char chr;
    int wordLength = 0;
    int hasStartedWord = 0; // Флаг для отслеживания начала нового слова

    while ((chr = getchar()) != EOF) {
        if (separator(chr)) {
            if (hasStartedWord) {
                // Обработка конца слова
                if (wordLength > 1) {
                    int quantity = 0;
                    unsigned int upperMask = currentWord & uppercaseLetters;
                    while (upperMask) {
                        quantity += upperMask & 1;
                        upperMask >>= 1;
                        if (quantity == 2) {
                            hasWordWithMoreThanOneUppercase = 1;
                            wordCount++;
                            break; // Выход из цикла подсчёта, если найдены две заглавные буквы
                        }
                    }
                }
                // Сброс состояния текущего слова
                currentWord = 0;
                uppercaseLetters = 0;
                wordLength = 0;
                hasStartedWord = 0;
            }
        } else {
            currentWord = currentWord | (lu << (towlower(chr) - 'a'));
            if (iswupper(chr)) {
                uppercaseLetters = uppercaseLetters | (lu << (towlower(chr) - 'a'));
            }
            wordLength++;
            hasStartedWord = 1; // Устанавливаем флаг, что началось новое слово
        }
    }

    if (hasWordWithMoreThanOneUppercase) {
        printf("Yes, there is a word with more than one uppercase letter.\n");
        printf("Total words: %d\n", wordCount);
    } else {
        printf("No, there is no word with more than one uppercase letter.\n");
    }

    return 0;
}
