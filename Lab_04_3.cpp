#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    // Налаштування UTF-8 для консолі Windows
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double a, b, c;
    double xp, xk, dx;
    double F;

    // Введення початкових даних
    cout << "Введіть параметр a: "; cin >> a;
    cout << "Введіть параметр b: "; cin >> b;
    cout << "Введіть параметр c: "; cin >> c;
    cout << "Введіть X поч (xp): "; cin >> xp;
    cout << "Введіть X кін (xk): "; cin >> xk;
    cout << "Введіть крок dx: "; cin >> dx;

    // Шапка таблиці
    cout << fixed;
    cout << "\n-----------------------------------" << endl;
    cout << "|" << setw(10) << "x" << " |" << setw(18) << "F" << " |" << endl;
    cout << "-----------------------------------" << endl;

    double x = xp;

    // Цикл табуляції
    while (x <= xk + dx / 2.0)
    {
        bool error = false;

        if (a < 0 && c != 0)
        {
            F = a * x * x + b * x + c;
        }
        else if (a > 0 && c == 0)
        {
            if (x - b != 0)
            {
                F = -a / (x - b);
            }
            else
            {
                error = true;
            }
        }
        else
        {
            F = a * (x + c);
        }

        // Форматований вивід
        cout << "|" << setw(10) << setprecision(3) << x << " |";
        if (!error)
        {
            cout << setw(18) << setprecision(5) << F << " |" << endl;
        }
        else
        {
            cout << setw(18) << "не існує (÷0)" << " |" << endl;
        }

        x += dx;
    }

    cout << "-----------------------------------" << endl;

    return 0;
}