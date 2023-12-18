#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 4
#define COLS 6

int main() {
    setlocale(LC_CTYPE, "ukr"); // українізація

    int matrix[ROWS][COLS];

    srand(time(NULL));
    // Заповнення матриці випадковими числами 0 або 1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    printf("Матриця:\n");
    // Виведення матриці на екран
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Стовпцi, що мiстять 2 чи бiльше 0: ");
    // Пошук стовпців, що містять два чи більше нулі
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
        // Виведення номерів стовпців, які мають 2 чи більше нулі
        if (count >= 2) {
            printf("%d ", j + 1);
        }
    }

    return 0;
}