#!/bin/bash

# Использование: ./custom_split.sh <имя_файла> <строк_в_файле> <префикс_результата>

FILENAME=$1
LINES_PER_FILE=$2
PREFIX=$3

# Проверяем аргументы командной строки
if [[ -z "$FILENAME" || -z "$LINES_PER_FILE" ]]; then
    echo "Usage: $0 <file_to_split> <lines_per_file> [output_file_prefix]"
    exit 1
fi

# Проверяем, существует ли файл
if [[ ! -f "$FILENAME" ]]; then
    echo "Error: File '$FILENAME' not found!"
    exit 1
fi

# Если префикс не задан, используем 'x'
if [[ -z "$PREFIX" ]]; then
    PREFIX='x'
fi

# Функция для генерации следующего суффикса файла
next_suffix() {
    echo $(printf "%02d" $1 | tr '0-9' 'a-z')
}

# Счетчик для именования новых файлов
COUNTER=0

# Счетчик строк в текущем файле
LINE_COUNT=0

# Чтение файла построчно
while IFS= read -r line; do
    # Генерация суффикса на основе счетчика
    SUFFIX=$(next_suffix $COUNTER)
    
    # Имя нового файла с добавленным суффиксом и префиксом
    OUTPUT_FILE="${PREFIX}${SUFFIX}"
    
    # Запись строки в текущий файл
    echo "$line" >> "$OUTPUT_FILE"
    
    # Обновление счетчика строк
    ((LINE_COUNT++))
    
    # Если достигнуто указанное количество строк, сбросить счетчик и увеличить счетчик файлов
    if [ "$LINE_COUNT" -eq "$LINES_PER_FILE" ]; then
        LINE_COUNT=0
        ((COUNTER++))
    fi
done < "$FILENAME"

echo "File '$FILENAME' has been split into multiple files with prefix '$PREFIX'"