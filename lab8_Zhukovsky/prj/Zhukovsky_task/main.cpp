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
        cerr << "�������: ������ �� ���� (sin(zy) = 0)" << endl;
        return NAN;
    }
    double term1 = 0.5 * (y * y + (2 * z) / sqrt(7 * M_PI) + x);
    double term2 = -sqrt(exp(fabs(x)));
    double term3 = sqrt(fabs(y - z)) / denominator;
    return term1 + term2 + term3;
}

void printDeveloperInfo(ofstream &file) {
    file << "� �������� ��������: ������� ��'�" << endl;
}

string evaluateLogic(char a, char b) {
    if (!isalpha(a) || !isalpha(b)) return "�������: ��������� �������!";
    return (a + 5 > b + 2) ? "true" : "false";
}

void printNumbers(ofstream &file, double x, double y, double z) {
    file << "��������� �������: x = " << x << ", y = " << y << ", z = " << z << endl;
    file << hex << showbase;
    file << "س������������ �������: x = " << (int)x << ", y = " << (int)y << ", z = " << (int)z << endl;
    file << dec;
}

void calculateAndPrintS(ofstream &file, double x, double y, double z) {
    double S = s_calculation(x, y, z);
    if (isnan(S)) {
        file << "������� � ����������� S!" << endl;
    } else {
        file << "��������� �������� S: " << S << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001); // ������������ UTF-8 ��� ������
    ofstream file("output.txt", ios::out);

    double x, y, z;
    char a, b;

    cout << "������ ����� x: ";
    cin >> x;
    cout << "������ ����� y: ";
    cin >> y;
    cout << "������ ����� z: ";
    cin >> z;
    cout << "������ ������ a: ";
    cin >> a;
    cout << "������ ������ b: ";
    cin >> b;

    printDeveloperInfo(file);
    file << "��������� �������� ������: " << evaluateLogic(a, b) << endl;
    printNumbers(file, x, y, z);
    calculateAndPrintS(file, x, y, z);

    file.close();
    cout << "��������� ��������� � output.txt" << endl;

    return 0;
}
