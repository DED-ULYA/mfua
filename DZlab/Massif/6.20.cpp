#include <iostream>
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    int m, n;

    cout << "Введите размер массива A (m): ";
    cin >> m;
    cout << "Введите размер массива B (n, n > m): ";
    cin >> n;

    if (n <= m) {
        cout << "Ошибка: n должно быть больше m" << endl;
        return 1;
    }

    int A[100];
    int B[100];

    // Ввод массива A
    cout << "Введите " << m << " элементов массива A:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    // Ввод массива B
    cout << "Введите " << n << " элементов массива B:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
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
        cout << "Массив A найден в массиве B, начиная с индекса " << position << endl;
        cout << "(позиция " << position + 1 << " при нумерации с 1)" << endl;
    }
    else {
        cout << "Массив A не найден в массиве B" << endl;
    }

    return 0;
}
