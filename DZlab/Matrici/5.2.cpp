#include <iostream>

using namespace std;

const int MAX_M = 100; // Максимальное количество строк
const int MAX_N = 100; // Максимальное количество столбцов

// Функция для заполнения матрицы по спирали
void Spiral(int matrix[MAX_M][MAX_N], int m, int n) {
    int top = 0, bottom = m - 1;      // Границы по строкам
    int left = 0, right = n - 1;      // Границы по столбцам
    int num = 1;                       // Текущее число для заполнения

    while (top <= bottom && left <= right) {
        //Заполняем верхнюю строку (слева направо)
        for (int j = left; j <= right; ++j) {
            matrix[top][j] = num++;
        }
        top++; //Верхняя граница опускается вниз

        //Заполняем правый столбец (сверху вниз)
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--; // Правая граница сдвигается влево

        //Заполняем нижнюю строку (справа налево)
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                matrix[bottom][j] = num++;
            }
            bottom--; //Нижняя граница поднимается вверх
        }

        //Заполняем левый столбец (снизу вверх)
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++; //Левая граница сдвигается вправо
        }
    }
}

//Функция для вывода матрицы
void printMatrix(int matrix[MAX_M][MAX_N], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%4d ", matrix[i][j]); //Выравнивание по 4 символа
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;
    int matrix[MAX_M][MAX_N]; //Статический двумерный массив

    cout << "Введите количество строк m (не более " << MAX_M << "): ";
    cin >> m;
    cout << "Введите количество столбцов n (не более " << MAX_N << "): ";
    cin >> n;

    if (m <= 0 || n <= 0 || m > MAX_M || n > MAX_N) {
        cout << "Неверные размеры матрицы!" << endl;
        return 1;
    }

    //Заполняем матрицу по спирали
    Spiral(matrix, m, n);

    //Выводим результат
    cout << "Матрица заполненная по спирали:" << endl;
    printMatrix(matrix, m, n);

    return 0;
}