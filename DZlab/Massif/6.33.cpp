#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int arr[1000];
    cout << "Введите неотрицательные чисела:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Вычисляем общую сумму всех элементов
    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    long long leftSum = 0;      // сумма элементов до текущего
    int bestIndex = 0;
    long long minDiff = llabs(totalSum - arr[0]); // для индекса 0 (слева 0)

    for (int i = 0; i < n; i++) {
        // leftSum уже содержит сумму arr[0]..arr[i-1]
        long long rightSum = totalSum - leftSum - arr[i];
        long long diff = llabs(leftSum - rightSum);

        if (diff < minDiff) {
            minDiff = diff;
            bestIndex = i;
        }

        // Обновляем leftSum для следующего элемента
        leftSum += arr[i];
    }

    cout << "Индекс элемента: " << bestIndex << endl;
    cout << "Значение элемента: " << arr[bestIndex] << endl;

    // Повторно вычисляем суммы для вывода
    leftSum = 0;
    for (int i = 0; i < bestIndex; i++) {
        leftSum += arr[i];
    }
    long long rightSum = totalSum - leftSum - arr[bestIndex];

    cout << "Сумма слева: " << leftSum << endl;
    cout << "Сумма справа: " << rightSum << endl;
    cout << "Разница: " << minDiff << endl;

    return 0;
}