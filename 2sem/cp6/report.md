# Отчет по лабораторной работе № 6
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Григорьев Тимофей Андреевич

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Инструментальные средства UNIX, алгоритмы и структуры данных.
2. **Цель работы**: Обработка последовательной файловой структуры на языке Си.
3. **Задание (вариант №29)**: 
Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си. Распечатать содержимое файла; выполнить над ним заданное действие и распечатать результат. 
Сведения о вступительных экзаменах абитуриентов: фамилия, инициалы, пол, номер школы, наличие медали, оценки в баллах и зачет/незачет по сочинению. 
Найти абитуриентов, получивших максимальную оценку по одному предмету, но не набравших проходного балла p
4. **Идея, метод, алгоритм решения задачи**:

Файл "print.c" содержит следующую функцию:

* `main(int argc, char *argv[]):`
- Проверяет количество переданных аргументов командной строки, если их количество не равно 2, выводит сообщение об использовании программы и завершает выполнение.
- Открывает файл с данными об участниках для чтения.
- Использует функцию `applicant_read_bin` для считывания информации об участнике из файла в структуру "Applicant".
- Затем вызывает функцию "applicant_print" для вывода информации об участнике в консоль.
- После завершения работы с файлом, закрывает его.

Файл "io.h" содержит объявления следующих функций:
1. `void applicant_read_bin(Applicant *a, FILE *in):`
- Функция считывает информацию об участнике из бинарного файла и записывает её в структуру "Applicant".
2. `void applicant_print(Applicant *a):`
- Функция выводит информацию об участнике в консоль.
3. `void applicants_write_bin(Applicant *a, FILE *out):`
- Функция записывает информацию об участнике в бинарный файл.

Файл "io.c" содержит реализацию вышеописанных функций для работы с данными об участниках.

Файл "generate.c" содержит следующую функцию:
1. `main(int argc, char *argv[]):`
- Проверяет количество переданных аргументов командной строки. Если их количество не равно 3, выводит сообщение об использовании программы и завершает выполнение.
- Открывает входной файл для чтения и выходной файл для записи в бинарном режиме.
- Если есть проблемы с открытием файлов, выводит соответствующие сообщения об ошибке.
- Создает структуру "Applicant".
- Считывает информацию об участнике из текстового файла с помощью функции `applicant_read_txt` и записывает ее в бинарный файл с помощью функции `applicant_write_bin`.
- После завершения работы с файлами, закрывает их.

Файл "execute.c" содержит следующие функции:
1. `float average(FILE *in):`
- Эта функция вычисляет среднее значение оценок по трем предметам (русский язык, математика, информатика) для участников, данные о которых считываются из бинарного файла.
- В цикле считывает данные об участниках с помощью функции `applicant_read_bin`.
- Подсчитывает сумму оценок и количество участников.
- Если данные в файле некорректны, выводит сообщение об ошибке и завершает выполнение программы.
- Возвращает среднее значение оценок.

2. `main(int argc, char *argv[]):`
- Эта функция является точкой входа в программу.
- Проверяет количество переданных аргументов командной строки. Если их количество не равно 2, выводит сообщение об использовании программы и завершает выполнение.
- Открывает файл с данными об участниках в бинарном режиме.
- Вычисляет среднюю оценку с помощью функции `average`.
- Затем считывает информацию об участниках и проверяет, у кого сумма оценок превышает среднюю и у кого нет медали, и выводит это в консоль.
- После завершения работы с файлом, закрывает его.
5. **Сценарий выполнения работы**:
Программа была разработана для обработки данных абитуриентов, хранящихся в файловой структуре. Изначально был составлен план разработки программы, включающий в себя определение структур данных, функций для работы с файлами, а также функций для выполнения операций над данными абитуриентов. Программа состоит из нескольких модулей, каждый из которых отвечает за определенный аспект работы с данными.
Программа была протестирована на различных наборах данных, включая корректные и некорректные значения, чтобы проверить её устойчивость к ошибкам и способность корректно обрабатывать исключительные ситуации.
6. **Протокол**: 
- [base_generator.c](base_generator.c)
- [generate.c](generate.c)
- [print.c](print.c)
- [execute.c](execute.c)
7. **Замечания автора** по существу работы: Работа была интересной и обучающей, так как позволила углубить знания в области работы с файлами в Си и усовершенствовать навыки программирования. Проблемы, связанные с управлением памятью и отладкой с использованием инструментов типа Valgrind, были значительной частью процесса разработки.
8. **Выводы**: В процессе выполнения работы я научился работать с файлами в Си, используя структуры и потоки ввода-вывода, применять инструменты для отладки и решения проблем с управлением памятью. Это опыт, который будет полезен в будущих проектах, особенно в разработке низкоуровневого программного обеспечения. Было интересно решать задачи по оптимизации кода и делать его более устойчивым к ошибкам. Также я улучшил свои навыки в написании чистого и понятного кода, что является важным аспектом в программировании.