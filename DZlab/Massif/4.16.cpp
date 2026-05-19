#include <iostream>
#include <cmath> // для abs() при работе с отрицательными числами

int main() {
    const int n = 10; // размер исходного массива (можно изменить или ввести с клавиатуры)
    int K[n]; // исходный массив
    int L[n]; // массив для четных элементов
    int M[n]; // массив для нечетных элементов
    int countL = 0; // счетчик четных
    int countM = 0; // счетчик нечетных

    // Ввод элементов массива K
    std::cout << "Введите " << n << " целых чисел:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> K[i];
    }

    // Разделение на четные и нечетные
    for (int i = 0; i < n; i++) {
        if (K[i] % 2 == 0) {
            L[countL] = K[i];
            countL++;
        } else {
            M[countM] = K[i];
            countM++;
        }
    }

    // Вывод результата
    std::cout << "\nИсходный массив K: ";
    for (int i = 0; i < n; i++) {
        std::cout << K[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Четные элементы (массив L): ";
    for (int i = 0; i < countL; i++) {
        std::cout << L[i] << " ";
    }
    std::cout << "\nКоличество четных элементов: " << countL << std::endl;

    std::cout << "Нечетные элементы (массив M): ";
    for (int i = 0; i < countM; i++) {
        std::cout << M[i] << " ";
    }
    std::cout << "\nКоличество нечетных элементов: " << countM << std::endl;

    return 0;
}