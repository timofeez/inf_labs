#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(float data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(Node* parent, float data) {
    if (!parent) return;
    Node* child = createNode(data);
    if (!parent->firstChild) {
        parent->firstChild = child;
    } else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

Node* findNode(Node* root, float data) {
    if (!root) return NULL;
    if (root->data == data) return root;
    Node* found = findNode(root->firstChild, data);
    if (found) return found;
    return findNode(root->nextSibling, data);
}

void addNode(Node** root, int* isRootSet) {
    float parentData, childData;
    printf("Введите родительский узел и значение нового узла (для корня введите 0.0 число): ");
    if (scanf("%f %f", &parentData, &childData) != 2) {
        printf("Некорректный ввод.\n");
        exit(1);
    }
    if (!*isRootSet) { // Сначала проверяем, был ли установлен корень
        *root = createNode(childData);
        *isRootSet = 1; // Устанавливаем флаг в 1, поскольку корень создан
    } else if (*isRootSet && parentData == 0) {
        // Если корень уже создан и родительский узел равен нулю, добавляем потомка к корню
        addChild(*root, childData);
    } else {
        // Иначе ищем родительский узел и добавляем к нему потомка
        Node* parent = findNode(*root, parentData);
        if (parent) {
            addChild(parent, childData);
        } else {
            printf("Родительский узел не найден.\n");
        }
    }
}

void printTree(Node* root, int level) {
    if (root == NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    if (root->data == (int)root->data) {
        // Если число целое, выводим без десятичной точки
        printf("%d\n", (int)root->data);
    } else {
        // Если число не целое, выводим с точкой и необходимым количеством знаков после запятой
        printf("%f\n", root->data);
    }
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

void deleteRoot(Node* root) {
    if (root == NULL) return;
    deleteRoot(root->firstChild);
    deleteRoot(root->nextSibling);
    free(root);
}

void print_menu() {
    printf("What do you want to do?\n");
    printf("1: Add a node\n");
    printf("2: Print a tree\n");
    printf("3: Get maximum NonTerminalDepth node value\n");
    printf("4: Delete the tree\n");
    printf("5: Exit\n");
    printf(">");
}

void getMaxNonTerminalDepth(Node* root, int level, int* maxDepth, float* maxDepthValue) {
    if (root == NULL) return;
    if (root->firstChild != NULL) {  // Проверка, является ли узел нетерминальным
        if (level > *maxDepth) {
            *maxDepth = level;
            *maxDepthValue = root->data;
        } else if (level == *maxDepth && root->data > *maxDepthValue) {
            // Если уровень совпадает с максимальным, но значение узла больше, обновляем значение
            *maxDepthValue = root->data;
        }
        Node* child = root->firstChild;
        while (child != NULL) {
            getMaxNonTerminalDepth(child, level + 1, maxDepth, maxDepthValue);
            child = child->nextSibling;
        }
    }
}

int main() {
    Node* root = NULL;
    int isRootSet = 0; // Используем int в качестве флага
    int variant;
    int maxDepth = -1; 
    float maxDepthValue = 0.0;
    print_menu();
    while (scanf("%d", &variant), variant != 5) {
        switch(variant) {
            case 1:
                addNode(&root, &isRootSet); // Передаем в функцию указатель на флаг
                break;
            case 2:
                printf("Tree:\n");
                printTree(root, 0);
                break;
            case 3:
                getMaxNonTerminalDepth(root, 0, &maxDepth, &maxDepthValue);
                if (maxDepth != -1) {
                    printf("Max non-terminal node depth is: %d with value: %f\n", maxDepth, maxDepthValue);
                } else {
                    printf("There are no non-terminal nodes in the tree.\n");
                }
                break;
            case 4:
                deleteRoot(root);
                root = NULL;
                isRootSet = 0; // Сбрасываем флаг после удаления корня
                printf("The tree has been deleted.\n");
                break;
        }
        print_menu();
    }
    printf("Работа программы окончена\n");
    deleteRoot(root); 
    return 0;
}