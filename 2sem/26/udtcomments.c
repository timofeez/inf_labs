#include "udt.h"
#include <stdlib.h>
#include <stdio.h>

// Создание новой очереди с заданной вместимостью
udt* udt_create(int capacity) {
	// Выделение памяти под структуру очереди
	udt* queue = (udt*)malloc(sizeof(udt));
	// Установка вместимости очереди
	queue->capacity = capacity;
	// Инициализация начала, размера и конца очереди
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	// Выделение памяти под данные очереди
	queue->data = (int*)malloc(queue->capacity * sizeof(int));
	// Возвращение указателя на созданную очередь
	return queue;
}

// Проверка, пуста ли очередь
bool udt_is_empty(const udt *queue) {
	// Если размер очереди равен 0, то она пуста
	return (queue->size == 0);
}

// Добавление элемента в очередь
void udt_push(udt *queue, int item) {
	// Если очередь полная, то выходим из функции
	if (queue->size == queue->capacity) return;
	// Перемещаем указатель на конец очереди
	queue->rear = (queue->rear + 1)%queue->capacity;
	// Добавляем элемент в конец очереди
	queue->data[queue->rear] = item;
	// Увеличиваем размер очереди
	queue->size = queue->size + 1;
}

// Удаление элемента из очереди
void udt_pop(udt *queue) {
	// Если очередь пуста, то выходим из функции
	if (udt_is_empty(queue)) return;
	// Перемещаем указатель на начало очереди
	queue->front = (queue->front + 1)%queue->capacity;
	// Уменьшаем размер очереди
	queue->size = queue->size - 1;
}

// Получение первого элемента очереди
int udt_get(const udt* queue) {
	// Возвращаем элемент, на который указывает front
	return queue->data[queue->front];
}

// Вывод очереди на экран
void udt_print(const udt* queue) {
	int i;
	// Проходим по всем элементам очереди
	for (i = 0; i < queue->size; i++) {
		// Выводим текущий элемент на экран
		printf("%d ", queue->data[i]);
	}
	// Переходим на новую строку
	printf("\n");
}

// Получение размера очереди
int udt_size(const udt *queue) {
	// Возвращаем размер очереди
	return queue->size;
}

// Уничтожение очереди
void udt_destroy(udt* queue) {
	// Освобождаем память, выделенную под данные очереди
    free(queue->data);
	// Освобождаем память, выделенную под структуру очереди
    free(queue);
}

// Перемещение меньшего элемента в начало очереди
void udt_shift_smaller(udt *queue) {
	// Если очередь пуста или в ней один элемент, то выходим из функции
    if (udt_is_empty(queue) || queue->size == 1) return;

    int i, j;
	// Проходим по всем элементам очереди
    for (i = 1; i < queue->size; i++) {
		// Если текущий элемент меньше предыдущего
        if (queue->data[i] < queue->data[i-1]) {
			// Запоминаем текущий элемент
            int temp = queue->data[i];
			// Перемещаем все элементы, большие текущего, вправо
            for (j = i; j > 0 && queue->data[j-1] > temp; j--) {
                queue->data[j] = queue->data[j-1];
            }
			// Вставляем текущий элемент на его место
            queue->data[j] = temp;
			// Выходим из цикла после первого перемещения
			break;
        }
    }
}

// Сортировка очереди методом вставок
void udt_insertion_sort(udt *queue) {
	// Получаем размер очереди
    int size = udt_size(queue);
	// Проходим по всем элементам очереди
    for (int i = 0; i < size; i++) {
		// Вызываем функцию перемещения меньшего элемента
        udt_shift_smaller(queue);
    }
}