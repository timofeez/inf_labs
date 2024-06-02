#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node* left;
    struct Node* right;
} Node;

char* strdup(const char* s) {
    char* p = malloc(strlen(s) + 1); // Выделение памяти под строку + символ конца строки
    if (p != NULL) {
        strcpy(p, s); // Копируем содержимое s в p
    }
    return p;
}

void freeNode(Node* node) {
    if (node != NULL) {
        free(node->value);
        free(node);
    }
}

void freeTree(Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        freeNode(node);
    }
}

Node* createNode(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Расширяем проверку, чтобы позволить переменным и числам быть операндами
int isOperand(char ch) {
    return isdigit(ch) || isalpha(ch) || ch == '.';
}

void infixToPostfix(const char* infix, char* postfix) {
    char stack[100];
    int top = -1, k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isOperand(infix[i])) { // Проверяем, является ли символ операндом
            // Копируем операнд в postfix
            while (isOperand(infix[i]) && infix[i] != ' ') {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
            if (infix[i] == ' ') continue;
            i--; // Возвращаемся на шаг назад, если цикл прервался не из-за пробела
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
                postfix[k++] = ' ';
            }
            top--; // Удаление '(' из стека
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]) && stack[top] != '(') {
                postfix[k++] = stack[top--];
                postfix[k++] = ' ';
            }
            stack[++top] = infix[i];
        }
    }
    while (top != -1) {
        postfix[k++] = stack[top--];
        postfix[k++] = ' ';
    }
    postfix[k - 1] = '\0'; // Удаляем лишний пробел в конце и завершаем строку
}

Node* buildTreeFromPostfix(const char* postfix) {
    Node* stack[100];
    int top = -1;

    char* postfix_copy = strdup(postfix);
    char* token = strtok(postfix_copy, " ");

    while (token != NULL) {
        if (isOperator(token[0]) && (token[1] == '\0' || token[0] == '^')) {
            Node* node = createNode(token);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        } else {
            stack[++top] = createNode(token);
        }
        token = strtok(NULL, " ");
    }

    free(postfix_copy);

    return stack[top];
}

Node* simplifyTree(Node* node) {
    if (node == NULL) return NULL;

    // Рекурсивно упрощаем левое и правое поддеревья
    node->left = simplifyTree(node->left);
    node->right = simplifyTree(node->right);

    // Если узел является оператором деления и правый потомок равен 1,
    // заменяем данный узел на его левого потомка.
    if (node->value[0] == '/' && node->right && strcmp(node->right->value, "1") == 0) {
        Node* left = node->left;
        freeNode(node->right); // освобождаем узел, содержащий "1"
        free(node->value);     // освобождаем строку, содержащую оператор
        free(node);            // освобождаем сам узел
        return left;
    }

    return node;
}

void printInfix(Node* node) {
    if (node == NULL) return;
    if (node->left != NULL || node->right != NULL) printf("(");
    printInfix(node->left);
    printf("%s", node->value);
    printInfix(node->right);
    if (node->left != NULL || node->right != NULL) printf(")");
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Введите арифметическое выражение: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Удаление символа новой строки

    infixToPostfix(infix, postfix);

    Node* tree = buildTreeFromPostfix(postfix);
    Node* simplifiedTree = simplifyTree(tree);

    printf("Упрощенное выражение: ");
    printInfix(simplifiedTree);
    printf("\n");

    freeTree(simplifiedTree); // Освобождаем память дерева

    return 0;
}