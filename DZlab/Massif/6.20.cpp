#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    int m, n;

    std::cout << "Введите размер массива A (m): ";
    std::cin >> m;
    std::cout << "Введите размер массива B (n, n > m): ";
    std::cin >> n;

    if (n <= m) {
        std::cout << "Ошибка: n должно быть больше m" << std::endl;
        return 1;
    }

    int A[100];
    int B[100];

    // Ввод массива A
    std::cout << "Введите " << m << " элементов массива A:" << std::endl;
    for (int i = 0; i < m; i++) {
        std::cin >> A[i];
    }

    // Ввод массива B
    std::cout << "Введите " << n << " элементов массива B:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    int position = -1;  // позиция начала A в B (-1 означает не найдено)

    // Поиск подмассива A в B
    for (int i = 0; i <= n - m; i++) {
        bool found = true;

        // Сравниваем элементы A с элементами B начиная с позиции i
        for (int j = 0; j < m; j++) {
            if (A[j] != B[i + j]) {
                found = false;
                break;
            }
        }

        if (found) {
            position = i;
            break;  // находим первое вхождение
        }
    }

    // Вывод результата
    if (position != -1) {
        std::cout << "Массив A найден в массиве B, начиная с индекса " << position << std::endl;
        std::cout << "(позиция " << position + 1 << " при нумерации с 1)" << std::endl;
    }
    else {
        std::cout << "Массив A не найден в массиве B" << std::endl;
    }

    return 0;
}
