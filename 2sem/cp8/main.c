#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    size_t data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} CircularLinkedList;

typedef struct {
    Node* current;
} Iterator;

// Освобождение всей памяти, выделенной под список
void deallocateList(CircularLinkedList* list) {
    while (list->size > 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
    list->head = NULL;
    list->tail = NULL;
}

// Инициализация пустого списка
void initList(CircularLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Переход к следующему элементу итератора
int moveNext(Iterator* iter) {
    if (iter->current != NULL) {
        iter->current = iter->current->next;
        return iter->current != NULL;
    }
    return 0;
}

// Инициализация итератора
void initIterator(Iterator* iter, const CircularLinkedList* list) {
    iter->current = list->head;
}

// Получение данных текущего элемента итератора
size_t GetCurrentData(const Iterator* iter) {
    if (iter->current != NULL) {
        return iter->current->data;
    }
    return 0;
}

// Печать списка
void printList(const CircularLinkedList* list) {
    if (list->size == 0) {
        printf("Список пуст\n");
        return;
    }
    Iterator iter;
    initIterator(&iter, list);
    int isFirstIteration = 1;
    do {
        printf("%zu ", GetCurrentData(&iter));
        isFirstIteration = 0;
    } while (moveNext(&iter) && (iter.current != list->head || isFirstIteration));
    printf("\n");
}

// Вставка элемента в конец списка
void insertEnd(CircularLinkedList* list, size_t data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    if (list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
    } else {
        list->tail->next = newNode;
        newNode->next = list->head;
        list->tail = newNode;
    }
    list->size++;
}

// Удаление элемента из списка по значению
void deleteNode(CircularLinkedList* list, size_t data) {
    if (list->size == 0) {
        printf("Список пуст, невозможно удалить элемент\n");
        return;
    }
    Iterator iter;
    initIterator(&iter, list);
    Node* prev = list->tail;
    do {
        if (GetCurrentData(&iter) == data) {
            Node* current = iter.current;
            if (current == list->head) {
                list->head = current->next;
                list->tail->next = list->head;
                if (list->head == current) { // Список стал пустым
                    list->head = NULL;
                    list->tail = NULL;
                }
            } else {
                prev->next = current->next;
                if (current == list->tail) {
                    list->tail = prev;
                }
            }
            free(current);
            list->size--;
            printf("Элемент %zu удален из списка\n", data);
            return;
        }
        prev = iter.current;
    } while (moveNext(&iter) && iter.current != list->head);
    printf("Элемент %zu не найден в списке\n", data);
}

// Подсчет длины списка
size_t length(const CircularLinkedList* list) {
    return list->size;
}

void swapSecondAndPenultimate(CircularLinkedList* list) {
    if (list->size < 2) {
        printf("Недостаточно элементов для обмена.\n");
        return;
    }
    
    // Если всего два элемента, то они и будут вторым и предпоследним
    if (list->size == 2) {
        // Просто обменяем данные головы и хвоста списка
        size_t temp = list->head->data;
        list->head->data = list->tail->data;
        list->tail->data = temp;
        return;
    }

    Node* second = list->head->next;
    Node* penultimate = list->head;

    // Перемещаемся к предпоследнему элементу
    while (penultimate->next != list->tail) {
        penultimate = penultimate->next;
    }

    // Обмен данными между вторым и предпоследним элементом
    size_t temp = second->data;
    second->data = penultimate->data;
    penultimate->data = temp;

    printf("Элементы обменяны.\n");
}


void print_menu() {
    printf("What do you want to do?\n");
    printf("1: Print a list\n");
    printf("2: Insert End\n");
    printf("3: Get length\n");
    printf("4: Delete node\n");
    printf("5: Swap second and penultimate\n");
    printf("6: Exit\n");
    printf("> ");
}

int main() {
    CircularLinkedList list;
    initList(&list);
    int variant;
    size_t number;
    print_menu();
    while (scanf("%d", &variant) == 1 && variant != 6) {
        switch(variant) {
            case 1:
                printList(&list);
                break;
            case 2:
                printf("Enter a number to insert at the end: ");
                if (scanf("%zu", &number) == 1) {
                    insertEnd(&list, number);
                }
                break;
            case 3:
                printf("Length of the list: %zu\n", length(&list));
                break;
            case 4:
                printf("Enter a number to delete: ");
                if (scanf("%zu", &number) == 1) {
                    deleteNode(&list, number);
                }
                break;         
            case 5:
                swapSecondAndPenultimate(&list);
                break;
        }
        print_menu();
    }
    deallocateList(&list);
    return 0;
}