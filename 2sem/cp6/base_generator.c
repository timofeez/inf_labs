#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "applicant.h"

int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char* random_string(char *str, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size; // Leave space for the null terminator
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int)(sizeof(charset) - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

void write_applicant(FILE *file, Applicant *applicant) {
    fwrite(applicant, sizeof(Applicant), 1, file);
}

Applicant generate_applicant() {
    Applicant applicant;
    memset(&applicant, 0, sizeof(applicant)); // Инициализация всей структуры нулями

    random_string(applicant.name, STR_SIZE - 1);
    random_string(applicant.initials, STR_SIZE - 1);
    // Убедитесь, что поле gender достаточно велико для нулевого терминатора
    strcpy(applicant.gender, random_range(0, 1) ? "M" : "F");
    applicant.school = random_range(1, 100);
    // Убедитесь, что поле medal достаточно велико для нулевого терминатора
    strcpy(applicant.medal, random_range(0, 1) ? "yes" : "no");
    applicant.rus = random_range(1, 100);
    applicant.math = random_range(1, 100);
    applicant.inf = random_range(1, 100);
    random_string(applicant.essay, STR_SIZE - 1);

    return applicant;
}

int main() {
    srand(time(NULL));
    FILE *out = fopen("applicants.bin", "wb");
    if (!out) {
        printf("Ошибка при открытии файла для записи.\n");
        return 1;
    }

    int num_applicants = random_range(10, 40);
    for (int i = 0; i < num_applicants; i++) {
        Applicant applicant = generate_applicant();
        write_applicant(out, &applicant);
    }

    fclose(out);
    printf("Файл успешно создан с %d абитуриентами.\n", num_applicants);
    return 0;
}