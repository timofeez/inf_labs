#include <stdio.h>
#include "udt.c"

void print_menu() {
    printf("What do you want to do?\n");
    printf("1: Push item\n");
    printf("2: Pop item\n");
    printf("3: Print queue\n");
    printf("4: Get size\n");
    printf("5: Shift smaller\n");
    printf("6: Insertion sort\n");
    printf("7: Exit\n");
    printf(">");
}

int main(int argc, char *argv[])
{
    int val;
    int variant;
    int item;
    udt *q = udt_create(100);
    print_menu();
    while (scanf("%d", &variant)&& variant != 7) {
        switch(variant) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                udt_push(q, item);
                break;
            case 2:
                udt_pop(q);
                break;
            case 3:
                udt_print(q);
                break;
            case 4:
                printf("%d\n", udt_size(q));
                break;
            case 5:
                udt_shift_smaller(q);
                break;
            case 6:
                udt_insertion_sort(q);
                break;
        }
        print_menu();
    }
    printf("\n");
    while (!udt_is_empty(q)) {
        val = udt_get(q);
        printf("%d\n", val);
        udt_pop(q);
    }

    udt_destroy(q);

    return 0;
}
