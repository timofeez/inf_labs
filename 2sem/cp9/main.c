#include <stdbool.h>
#include "functions.h"
#include "functions.c"
#include <string.h>

int main() {
    FILE *f = fopen("input", "r");
    FILE *k = fopen("key", "r");
    if (!(f) || !(k)) {
        printf("Error, can`t open files\n");
        return 0;
    }
    while (fgets(l[n].str, MAX_STRING_SIZE, f) != NULL) {
        // Удаляем символ новой строки из конца строки, если он там есть
        l[n].str[strcspn(l[n].str, "\n")] = 0;
        if (fscanf(k, "%u", &l[n].key) != 1) {
            break; // Ошибка чтения ключа или достигнут конец файла ключей
        }
        ++n;
    }
    int ans, c = 1;
    while (c) {
        printf("1. Print table\n2. Sort\n3. Random\n4. Reverse\n5. Binary search\n6. Exit\n");
        scanf("%d", &ans);
        switch (ans) {
            case 1: {
                print_table();
                break;
            }
            case 2: {
                printf("Before:\n");
                print_table();
                sorting();
                printf("After:\n");
                print_table();
                break;
            }
            case 3: {
                random_table();
                break;
            }
            case 4: {
                reverse_table();
                break;
            }
            case 5: {
                int key;
                scanf("%d", &key);
                int index = binary_search(key);
                if (index != -1) {
                    printf("Element found at index %d: %d  %s\n", index, l[index].key, l[index].str);
                } 
                else {
                printf("Element with key %d not found.\n", key);
                }
            break;
        }
            case 6: {
                c = 0;
                break;
            }
            default: {
                printf("Wrong answer\n");
            }
        }
    }
	fclose(f);
	fclose(k);
    return 0;
}