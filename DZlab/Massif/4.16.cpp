#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    double X[100];      // исходный массив
    double result[100]; // массив для результата
    double sum = 0;     // накопленная сумма

    if (n <= 0 || n > 100) {
        std::cout << "Ошибка: размер массива должен быть от 1 до 100" << std::endl;
        return 1;
    }

    std::cout << "Введите " << n << " чисел:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> X[i];
    }

    // Вычисляем сглаженные значения
    for (int i = 0; i < n; i++) {
        sum += X[i];                // добавляем текущий элемент к сумме
        result[i] = sum / (i + 1); // среднее арифметическое первых (i+1) элементов
    }

    std::cout << "Исходный массив X: ";
    for (int i = 0; i < n; i++) {
        std::cout << X[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Сглаженный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}