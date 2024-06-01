#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "applicant.h"
#include "io.c"

void find_top_applicants(FILE *in, int passing_score) {
    int max_rus = 0, max_math = 0, max_inf = 0;
    Applicant a;

    // Поиск максимальных оценок по каждому предмету
    while(applicant_read_bin(&a, in)) {
        if (a.rus > max_rus) max_rus = a.rus;
        if (a.math > max_math) max_math = a.math;
        if (a.inf > max_inf) max_inf = a.inf;
    }

    rewind(in);

    // Вывод абитуриентов, имеющих максимальные оценки по предметам, но не набравших проходной балл
    while(applicant_read_bin(&a, in)) {
        int total_score = a.rus + a.math + a.inf;
        if (total_score < passing_score && (a.rus == max_rus || a.math == max_math || a.inf == max_inf)) {
            printf("Applicant: %s %s, School: %d, Russian: %d, Math: %d, Informatics: %d\n",
                   a.name, a.initials, a.school, a.rus, a.math, a.inf);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage:\n\t./execute DB_FILE PASSING_SCORE\n");
        exit(0);
    }

    int passing_score = atoi(argv[2]);

    FILE *in = fopen(argv[1], "rb");
    if (!in) {
        printf("I/O Error: can't open file.\n");
        exit(1);
    }
    
    find_top_applicants(in, passing_score);
    
    fclose(in);
    
    return 0;
}