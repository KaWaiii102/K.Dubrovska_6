#include <iostream>
#include <cmath>

const int MAX_SIZE = 100;

// Функція для знаходження номеру мінімального елемента в масиві
int findMinIndex(const double array[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    double array[MAX_SIZE];
    int size;

    // Введення розміру масиву
    std::cout << "Введіть розмір масиву (не більше " << MAX_SIZE << "): ";
    std::cin >> size;

    // Введення елементів масиву
    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Елемент " << i + 1 << ": ";
        std::cin >> array[i];
    }

    // Знаходження номеру мінімального елемента та виведення його
    int minIndex = findMinIndex(array, size);
    std::cout << "Номер мінімального елемента: " << minIndex + 1 << "\n";

    // Знаходження першого та другого від'ємного елемента
    int firstNegativeIndex = -1;
    int secondNegativeIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            else {
                secondNegativeIndex = i;
                break;
            }
        }
    }

    // Обчислення суми елементів масиву між першим і другим від’ємними елементами
    double sumBetweenNegatives = 0.0;
    if (firstNegativeIndex != -1 && secondNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < secondNegativeIndex; ++i) {
            sumBetweenNegatives += array[i];
        }
    }

    std::cout << "Сума елементів між першим і другим від’ємними: " << sumBetweenNegatives << "\n";

    // Перетворення масиву
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (std::abs(array[j]) > 1.0 && std::abs(array[j + 1]) <= 1.0) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }

    // Виведення перетвореного масиву
    std::cout << "Перетворений масив:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}
