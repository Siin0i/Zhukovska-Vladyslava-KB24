#ifndef MODULES_ZHUKOVSKY_H
#define MODULES_ZHUKOVSKY_H

// Прототип функції
double s_calculation(double x, double y, double z);

#endif // MODULES_ZHUKOVSKY_H
#include "modules_Zhukovsky.h"
#include <iostream>
#include <cmath>
#include <cstdlib> // isnan()

using namespace std;

// Реалізація функції обчислення S
double s_calculation(double x, double y, double z) {
    double denominator = sin(z * y);
    if (denominator == 0) {
        cerr << "Помилка: ділення на нуль (sin(zy) = 0)" << endl;
        return NAN;
    }

    double term1 = 0.5 * (y * y + (2 * z) / sqrt(7 * M_PI) + x);
    double term2 = -sqrt(exp(fabs(x)));
    double term3 = sqrt(fabs(y - z)) / denominator;

    return term1 + term2 + term3;
}
#include <iostream>
#include <cmath>
#include <iomanip> // Для форматування виводу
#include "modules_Zhukovsky.h" // Підключення бібліотеки

using namespace std;

// Структура для тестових кейсів
struct TestCase {
    double x, y, z;   // Вхідні параметри
    double expected;  // Очікуваний результат (або NAN для перевірки помилок)
    string description;
};

// Функція тестування
void runTest(const TestCase& test) {
    double result = s_calculation(test.x, test.y, test.z);
    cout << fixed << setprecision(5);

    cout << "Тест: " << test.description << endl;
    cout << "Вхідні дані: x = " << test.x << ", y = " << test.y << ", z = " << test.z << endl;
    cout << "Очікуваний результат: " << (isnan(test.expected) ? "Помилка" : to_string(test.expected)) << endl;
    cout << "Отриманий результат: " << (isnan(result) ? "Помилка" : to_string(result)) << endl;

    if ((isnan(test.expected) && isnan(result)) || (!isnan(test.expected) && fabs(result - test.expected) < 0.0001)) {
        cout << "Статус: PASSED ✅\n" << endl;
    } else {
        cout << "Статус: FAILED ❌\n" << endl;
    }
}

int main() {
    // Набір тестових випадків
    TestCase tests[] = {
        {2.0, 3.0, 1.0, 5.12345, "Позитивні значення"},
        {-2.0, -3.0, -1.0, -3.45678, "Негативні значення"},
        {0.0, 0.0, 0.0, NAN, "Ділення на нуль (sin(zy) = 0)"},
        {1.0, 100000.0, 0.00001, NAN, "sin(zy) ≈ 0"},
        {1000.0, 2000.0, 500.0, 12345.6789, "Великі числа"},
        {0.0001, 0.0002, 0.0003, 0.00123, "Малі значення"},
        {5.0, 2.0, 2.0, 6.54321, "y = z (корінь з 0)"},
        {M_PI, 2.5, 1.5, 4.98765, "x = π"},
        {M_E, 1.2, 2.3, 3.87654, "x = e"},
        {1.0, -10.0, 10.0, 7.65432, "sqrt(від'ємне)"},
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);

    // Виконання всіх тестів
    for (int i = 0; i < numTests; i++) {
        runTest(tests[i]);
    }

    return 0;
}
