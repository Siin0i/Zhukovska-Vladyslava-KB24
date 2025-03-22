#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>
#include <windows.h>

using namespace std;

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

void printDeveloperInfo(ofstream &file) {
    file << "© Програму розробив: Прізвище Ім'я" << endl;
}

string evaluateLogic(char a, char b) {
    if (!isalpha(a) || !isalpha(b)) return "Помилка: некоректні символи!";
    return (a + 5 > b + 2) ? "true" : "false";
}

void printNumbers(ofstream &file, double x, double y, double z) {
    file << "Десяткова система: x = " << x << ", y = " << y << ", z = " << z << endl;
    file << hex << showbase;
    file << "Шістнадцяткова система: x = " << (int)x << ", y = " << (int)y << ", z = " << (int)z << endl;
    file << dec;
}

void calculateAndPrintS(ofstream &file, double x, double y, double z) {
    double S = s_calculation(x, y, z);
    if (isnan(S)) {
        file << "Помилка в обчисленнях S!" << endl;
    } else {
        file << "Обчислене значення S: " << S << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001); // Установлюємо UTF-8 для консолі
    ofstream file("output.txt", ios::out);

    double x, y, z;
    char a, b;

    cout << "Введіть число x: ";
    cin >> x;
    cout << "Введіть число y: ";
    cin >> y;
    cout << "Введіть число z: ";
    cin >> z;
    cout << "Введіть символ a: ";
    cin >> a;
    cout << "Введіть символ b: ";
    cin >> b;

    printDeveloperInfo(file);
    file << "Результат логічного виразу: " << evaluateLogic(a, b) << endl;
    printNumbers(file, x, y, z);
    calculateAndPrintS(file, x, y, z);

    file.close();
    cout << "Результат збережено в output.txt" << endl;

    return 0;
}
