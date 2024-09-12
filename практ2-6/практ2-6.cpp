#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// Функція для обчислення відстані між двома точками
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Функція для виведення числа у зворотному порядку
void printReversed(double number) {
    // Приведемо число до формату з фіксованою кількістю знаків після коми
    cout << fixed << setprecision(2);

    // Перетворимо число в рядок
    string str = to_string(number);

    // Видалимо непотрібні нулі в кінці
    size_t dotPos = str.find('.');
    if (dotPos != string::npos) {
        // Видалимо зайві нулі після десяткової крапки
        str.erase(str.find_last_not_of('0') + 1, string::npos);
        // Видалимо десяткову крапку, якщо вона залишилася
        if (str.back() == '.') {
            str.pop_back();
        }
    }

    // Виведемо число у зворотному порядку
    for (int i = str.size() - 1; i >= 0; --i) {
        cout << str[i];
    }
    cout << endl;
}

int main() {
    double x1, y1, x2, y2, x3, y3;

    // Введення координат вершин трикутника
    cout << "Enter coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Enter coordinates of the third point (x3 y3): ";
    cin >> x3 >> y3;

    // Обчислення довжин сторін
    double d1 = distance(x1, y1, x2, y2);
    double d2 = distance(x2, y2, x3, y3);
    double d3 = distance(x3, y3, x1, y1);

    // Виведення довжин сторін у зворотному порядку
    cout << "Lengths of the sides in reverse order:" << endl;
    printReversed(d3);
    printReversed(d2);
    printReversed(d1);

    return 0;
}
