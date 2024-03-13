#!/bin/bash

string=$1
delimiter=$2
array=()

# Если первый аргумент - это файл, считываем его содержимое
if [[ -f $string ]]; then
    string=$(<"$string")
fi

# Заменяем все вхождения разделителя на символ новой строки
string=$(echo "$string" | sed "s/$delimiter/\n/g")

# Читаем строку в массив
while read -r line; do
    array+=("$line")
done <<< "$string"

# Выводим элементы массива
echo "${array[@]}"

