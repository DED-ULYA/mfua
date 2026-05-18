#include <iostream>

using namespace std;

const int MAX_N = 100; // Максимальный порядок квадрата

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите порядок латинского квадрата n: ";
    cin >> n;

    if (n <= 0 || n > MAX_N) {
        cout << "Неверный порядок!" << endl;
        return 1;
    }

    int square[MAX_N][MAX_N];

    // Заполняем первую строку
    for (int j = 0; j < n; ++j) {
        square[0][j] = j + 1;
    }

    // Заполняем остальные строки циклическим сдвигом
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            square[i][j] = square[i - 1][(j + 1) % n];
        }
    }

    // Выводим результат
    cout << "Латинский квадрат порядка " << n << ":" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << square[i][j];
        }
        cout << endl;
    }

    return 0;
}
