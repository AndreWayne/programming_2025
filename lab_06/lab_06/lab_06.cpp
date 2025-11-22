#include <iostream>
#include <cstdlib>
#include <locale.h>

// Функция для поиска столбцов с нулевыми значениями
int* findZeroColumns(int** matrix, int rows, int cols, int& zeroCount) {
    zeroCount = 0;

    // Сначала подсчитаем количество столбцов с нулями
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
                break; // Переходим к следующему столбцу
            }
        }
    }

    if (zeroCount == 0) return nullptr;

    // Создаем массив для индексов столбцов с нулями
    int* zeroColumns = (int*)malloc(zeroCount * sizeof(int));
    if (zeroColumns == nullptr) return nullptr;

    // Заполняем массив индексами столбцов с нулями
    int index = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                zeroColumns[index++] = j;
                break; // Переходим к следующему столбцу
            }
        }
    }

    return zeroColumns;
}

// Функция для удаления столбцов из матрицы
int** removeColumns(int** matrix, int rows, int& cols, int* columnsToRemove, int removeCount) {
    if (removeCount == 0 || columnsToRemove == nullptr) return matrix;

    // Создаем новую матрицу с уменьшенным количеством столбцов
    int newCols = cols - removeCount;
    int** newMatrix = (int**)malloc(rows * sizeof(int*));
    if (newMatrix == nullptr) return nullptr;

    for (int i = 0; i < rows; i++) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
        if (newMatrix[i] == nullptr) {
            // Освобождаем ранее выделенную память в случае ошибки
            for (int k = 0; k < i; k++) free(newMatrix[k]);
            free(newMatrix);
            return nullptr;
        }
    }

    // Копируем данные, пропуская удаляемые столбцы
    for (int i = 0; i < rows; i++) {
        int newColIndex = 0;
        for (int j = 0; j < cols; j++) {
            bool shouldRemove = false;
            for (int k = 0; k < removeCount; k++) {
                if (j == columnsToRemove[k]) {
                    shouldRemove = true;
                    break;
                }
            }
            if (!shouldRemove) {
                newMatrix[i][newColIndex++] = matrix[i][j];
            }
        }
    }

    // Освобождаем старую матрицу
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);

    cols = newCols;
    return newMatrix;
}

// Функция для вывода матрицы
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем исходную матрицу 2x2
    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)malloc(2 * sizeof(int));
    }

    // Ввод данных для исходной матрицы
    std::cout << "Введите элементы матрицы 2x2:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Ввод A и B с проверкой на отрицательные значения
    int A, B;

    do {
        std::cout << "Введите A (количество строк для добавления снизу): ";
        std::cin >> A;
        if (A < 0) std::cout << "Ошибка: A не может быть отрицательным. Попробуйте снова." << std::endl;
    } while (A < 0);

    do {
        std::cout << "Введите B (количество столбцов для добавления справа): ";
        std::cin >> B;
        if (B < 0) std::cout << "Ошибка: B не может быть отрицательным. Попробуйте снова." << std::endl;
    } while (B < 0);

    // Получаем коэффициенты C и D из исходной матрицы
    int C = matrix[1][0]; // C находится в [1][0]
    int D = matrix[1][1]; // D находится в [1][1]

    // Создаем расширенную матрицу
    int newRows = 2 + A;
    int newCols = 2 + B;

    int** extendedMatrix = (int**)malloc(newRows * sizeof(int*));
    for (int i = 0; i < newRows; i++) {
        extendedMatrix[i] = (int*)malloc(newCols * sizeof(int));
    }

    // Заполняем расширенную матрицу по заданному шаблону
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            if (i < 2 && j < 2) {
                // Копируем исходную матрицу
                extendedMatrix[i][j] = matrix[i][j];
            }
            else if (j >= 2) {
                // Новые столбцы справа
                extendedMatrix[i][j] = (i - 1) * C + (j - 1) * D;
            }
            else {
                // Новые строки снизу
                extendedMatrix[i][j] = (i - 1) * C + (j - 1) * D;
            }
        }
    }

    std::cout << "\nРасширенная матрица:" << std::endl;
    printMatrix(extendedMatrix, newRows, newCols);

    // Находим столбцы с нулевыми значениями
    int zeroCount;
    int* zeroColumns = findZeroColumns(extendedMatrix, newRows, newCols, zeroCount);

    if (zeroCount > 0) {
        std::cout << "\nСтолбцы с нулевыми значениями: ";
        for (int i = 0; i < zeroCount; i++) {
            std::cout << zeroColumns[i] << " ";
        }
        std::cout << std::endl;

        // Удаляем столбцы с нулями
        int** finalMatrix = removeColumns(extendedMatrix, newRows, newCols, zeroColumns, zeroCount);

        std::cout << "\nФинальная матрица после удаления столбцов с нулями:" << std::endl;
        printMatrix(finalMatrix, newRows, newCols);

        // Освобождаем память финальной матрицы
        for (int i = 0; i < newRows; i++) free(finalMatrix[i]);
        free(finalMatrix);
    }
    else {
        std::cout << "\nНет столбцов с нулевыми значениями. Матрица остается без изменений." << std::endl;
        // Освобождаем память расширенной матрицы
        for (int i = 0; i < newRows; i++) free(extendedMatrix[i]);
        free(extendedMatrix);
    }

    // Освобождаем память
    for (int i = 0; i < 2; i++) free(matrix[i]);
    free(matrix);
    if (zeroColumns != nullptr) free(zeroColumns);

    return 0;









    // Ввод значений переменных
    double a, b;

    std::cout << "Введите значение переменной a: ";
    std::cin >> a;

    std::cout << "Введите значение переменной b: ";
    std::cin >> b;

    // Вывод исходных значений
    std::cout << "\nИсходные значения:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    // Создание указателей с использованием new
    double* ptrA = new double;
    double* ptrB = new double;

    // Направляем указатели на переменные (копируем значения)
    *ptrA = a;
    *ptrB = b;

    // Увеличиваем значение переменной a в 3 раза через указатель
    *ptrA *= 3;

    // Вывод после увеличения
    std::cout << "\nПосле увеличения a в 3 раза:" << std::endl;
    std::cout << "a = " << *ptrA << std::endl;
    std::cout << "b = " << *ptrB << std::endl;

    // Меняем местами значения переменных через указатели
    double temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    // Вывод после обмена
    std::cout << "\nПосле обмена значений:" << std::endl;
    std::cout << "a = " << *ptrA << std::endl;
    std::cout << "b = " << *ptrB << std::endl;

    // Обновляем исходные переменные
    a = *ptrA;
    b = *ptrB;

    // Вывод финальных значений исходных переменных
    std::cout << "\nФинальные значения исходных переменных:" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    // Освобождаем память
    delete ptrA;
    delete ptrB;

    return 0;
}

