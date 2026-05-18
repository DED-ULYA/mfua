#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    double X[100];      // исходный массив
    double result[100]; // массив для результата
    double sum = 0;     // накопленная сумма

    if (n <= 0 || n > 100) {
        cout << "Ошибка: размер массива должен быть от 1 до 100" << endl;
        return 1;
    }

    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    // Вычисляем сглаженные значения
    for (int i = 0; i < n; i++) {
        sum += X[i];                // добавляем текущий элемент к сумме
        result[i] = sum / (i + 1); // среднее арифметическое первых (i+1) элементов
    }

    cout << "Исходный массив X: ";
    for (int i = 0; i < n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;

    cout << "Сглаженный массив: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}